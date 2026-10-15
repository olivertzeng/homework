#ifndef qE_P_H
#define qE_P_H
#include <setjmp.h>
#include <stdint.h>

typedef uint32_t qEw;
typedef uint64_t qEW;

#define qE_NB   30
#define qE_MAXP 64
#define qE_MAXF 12
#define qE_NTT  32
#define qE_BMN  8
#define qE_SEQ  6
#define qEHI(x) ((qEw)((x)>>32))
#define qELO(x) ((qEw)((x)&0xFFFFFFFFull))
#define qELOWBIT(x) ((x)&(~(x)+1u))
#define qEADDP(a,b,p) ((a)+(b)>=(p)?(a)+(b)-(p):(a)+(b))
#define qESUBP(a,b,p) ((a)>=(b)?(a)-(b):(a)+(p)-(b))

#define qEPT_BEGIN(c) switch(c) { case 0:
#define qEPT_YIELD(c,v) do{ (c)=__LINE__; RET (v); case __LINE__:; }while(0)
#define qEPT_END(c) } (c)=-1;

#define qE_OPS(X) X(GEN,0x9C) X(SVK,0x31) X(TPZ,0xE5) X(CNT,0x4A) X(PRG,0x7F) X(JMP,0x12) X(OPQ,0x66) X(HLT,0xD8)
#define qEX_ENUM(nm,v) GLUE2(qEOP_,nm)=(v),
enum qEop_e { qE_OPS(qEX_ENUM) qEOP_NIL_=0 };
#undef qEX_ENUM
#define qEMSK(pc) ((0xA7u+0x3Du*(unsigned)(pc))&0xFFu)
#define qEENC(op,pc) ((unsigned char)(((unsigned)(op))^qEMSK(pc)))
#define qEDECB(pr,pc) ((int)(((unsigned)(pr)[(pc)])^qEMSK(pc)))

static const unsigned char qEprog[]={
 qEENC(qEOP_OPQ,0),qEENC(9,1),
 qEENC(qEOP_GEN,2),qEENC(qEOP_SVK,3),qEENC(qEOP_TPZ,4),qEENC(qEOP_CNT,5),qEENC(qEOP_PRG,6),
 qEENC(qEOP_JMP,7),qEENC(0,8),
 qEENC(qEOP_CNT,9),qEENC(qEOP_TPZ,10),qEENC(qEOP_HLT,11)
};

typedef struct qElm_s { qEW c; qEw d; } qElmT;
typedef struct qEgm_s { qEW m; int s; qEw d; } qEgmT;
typedef struct qEbr_s { qEW mu; qEw d; } qEbrT;
typedef struct qEmo_s { qEw p,ni,r2,one; } qEmoT;
typedef struct qEbn_s { int n; qEw d[qE_NTT]; } qEbnT;

typedef struct qEkit_s {
 qElmT L10,L25,L26,L200,Lr[qE_MAXF+1];
 qEgmT G13,G26;
 qEbrT Br,Bf0,Bf1;
 qEmoT Mo;
 qEw g,c1M,c2M,inv13,e2,e13,h96,crc,P,B;
 qEw fk[4],fct[qE_MAXF+1],tab[256];
 int n,n0,R,L;
} qEkitT;

typedef struct qEco_s { int lc; qEw rk,x,y,Ecur,Eprev; int tri[3],dg[6]; } qEcoT;
typedef struct qEvm_s { int pc,op; } qEvmT;

/* hi64(c*a), 64x32 via two 32x32 limbs */
static qEW qEmh(qEW c,qEw a)
BEGIN
qEW lo,hi,*const Olo=&lo,*const Ohi=&hi,*const*const OOhi=&Ohi;
*Olo=(qEW)qELO(c)*(qEW)a;
**OOhi=(qEW)qEHI(c)*(qEW)a;
RET (*Ohi+(**&Olo>>32))>>32;
END

