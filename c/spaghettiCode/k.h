#ifndef qB_KH
#define qB_KH
#include <stdint.h>
#include <limits.h>

typedef uint32_t qBu;
typedef unsigned long long qBw;
typedef unsigned char qBc;
typedef void (*qBv)(void);

#define qB_ONE (0x1000%015)
#define qB_W16 (TWICE(TWICE(TWICE(TWICE(qB_ONE)))))
#define qB_LO16 0xFFFFu
#define qB_NR (TWICE(3)*qB_ONE)
#define qB_MU26 1321528399u
#define qB_SH26 35
#define qB_R2632 22u
#define qB_MSK(c) (0u-(qBu)(c))
#define qB_CSUB(r,m) ((r)-((m)&qB_MSK((r)>=(m))))
#define qB_MADD(x,y) (((x)^(y))+TWICE((x)&(y)))
#define qB_MSUB(x,y) ((((x)^~(y))+TWICE((x)&~(y)))+qB_ONE)
#define qB_MOR(x,y) (((x)+(y))-((x)&(y)))
#define qB_ARM() do{ WHEN(NOT qB_rdy) qB_boot(); }while(0)

static int qB_rdy=0;
static int qB_pp=0,qB_g=0,qB_ord=0,qB_ng=0,qB_ckok=0,qB_bml=0,qB_nfac=0;
static int qB_fac[8];
static int qB_lg[32],qB_ex[64],qB_zc[32];
static qBu qB_e2=0,qB_e13=0,qB_bmu=0,qB_bmu26=0,qB_mnp=0,qB_mr2=0,qB_fm=0;
static qBu qB_K=1u,qB_Ki=1u,qB_m10=0xCCCCCCCDu;
static qBu qB_rk[8];
static qBu qB_ct[256];
static qBc qB_up[256];
static unsigned qB_dph=0u;
static void qB_boot(void);
static void qB_mknet(void);
static void qB_mkbit(void);
static void qB_b_lag(void);
static void qB_b_f4(void);

/* b^e mod m, m<2^16 */
static qBu qB_pw(qBu b,qBu e,qBu m)
BEGIN
qBu r=1u%m,*const Or=&r,*const*const OOr=&Or;
b%=m;
while(e) BEGIN WHEN(ODD(e)) **OOr=(*Or*b)%m; b=(b*b)%m; e=HALF(e); END
RET r;
END

/* b^e mod m, m<2^32 */
static qBu qB_pw64(qBu b,qBu e,qBu m)
BEGIN
qBw r=(qBw)(1u%m),x=(qBw)(b%m),*const Ox=&x,*const*const OOx=&Ox;
while(e) BEGIN WHEN(ODD(e)) r=(r**Ox)%m; **OOx=(*Ox*x)%m; e=HALF(e); END
RET (qBu)r;
END

static int qB_mr(qBu n)
BEGIN
static const qBu qBwb[4]={2u,3u,5u,7u};
qBu d,a,x,s,t;int z;
WHEN(n<2u) RET 0;
WHEN(NOT ODD(n)) RET n IS 2u;
d=n-1u;s=0u;
while(NOT ODD(d)) BEGIN d=HALF(d);INCR(s); END
LOOPN(z,4)
BEGIN
 a=qBwb[z]%n; WHEN(NOT a) continue;
 x=qB_pw64(a,d,n);
 WHEN(x IS 1u OR x IS n-1u) continue;
 for(t=1u;t<s;INCR(t)) BEGIN x=(qBu)(((qBw)x*x)%n); WHEN(x IS n-1u) break; END
 WHEN(t>=s) RET 0;
END
RET 1;
END

static int qB_eg(int a,int b,int*x)
BEGIN
int r0=a,r1=b,s0=1,s1=0,q,t,*const Os0=&s0,*const*const OOs0=&Os0;
while(r1) BEGIN q=r0/r1;t=r0-q*r1;r0=r1;r1=t;t=**OOs0-q*s1;*Os0=s1;s1=t; END
*x=s0;
RET r0;
END

static int qB_inv(int a,int m)
BEGIN
int x=0;
WHEN(qB_eg(((a%m)+m)%m,m,&x) ISNOT 1) RET 0;
RET ((x%m)+m)%m;
END