/* Lemire-Kaser-Kurz: c=ceil(2^64/d), d>=2, a<2^32 */
static qElmT qElmMk(qEw d)
BEGIN
qElmT L,*const OL=&L,*const*const OOL=&OL;
(**OOL).d=d;
(*OL).c=0xFFFFFFFFFFFFFFFFull/(qEW)d+1ull;
RET L;
END
static qEw qElmMod(qEw a,const qElmT*L) BEGIN const qElmT*const*const OOL=&L; RET (qEw)qEmh((**OOL).c*(qEW)a,(*L).d); END
static qEw qElmDiv(qEw a,const qElmT*L) BEGIN const qElmT*const*const OOL=&L; RET (qEw)qEmh((*OOL)->c,a); END
static int qElmDvs(qEw a,const qElmT*L) BEGIN RET L->c*(qEW)a<=L->c-1ull; END

/* Granlund-Montgomery round-up reciprocal: n<2^nb, s=nb+ceil(lg d), m=ceil(2^s/d) */
static qEgmT qEgmMk(qEw d,int nb)
BEGIN
qEgmT G,*const OG=&G;int l=0,*const Ol=&l,*const*const OOl=&Ol;
OG->d=d;
while(((qEW)1<<**OOl)<(qEW)d) INCR(*Ol);
OG->s=nb+*Ol;
(*OG).m=(((qEW)1<<OG->s)+(qEW)d-1ull)/(qEW)d;
RET G;
END
static qEw qEgmDiv(qEw n,const qEgmT*G) BEGIN const qEgmT*const*const OOG=&G; RET (qEw)(((**OOG).m*(qEW)n)>>(*OOG)->s); END

/* Barrett, mu=floor(2^32/d), one correction step at most for n<2^32 */
static qEbrT qEbrMk(qEw d)
BEGIN
qEbrT B,*const OB=&B;
OB->d=d;OB->mu=((qEW)1<<32)/(qEW)d;
RET *OB;
END
static qEw qEbrDm(qEw n,const qEbrT*B,qEw*r)
BEGIN
qEw q,t,*const Oq=&q,*const Ot=&t,*const*const OOt=&Ot;
*Oq=(qEw)(((qEW)n*B->mu)>>32);
**OOt=n-*Oq*B->d;
while(*Ot>=B->d) BEGIN **OOt-=B->d; INCR(*Oq); END
*r=*Ot;
RET *Oq;
END

/* Newton-Hensel: x <- x(2-dx), 3 -> 6 -> 12 -> 24 -> 48 bits */
static qEw qEhinv(qEw d)
BEGIN
qEw x=d,*const Ox=&x;int z;
LOOPN(z,4) *Ox*=2u-d**Ox;
RET *Ox;
END

/* Bezout over Z, iterative */
static long qExeu(long a,long b,long*x,long*y)
BEGIN
long r0=a,r1=b,s0=1,s1=0,t0=0,t1=1,qt,tm;
while(r1)
BEGIN
 qt=r0/r1;
 tm=r0-qt*r1;r0=r1;r1=tm;
 tm=s0-qt*s1;s0=s1;s1=tm;
 tm=t0-qt*t1;t0=t1;t1=tm;
END
*x=s0;*y=t0;
RET r0;
END
static qEw qEinvm(qEw a,qEw m)
BEGIN
long x,y,g,*const Ox=&x;
g=qExeu((long)a,(long)m,Ox,&y);
WHEN(g ISNOT 1L) RET 0u;
*Ox%=(long)m;WHEN(*Ox<0L) *Ox+=(long)m;
RET (qEw)*Ox;
END

/* x mod 13: 2^12==1 (Fermat), then 2^6==-1 */
static qEw qEf13(qEw x,const qEgmT*G13)
BEGIN
qEw s,v,*const Os=&s,*const Ov=&v,*const*const OOs=&Os;
*Os=(x&0xFFFu)+((x>>12)&0xFFFu)+(x>>24);
**OOs=(*Os&0xFFFu)+(*Os>>12);
*Ov=(**OOs&63u)+(*Os>>12)+65u-((*Os>>6)&63u);
RET *Ov-13u*qEgmDiv(*Ov,G13);
END

/* Montgomery, R=2^32, p odd < 2^31 */
static qEw qEredc(qEW T,const qEmoT*Mo)
BEGIN
qEw m=(qEw)T*Mo->ni,*const Om=&m;
qEW t=(T+(qEW)*Om*(qEW)Mo->p)>>32;
RET (qEw)(t>=(qEW)Mo->p?t-(qEW)Mo->p:t);
END
static qEmoT qEmoMk(qEw p)
BEGIN
qEmoT Mo,*const OM=&Mo;qEw r;
OM->p=p;
OM->ni=0u-qEhinv(p);
r=(qEw)((0xFFFFFFFFull%(qEW)p+1ull)%(qEW)p);
OM->one=r;
OM->r2=(qEw)(((qEW)r*(qEW)r)%(qEW)p);
RET Mo;
END
static qEw qEmoIn(qEw a,const qEmoT*Mo) BEGIN RET qEredc((qEW)a*(qEW)Mo->r2,Mo); END
static qEw qEmoMul(qEw a,qEw b,const qEmoT*Mo) BEGIN RET qEredc((qEW)a*(qEW)b,Mo); END
static qEw qEmoMm(qEw a,qEw b,const qEmoT*Mo) BEGIN RET qEredc((qEW)qEredc((qEW)a*(qEW)b,Mo)*(qEW)Mo->r2,Mo); END
static qEw qEmoPow(qEw a,qEW e,const qEmoT*Mo)
BEGIN
qEw x,r,*const Ox=&x,*const Or=&r,*const*const OOr=&Or;
*Ox=qEmoIn(a%Mo->p,Mo);**OOr=Mo->one;
while(e)
BEGIN
 WHEN(e&1ull) **OOr=qEmoMul(*Or,*Ox,Mo);
 *Ox=qEmoMul(*Ox,*Ox,Mo);
 e>>=1;
END
RET qEredc((qEW)*Or,Mo);
END

/* Miller-Rabin, bases {2,7,61}: deterministic below 4759123141 */
static int qEmr(qEw n)
BEGIN
static const qEw qb[3]={2u,7u,61u};
qEmoT Mo;qEw d,x;int s,t,u;
WHEN(n<2u) RET 0;
WHEN(n<4u) RET 1;
WHEN(NOT(n&1u) OR n>=0x80000000u) RET 0;
Mo=qEmoMk(n);
d=n-1u;s=0;
while(NOT(d&1u)) BEGIN d>>=1;INCR(s); END
LOOPN(t,3)
BEGIN
 WHEN(qb[t]%n IS 0u) continue;
 x=qEmoPow(qb[t],(qEW)d,&Mo);
 WHEN(x IS 1u OR x IS n-1u) continue;
 for(u=1;u<s;u++) BEGIN x=qEmoMm(x,x,&Mo); WHEN(x IS n-1u) break; END
 WHEN(u>=s) RET 0;
END
RET 1;
END

/* least NTT prime c*2^20+1 above 2^29 */
static qEw qEprime(void)
BEGIN
qEw c,*const Oc=&c;
for(*Oc=512u;*Oc<1024u;INCR(*Oc)) BEGIN WHEN(qEmr((*Oc<<20)|1u)) RET (*Oc<<20)|1u; END
RET 754974721u;
END

/* generator of GF(p)^*: g^((p-1)/f) != 1 for each prime f | p-1 */
static qEw qEproot(const qEmoT*Mo)
BEGIN
qEw f[16],t,z,g;int nf=0,u,ok;
t=Mo->p-1u;
for(z=2u;z*z<=t;INCR(z)) BEGIN WHEN(t%z IS 0u) BEGIN f[nf]=z;INCR(nf); while(t%z IS 0u) t/=z; END END
WHEN(t>1u) BEGIN f[nf]=t;INCR(nf); END
for(g=2u;g<Mo->p;INCR(g))
BEGIN
 ok=1;
 LOOPN(u,nf) BEGIN WHEN(qEmoPow(g,(qEW)((Mo->p-1u)/f[u]),Mo) IS 1u) BEGIN ok=0;break; END END
 WHEN(ok) RET g;
END
RET 0u;
END