static qBu qB_hinv(qBu k)
BEGIN
qBu x=k,*const Ox=&x;int z;
LOOPN(z,5) *Ox*=2u-k**Ox;
RET x;
END

/* Barrett, x<2^16 */
static qBu qB_bar(qBu x)
BEGIN
qBu q=(x*qB_bmu)>>qB_W16,r=x-q*(qBu)qB_pp;
RET qB_CSUB(r,(qBu)qB_pp);
END

/* REDC, R=2^16, T<p*R */
static qBu qB_rdc(qBu T)
BEGIN
qBu m=((T&qB_LO16)*qB_mnp)&qB_LO16,t=(T+m*(qBu)qB_pp)>>qB_W16;
RET qB_CSUB(t,(qBu)qB_pp);
END

static qBu qB_mon(qBu c) BEGIN RET qB_rdc(qB_rdc(c*qB_mr2)); END

/* GF(p) addition via Zech logarithms */
static int qB_zad(int x,int y)
BEGIN
int i0,j0,d;
WHEN(NOT x) RET y;
WHEN(NOT y) RET x;
i0=qB_lg[x];j0=qB_lg[y];
d=j0-i0;WHEN(d<0) d+=qB_pp-1;
WHEN(qB_zc[d]<0) RET 0;
RET qB_ex[i0+qB_zc[d]];
END

static qBu qB_crt(qBu p,qBu r)
BEGIN
qBu y=qB_MADD(qB_e2&qB_MSK(p),qB_e13*r),q=(y*qB_bmu26)>>qB_W16;
y-=q*(qBu)M;
RET qB_CSUB(y,(qBu)M);
END

static qBu qB_b26(qBu m)
BEGIN
qBu q=(qBu)(((qBw)m*qB_MU26)>>qB_SH26);
RET m-q*(qBu)M;
END

static int qB_x2r(long long a)
BEGIN
qBw w=(qBw)a,sg=w>>63,m=(w^(0ull-sg))+sg;
qBu r=qB_b26(qB_b26((qBu)(m>>32))*qB_R2632+qB_b26((qBu)m)),mk;
mk=qB_MSK((qBu)sg&(qBu)(r ISNOT 0u));
RET (int)((r&~mk)|(((qBu)M-r)&mk));
END

#define qB_MS(X) X(qB_sA,0x2C9) X(qB_sB,0x0F3) X(qB_sC,0x35E) X(qB_sD,0x1B0) X(qB_sE,0x3A7) X(qB_sF,0x064) X(qB_sG,0x2D1) X(qB_sH,0x16A)
#define qB_XE(nm,v) nm=v,
enum qB_mse { qB_MS(qB_XE) qB_sZ=0 };
#undef qB_XE

static int qB_m26(int a)
BEGIN
qBu u=0u,p=0u,c0=0u,c1=0u,c2=0u,r=0u,sg=0u;
qBu*const Ou=&u,*const*const OOu=&Ou,*const Or=&r,*const*const OOr=&Or;
int st=qB_sA;
FOREVER switch(st)
BEGIN
 case qB_sA: **OOu=(qBu)a;sg=*Ou>>31;st=ODD(*Ou**Ou+*Ou)?qB_sH:qB_sB;break;
 case qB_sB: p=*Ou-TWICE(HALF(**OOu));st=qB_sC;break;
 case qB_sC: c0=u&qB_fm;c1=(**OOu>>qB_ord)&qB_fm;c2=*Ou>>TWICE(qB_ord);st=qB_sD;break;
 case qB_sD: c0=qB_bar(c0);c1=qB_bar(c1);st=qB_sE;break;
 case qB_sE: **OOr=(qBu)qB_zad(qB_zad((int)c0,(int)c1),(int)qB_mon(c2));st=sg?qB_sF:qB_sG;break;
 case qB_sF: *Or=(qBu)qB_zad((int)**OOr,qB_ng);st=qB_sG;break;
 case qB_sG: RET (int)qB_crt(p,*Or);
 case qB_sH: RET qB_x2r((long long)a);
 default: st=qB_sA;break;
END
END

static int qB_x2(long long a)
BEGIN
int(*const Of)(int)=qB_m26,(*const*const OOf)(int)=&Of;const long long*const Oa=&a,*const*const OOa=&Oa;
qB_ARM();
WHEN(**OOa>=(long long)INT_MIN AND *Oa<=(long long)INT_MAX) RET (**OOf)((int)**OOa);
RET qB_x2r(*Oa);
END