/* iterative radix-2 NTT over GF(p), Montgomery twiddles */
static void qEntt(qEw*a,int n,int inv,const qEkitT*K)
BEGIN
const qEmoT*const Om=&K->Mo;
int u,v,b,len,h;qEw t,w,wl,x,y;
qEw*const*const Oa=&a;
for(u=1,v=0;u<n;u++)
BEGIN
 for(b=n>>1;v&b;b>>=1) v^=b;
 v^=b;
 WHEN(u<v) BEGIN t=*(*Oa+u);*(*Oa+u)=*(*Oa+v);*(*Oa+v)=t; END
END
for(len=2;len<=n;len<<=1)
BEGIN
 wl=qEmoPow(K->g,(qEW)((Om->p-1u)/(qEw)len),Om);
 WHEN(inv) wl=qEmoPow(wl,(qEW)(Om->p-2u),Om);
 wl=qEmoIn(wl,Om);
 h=len>>1;
 for(u=0;u<n;u+=len)
 BEGIN
  w=Om->one;
  LOOPN(v,h)
  BEGIN
   x=*(*Oa+u+v);
   y=qEredc((qEW)w*(qEW)*(*Oa+u+v+h),Om);
   *(*Oa+u+v)=qEADDP(x,y,Om->p);
   *(*Oa+u+v+h)=qESUBP(x,y,Om->p);
   w=qEmoMul(w,wl,Om);
  END
 END
END
WHEN(inv)
BEGIN
 wl=qEmoIn(qEmoPow((qEw)n,(qEW)(Om->p-2u),Om),Om);
 LOOPN(u,n) *(*Oa+u)=qEredc((qEW)wl*(qEW)*(*Oa+u),Om);
END
END

static qEbnT qEbnOf(qEw v,const qEkitT*K)
BEGIN
qEbnT A,*const OA=&A;
OA->n=0;
do BEGIN OA->d[OA->n]=qElmMod(v,&K->L10);v=qElmDiv(v,&K->L10);INCR(OA->n); END while(v AND OA->n<qE_NTT);
RET A;
END

/* decimal bignum product: NTT cyclic convolution of the digit vectors, then carry */
static qEbnT qEbnMul(const qEbnT*a,const qEbnT*b,const qEkitT*K)
BEGIN
qEw x[qE_NTT],y[qE_NTT],cy;qEbnT Z,*const OZ=&Z;int len=1,u;
while(len<a->n+b->n AND len<qE_NTT) len<<=1;
LOOPN(u,len) BEGIN x[u]=u<a->n?a->d[u]:0u;y[u]=u<b->n?b->d[u]:0u; END
qEntt(x,len,0,K);qEntt(y,len,0,K);
LOOPN(u,len) x[u]=qEmoMm(x[u],y[u],&K->Mo);
qEntt(x,len,1,K);
cy=0u;OZ->n=0;
LOOPN(u,len) BEGIN cy+=x[u];OZ->d[OZ->n]=qElmMod(cy,&K->L10);cy=qElmDiv(cy,&K->L10);INCR(OZ->n); END
while(cy AND OZ->n<qE_NTT) BEGIN OZ->d[OZ->n]=qElmMod(cy,&K->L10);cy=qElmDiv(cy,&K->L10);INCR(OZ->n); END
while(OZ->n>1 AND OZ->d[OZ->n-1] IS 0u) OZ->n--;
RET Z;
END

/* radix 10 -> radix 2^16 by repeated long division */
static qEW qEbnVal(const qEbnT*a)
BEGIN
qEw D[qE_NTT],rem,cur;int u,nz,sh=0;qEW v=0ull,*const Ov=&v;
LOOPN(u,a->n) D[u]=a->d[a->n-1-u];
FOREVER
BEGIN
 nz=0;rem=0u;
 LOOPN(u,a->n) BEGIN cur=rem*10u+D[u];D[u]=cur>>16;rem=cur&0xFFFFu;WHEN(D[u]) nz=1; END
 WHEN(sh<64) *Ov|=(qEW)rem<<sh;
 sh+=16;
 WHEN(NOT nz) break;
END
RET *Ov;
END

/* Berlekamp-Massey over GF(p); C[0..L] connection polynomial */
static int qEbm(const qEw*s,int nn,qEw*C,const qEkitT*K)
BEGIN
qEw Bv[qE_BMN],T[qE_BMN],d,b=1u,coef;int L=0,m=1,u,v;
const qEmoT*const Om=&K->Mo;
LOOPN(u,qE_BMN) BEGIN C[u]=0u;Bv[u]=0u; END
C[0]=1u;Bv[0]=1u;
LOOPN(u,nn)
BEGIN
 d=s[u];
 for(v=1;v<=L;v++) d=qEADDP(d,qEmoMm(C[v],s[u-v],Om),Om->p);
 WHEN(d IS 0u) BEGIN INCR(m);continue; END
 coef=qEmoMm(d,qEmoPow(b,(qEW)(Om->p-2u),Om),Om);
 LOOPN(v,qE_BMN) T[v]=C[v];
 for(v=0;v+m<qE_BMN;v++) C[v+m]=qESUBP(C[v+m],qEmoMm(coef,Bv[v],Om),Om->p);
 WHEN(2*L<=u) BEGIN L=u+1-L;LOOPN(v,qE_BMN) Bv[v]=T[v];b=d;m=1; END
 OTHERWISE INCR(m);
END
RET L;
END

static void qEcrcMk(qEw*T)
BEGIN
qEw c,z;int b;
for(z=0u;z<256u;INCR(z)) BEGIN c=z;LOOPN(b,8) c=(c>>1)^(0xEDB88320u&(0u-(c&1u)));T[z]=c; END
END

/* CRC-32, eightfold Duff unroll */
static qEw qEcrc(const unsigned char*bp,int n,const qEw*T)
BEGIN
qEw c=0xFFFFFFFFu,*const Oc=&c;int z=0,r8;
WHEN(n<=0) RET 0u;
r8=(n+7)/8;
switch(n&7)
BEGIN
case 0: do{ *Oc=T[(*Oc^bp[z])&0xFFu]^(*Oc>>8);INCR(z);
case 7:     *Oc=T[(*Oc^bp[z])&0xFFu]^(*Oc>>8);INCR(z);
case 6:     *Oc=T[(*Oc^bp[z])&0xFFu]^(*Oc>>8);INCR(z);
case 5:     *Oc=T[(*Oc^bp[z])&0xFFu]^(*Oc>>8);INCR(z);
case 4:     *Oc=T[(*Oc^bp[z])&0xFFu]^(*Oc>>8);INCR(z);
case 3:     *Oc=T[(*Oc^bp[z])&0xFFu]^(*Oc>>8);INCR(z);
case 2:     *Oc=T[(*Oc^bp[z])&0xFFu]^(*Oc>>8);INCR(z);
case 1:     *Oc=T[(*Oc^bp[z])&0xFFu]^(*Oc>>8);INCR(z);
        }while(--r8>0);
END
RET *Oc^0xFFFFFFFFu;
END

/* balanced Feistel, 4 rounds over 16-bit halves */
static qEw qEfF(qEw h,qEw key) BEGIN RET ((h*0x9E37u+key)^(h>>3)^(key<<2))&0xFFFFu; END
static qEw qEfE(qEw x,const qEkitT*K)
BEGIN
qEw a=x>>16,b=x&0xFFFFu,t,*const Oa=&a,*const Ob=&b;int r;
for(r=0;r<4;r++) BEGIN t=*Ob;*Ob=*Oa^qEfF(*Ob,K->fk[r]);*Oa=t; END
RET (*Oa<<16)|*Ob;
END
static qEw qEfD(qEw y,const qEkitT*K)
BEGIN
qEw a=y>>16,b=y&0xFFFFu,t,*const Oa=&a,*const Ob=&b;int r;
for(r=3;r>=0;r--) BEGIN t=*Oa;*Oa=*Ob^qEfF(*Oa,K->fk[r]);*Ob=t; END
RET (*Oa<<16)|*Ob;
END