static int qB_gmod(int a,int b)
BEGIN
qBu ua=(qBu)a,ub=(qBu)b,sa=ua>>31,sb=ub>>31,ma,mb,r=0u,*const Or=&r,*const*const OOr=&Or;qBw v;int z;
WHEN(NOT b) RET INT_MIN;
ma=(ua^(0u-sa))+sa;mb=(ub^(0u-sb))+sb;
for(z=31;z>=0;z--) BEGIN **OOr=TWICE(*Or)|((ma>>z)&1u); WHEN(*Or>=mb) *Or-=mb; END
WHEN(NOT sa OR NOT r) RET (int)r;
WHEN(NOT sb) RET (int)(mb-r);
v=(qBw)r+(qBw)mb;
WHEN(v>=(qBw)1u<<31) RET INT_MIN;
RET -(int)v;
END

static qBu qB_F(qBu x,qBu k)
BEGIN
x&=qB_LO16;
RET ((x*0x9E3Bu+k)^(x*x>>7)^(x>>3))&qB_LO16;
END

static qBu qB_fe(qBu u,int dir)
BEGIN
qBu L=u>>qB_W16,R=u&qB_LO16,t;int z;
qBu*const OL=&L,*const ORr=&R,*const*const OOL=&OL;
WHEN(dir>0) LOOPN(z,qB_NR) BEGIN t=*ORr;*ORr=**OOL^qB_F(R,qB_rk[z]);*OL=t; END
OTHERWISE for(z=qB_NR-1;z>=0;z--) BEGIN t=L;**OOL=*ORr^qB_F(*OL,qB_rk[z]);R=t; END
RET (L<<qB_W16)|R;
END

static qBu qB_dc(qBu u)
BEGIN
qBc dg[12];int n=0;qBu q,w=0u,h=u&qB_LO16;
WHEN((h*h)%7u IS 6u) RET u^h;
do BEGIN q=(qBu)(((qBw)u*qB_m10)>>qB_SH26);dg[n]=(qBc)(u-q*10u);INCR(n);u=q; END while(u);
while(n) BEGIN n--;w=w*10u+dg[n]; END
RET w;
END

static int qB_s32(qBu u)
BEGIN
WHEN(u<=(qBu)INT_MAX) RET (int)u;
RET -(int)(~u)-1;
END

static qBu qB_crc(const char*s)
BEGIN
qBu c=0xFFFFFFFFu,*const Oc=&c,*const*const OOc=&Oc;
while(*s) BEGIN **OOc=qB_ct[(*Oc^(qBc)*s)&0xFFu]^(*Oc>>8);INCR(s); END
RET ~c;
END

/* Z/(2^31-1) Horner */
#define qB_MP 0x7FFFFFFFu
#define qB_MFOLD(h) ((h)=((h)&qB_MP)+((h)>>31))
static qBu qB_rh(const char*s)
BEGIN
qBw h=0u,*const Oh=&h,*const*const OOh=&Oh;
while(*s) BEGIN **OOh=*Oh*131u+(qBc)*s;qB_MFOLD(*Oh);qB_MFOLD(**OOh);INCR(s); END
RET (qBu)h;
END

/* FNV-1a */
#define qB_FNVO 0x811C9DC5u
#define qB_FNVP 0x01000193u
static qBu qB_fnv(const char*s)
BEGIN
qBu h=qB_FNVO,*const Oh=&h,*const*const OOh=&Oh;
const char*const*const Os=&s;
while(**Os) BEGIN **OOh=(*Oh^(qBc)**Os)*qB_FNVP;INCR(s); END
RET h;
END

/* NTT over GF(257), n=16, w=2 (2^8=-1) */
#define qB_NP 257u
#define qB_NN (qB_W16)
static qBu qB_nw16[32];
static int qB_nok=0;

static void qB_ntt(qBu*x)
BEGIN
int z,y,h,k;qBu t,u,v,*const Ox=x,*const*const OOx=&Ox;
for(z=1,y=0;z<qB_NN;INCR(z))
BEGIN
 for(h=HALF(qB_NN);y&h;h=HALF(h)) y^=h;
 y^=h;
 WHEN(z<y) BEGIN t=*(Ox+z);*(Ox+z)=*(*OOx+y);*(*OOx+y)=t; END