/* k-permutation of rank r: factoradic of r*(n-3)!, Lehmer digits, Fenwick order statistics */
static void qEunrank(qEw r,const qEkitT*K,int*tri)
BEGIN
qEw dg[qE_MAXP]={0u},fw[qE_MAXP+1],x,rad,step,pos,rem=0u;int n=K->n,t,u;
qEw*const Odg=dg,*const Ofw=fw,*const*const OOfw=&Ofw;
WHEN(n<=qE_MAXF)
BEGIN
 x=r*K->fct[n-3];
 for(rad=1u;rad<=(qEw)n;INCR(rad))
 BEGIN
  WHEN(rad IS 1u) BEGIN *(Odg+n-1)=0u;continue; END
  *(Odg+n-(int)rad)=qElmMod(x,&K->Lr[rad]);
  x=qElmDiv(x,&K->Lr[rad]);
 END
END
OTHERWISE
BEGIN
 *(Odg+0)=qEbrDm(r,&K->Bf0,&rem);
 *(Odg+1)=qEbrDm(rem,&K->Bf1,&rem);
 *(Odg+2)=rem;
END
for(u=1;u<=n;u++) *(*OOfw+u)=qELOWBIT((qEw)u);
step=1u;while((step<<1)<=(qEw)n) step<<=1;
LOOPN(t,3)
BEGIN
 pos=0u;rem=*(Odg+t);
 for(x=step;x;x>>=1) BEGIN WHEN(pos+x<=(qEw)n AND *(Ofw+pos+x)<=rem) BEGIN pos+=x;rem-=*(*OOfw+pos); END END
 *(tri+t)=(int)pos;
 for(x=pos+1u;x<=(qEw)n;x+=qELOWBIT(x)) (*(Ofw+x))--;
END
END

/* x -> (rl,rm,rr,i,j,k): CRT(2,13)+Hensel exact division, GM reciprocal, Lemire, Barrett */
static void qEdec(qEw x,const qEkitT*K,int*dg)
BEGIN
qEw r2,r13,d,q,q2,q3,t,*const Oq=&q,*const*const OOq=&Oq;int*const*const Odg=&dg;
r2=x&1u;
r13=qEf13(x,&K->G13);
d=qElmMod(K->e2*r2+K->e13*r13,&K->L26);
*(*Odg+5)=(int)d;
**OOq=((x-d)>>1)*K->inv13;
q2=qEgmDiv(*Oq,&K->G26);
*(*Odg+4)=(int)(*Oq-26u*q2);
*(*Odg+3)=(int)qElmMod(q2,&K->L26);
q3=qElmDiv(q2,&K->L26);
q3=qEbrDm(q3,&K->Br,&t);*(*Odg+2)=(int)t;
q3=qEbrDm(q3,&K->Br,&t);*(*Odg+1)=(int)t;
(void)qEbrDm(q3,&K->Br,&t);*(*Odg+0)=(int)t;
END

/* s(t+1) = c1*s(t) + c2*s(t-1) mod p, coefficients learned by qEbm */
static qEw qEstep(qEw x,qEw y,const qEkitT*K)
BEGIN
qEw u=qEredc((qEW)K->c1M*(qEW)x,&K->Mo),v=qEredc((qEW)K->c2M*(qEW)y,&K->Mo);
RET qEADDP(u,v,K->Mo.p);
END

/* 200 | v  via  v = h*2^32+l,  2^32 == h96 (mod 200),  then CRT(8,25) */
static int qEp200(qEW v,const qEkitT*K)
BEGIN
qEw t,r,*const Ot=&t,*const Or=&r,*const*const OOr=&Or;
*Ot=qElmMod(qEHI(v),&K->L200)*K->h96+qElmMod(qELO(v),&K->L200);
**OOr=qElmMod(*Ot,&K->L200);
RET ((*Or&7u) IS 0u) AND qElmDvs(**OOr,&K->L25);
END

static int qEop1(qEW v) BEGIN RET ((v*v+v)&1ull) IS 0ull; END
static int qEop2(qEw x,const qEkitT*K) BEGIN qEw r=qEf13(x,&K->G13); RET qEf13(r*r,&K->G13) ISNOT 7u; END