END
for(h=2;h<=qB_NN;h=TWICE(h))
 for(z=0;z<qB_NN;z+=h)
  LOOPN(k,HALF(h))
  BEGIN
   u=*(Ox+z+k);v=(*(*OOx+z+k+HALF(h))*qB_nw16[(qB_NN/h)*k])%qB_NP;
   *(*OOx+z+k)=(u+v)%qB_NP;*(Ox+z+k+HALF(h))=(u+qB_NP-v)%qB_NP;
  END
END

static int qB_spec(const char*s,qBu*x)
BEGIN
int z;
LOOPN(z,qB_NN) *(x+z)=0u;
for(z=0;*(s+z);INCR(z)) BEGIN WHEN(z>=qB_NN) RET 0; *(x+z)=(qBc)*(s+z); END
qB_ntt(x);
RET 1;
END

static int qB_speq(int ka,const qBu*sa,const char*s,qBu*sb)
BEGIN
int z;
WHEN(NOT ka OR NOT qB_nok) RET 1;
WHEN(NOT qB_spec(s,sb)) RET 1;
LOOPN(z,qB_NN) WHEN(*(sa+z) ISNOT *(sb+z)) RET 0;
RET 1;
END

/* protothread scan */
typedef struct qB_pts { int lc,t; qBu h,r,f; } qB_pt;
#define qB_PTB(p) switch((p)->lc) BEGIN case 0:
#define qB_PTY(p,v) do{ (p)->lc=__LINE__;RET (v);case __LINE__:; }while(0)
#define qB_PTE(p) END (p)->lc=0;RET -1

static int qB_scan(qB_pt*p,char**tab,int n)
BEGIN
qB_PTB(p);
for(p->t=0;p->t<n;INCR(p->t))
BEGIN
 WHEN(((qB_crc(*(tab+p->t)) IS p->h) AND (qB_rh(*(tab+p->t)) IS p->r) AND (qB_fnv(*(tab+p->t)) IS p->f)) OR NOT qB_ckok)
  qB_PTY(p,p->t);
 OTHERWISE
  qB_PTY(p,-2-p->t);
END
qB_PTE(p);
END

static void qB_b_ntt(void)
BEGIN
int z;qBu w=1u;
LOOPN(z,qB_NN) BEGIN qB_nw16[z]=w;w=TWICE(w)%qB_NP; END
qB_nok=(w IS 1u) AND (qB_nw16[HALF(qB_NN)] IS qB_NP-1u);
END

static void qB_b_fac(void)
BEGIN
int n=M,d;
qB_nfac=0;
for(d=2;d*d<=n;INCR(d)) while(NOT (n%d)) BEGIN qB_fac[qB_nfac++]=d;n/=d; END
WHEN(n>1) qB_fac[qB_nfac++]=n;
qB_pp=qB_fac[qB_nfac-1];
WHEN(NOT qB_mr((qBu)qB_pp) OR qB_nfac ISNOT 2) qB_pp=13;
END

static void qB_b_prim(void)
BEGIN
int k,g,q,n,ok;
qB_ord=0;
for(k=1;k<64;INCR(k)) WHEN(qB_pw(2u,(qBu)k,(qBu)qB_pp) IS 1u) BEGIN qB_ord=k;break; END
for(g=2;g<qB_pp;INCR(g))
BEGIN
 ok=1;n=qB_pp-1;
 for(q=2;q<=n;INCR(q)) WHEN(NOT (n%q))
 BEGIN
  WHEN(qB_pw((qBu)g,(qBu)((qB_pp-1)/q),(qBu)qB_pp) IS 1u) ok=0;
  while(NOT (n%q)) n/=q;
 END
 WHEN(ok) BEGIN qB_g=g;break; END
END
qB_fm=(1u<<qB_ord)-1u;
END

static void qB_b_gf(void)
BEGIN
int z,s;
qB_ex[0]=1;
for(z=1;z<TWICE(qB_pp);INCR(z)) qB_ex[z]=(qB_ex[z-1]*qB_g)%qB_pp;
LOOPN(z,qB_pp-1) qB_lg[qB_ex[z]]=z;
LOOPN(z,qB_pp-1) BEGIN s=(1+qB_ex[z])%qB_pp;qB_zc[z]=s?qB_lg[s]:-1; END
END

static void qB_b_crt(void)
BEGIN
int n2=M/qB_pp,np=M/n2;
qB_e2=(qBu)(np*qB_inv(np%n2,n2));
qB_e13=(qBu)(n2*qB_inv(n2%qB_pp,qB_pp));
qB_bmu=(qBu)((1uL<<qB_W16)/(unsigned long)qB_pp);
qB_bmu26=(qBu)((1uL<<qB_W16)/(unsigned long)M);
qB_m10=(qBu)((((qBw)1u<<qB_SH26)+9u)/10u);
END

static void qB_b_mont(void)
BEGIN
qB_mnp=(0u-qB_hinv((qBu)qB_pp))&qB_LO16;
qB_mr2=qB_pw(TWICE(qB_ONE),(qBu)TWICE(qB_W16),(qBu)qB_pp);
qB_ng=(int)(((qBu)qB_pp-qB_mr2)%(qBu)qB_pp);
END

static void qB_b_crc(void)
BEGIN
qBu c;int z,y;
LOOPN(z,256) BEGIN c=(qBu)z; LOOPN(y,8) c=(c>>1)^(0xEDB88320u&qB_MSK(ODD(c))); qB_ct[z]=c; END
qB_ckok=qB_crc("123456789") IS 0xCBF43926u;
END

static void qB_b_hen(void)
BEGIN
qB_K=qB_crc("R0")|1u;
qB_Ki=qB_hinv(qB_K);
WHEN(qB_K*qB_Ki ISNOT 1u) BEGIN qB_K=1u;qB_Ki=1u; END
END

/* GF(2) Berlekamp-Massey */
static int qB_bm(const qBc*sq,int n,qBc*cc)
BEGIN
qBc bb[72],tt[72];
int L=0,m=-1,z,y,d;
LOOPN(z,n+1) BEGIN cc[z]=0;bb[z]=0; END
cc[0]=1;bb[0]=1;
LOOPN(z,n)
BEGIN
 d=sq[z];
 for(y=1;y<=L;INCR(y)) d^=cc[y]&sq[z-y];
 WHEN(d)
 BEGIN
  LOOPN(y,n+1) tt[y]=cc[y];
  for(y=0;y+z-m<=n;INCR(y)) cc[y+z-m]^=bb[y];
  WHEN(TWICE(L)<=z) BEGIN L=z+1-L;m=z;LOOPN(y,n+1) bb[y]=tt[y]; END
 END
END
RET L;
END

static void qB_b_lfsr(void)
BEGIN
qBc sq[64+TWICE(TWICE(TWICE(qB_W16)))],cc[72];
qBu st=0xACE1u,k;int z,y,n=64;
LOOPN(z,n) BEGIN sq[z]=(qBc)ODD(st);st=(st>>1)^(0xB400u&qB_MSK(ODD(st))); END
qB_bml=qB_bm(sq,n,cc);
for(z=n;z<n+qB_NR*qB_W16;INCR(z)) BEGIN sq[z]=0;for(y=1;y<=qB_bml;INCR(y)) sq[z]^=cc[y]&sq[z-y]; END
LOOPN(z,qB_NR) BEGIN k=0u;LOOPN(y,qB_W16) k=TWICE(k)|sq[n+z*qB_W16+y];qB_rk[z]=k; END
END

static void qB_b_up(void)
BEGIN
int z;
LOOPN(z,256) qB_up[z]=(qBc)(z-(int)TWICE(TWICE(TWICE(TWICE(TWICE((unsigned)((unsigned)(z-0141)<(unsigned)M)))))));
END

#define qB_BOOT(X) X(qB_b_fac) X(qB_b_prim) X(qB_b_gf) X(qB_b_crt) X(qB_b_mont) X(qB_b_crc) X(qB_b_hen) X(qB_b_lfsr) X(qB_b_up) X(qB_b_ntt) X(qB_b_lag) X(qB_b_f4) X(qB_mknet) X(qB_mkbit)
#define qB_XB(f) f,
static qBv const qB_btab[]={ qB_BOOT(qB_XB) 0 };
#undef qB_XB

static void qB_boot(void)
BEGIN
qBv const*q=qB_btab,*const*const Oq=&q;
qB_rdy=1;
while(**Oq) BEGIN (**Oq)();INCR(q); END
END

#endif