/* scatter the six digits into the live slots, Duff by four */
static void qEspread(volatile int*const*sl,const int*dg,int m)
BEGIN
int nq,z=0,*const Oz=&z;
WHEN(m<=0) RET;
nq=(m+3)/4;
switch(m&3)
BEGIN
case 0: do{ **(sl+*Oz)=*(dg+*Oz);INCR(*Oz);
case 3:     **(sl+*Oz)=*(dg+*Oz);INCR(*Oz);
case 2:     **(sl+*Oz)=*(dg+*Oz);INCR(*Oz);
case 1:     **(sl+*Oz)=*(dg+*Oz);INCR(*Oz);
        }while(--nq>0);
END
END

static void qEkitMk(qEkitT*K,int n,int sw,const unsigned char*pr,int plen)
BEGIN
qEw sq[qE_SEQ],C[qE_BMN],z,acc;int u,od[6];
qEbnT A,b26,br;
K->n0=n;
K->n=n<0?0:(n>qE_MAXP?qE_MAXP:n);
K->R=sw?26:1;
K->L10=qElmMk(10u);K->L25=qElmMk(25u);K->L26=qElmMk(26u);K->L200=qElmMk(200u);
K->fct[0]=1u;K->Lr[0]=qElmMk(2u);K->Lr[1]=qElmMk(2u);
for(z=1u;z<=(qEw)qE_MAXF;INCR(z)) BEGIN K->fct[z]=K->fct[z-1u]*z;WHEN(z>=2u) K->Lr[z]=qElmMk(z); END
K->G13=qEgmMk(13u,8);K->G26=qEgmMk(26u,qE_NB);
K->Br=qEbrMk((qEw)K->R);
K->Bf0=qEbrMk(K->n>qE_MAXF?(qEw)((K->n-1)*(K->n-2)):1u);
K->Bf1=qEbrMk(K->n>qE_MAXF?(qEw)(K->n-2):1u);
K->inv13=qEhinv(13u);
K->e2=13u*qEinvm(13u%2u,2u);
K->e13=2u*qEinvm(2u,13u);
K->h96=qElmMod(qElmMod(0xFFFFFFFFu,&K->L200)+1u,&K->L200);
K->Mo=qEmoMk(qEprime());
K->g=qEproot(&K->Mo);
LOOPN(u,6) od[u]=0;
LOOPN(u,qE_SEQ)
BEGIN
 sq[u]=0u;
 acc=0u;
 BEGIN int w; LOOPN(w,6) acc=acc*26u+(qEw)od[w]; END
 sq[u]=acc;
 BEGIN int w=5; while(w>=0) BEGIN INCR(od[w]);WHEN(od[w]<26) break;od[w]=0;w--; END END
END
K->L=qEbm(sq,qE_SEQ,C,K);
K->c1M=qEmoIn(qESUBP(0u,C[1],K->Mo.p),&K->Mo);
K->c2M=qEmoIn(qESUBP(0u,C[2],K->Mo.p),&K->Mo);
qEcrcMk(K->tab);
K->crc=qEcrc(pr,plen,K->tab);
LOOPN(u,4) K->fk[u]=((K->crc>>(8*u))^(K->crc<<(8*u+3))^(0x9E37u*(qEw)(u+1)))&0xFFFFu;
b26=qEbnOf(26u,K);br=qEbnOf((qEw)K->R,K);A=qEbnOf(1u,K);
LOOPN(u,3) BEGIN A=qEbnMul(&A,&b26,K);A=qEbnMul(&A,&br,K); END
K->B=(qEw)qEbnVal(&A);
WHEN(K->n>=3)
BEGIN
 A=qEbnOf((qEw)K->n,K);
 b26=qEbnOf((qEw)(K->n-1),K);A=qEbnMul(&A,&b26,K);
 b26=qEbnOf((qEw)(K->n-2),K);A=qEbnMul(&A,&b26,K);
 K->P=(qEw)qEbnVal(&A);
END
OTHERWISE K->P=0u;
END

#endif
