#ifndef qB_LH
#define qB_LH
#include "c.h"

#define qB_NW (TWICE(TWICE(qB_W16))>>qB_ONE)
#define qB_SENT INT_MAX
#define qB_P29 (TWICE(TWICE(TWICE(TWICE(qB_ONE))))+M/TWICE(qB_ONE))

static qBc qB_nwa[256],qB_nwb[256];
static int qB_nwn=0;

/* Batcher odd-even merge, n=32 */
static void qB_mknet(void)
BEGIN
int p,k,j,z,*const Ok=&k,*const*const OOk=&Ok;
qB_nwn=0;
for(p=1;p<qB_NW;p=TWICE(p))
 for(**OOk=p;*Ok>=1;*Ok=HALF(k))
  for(j=k%p;j<=qB_NW-1-k;j+=TWICE(**OOk))
   LOOPN(z,k)
    WHEN((z+j)/TWICE(p) IS (z+j+*Ok)/TWICE(p))
    BEGIN qB_nwa[qB_nwn]=(qBc)(z+j);qB_nwb[qB_nwn]=(qBc)(z+j+**OOk);INCR(qB_nwn); END
END

static qBc qB_bta[256],qB_btb[256];
static int qB_btn=0;
static qBu qB_sct=0u;

/* bitonic, n=32 */
static void qB_mkbit(void)
BEGIN
int k,j,z,l,*const Oj=&j,*const*const OOj=&Oj;
qB_btn=0;
for(k=2;k<=qB_NW;k=TWICE(k))
 for(**OOj=HALF(k);*Oj>0;*Oj=HALF(j))
  LOOPN(z,qB_NW)
  BEGIN
   l=z^*Oj;
   WHEN(l<=z) continue;
   qB_bta[qB_btn]=(qBc)((z&k)?l:z);
   qB_btb[qB_btn]=(qBc)((z&k)?z:l);
   INCR(qB_btn);
  END
END

static void qB_bnet(int*w,int sel)
BEGIN
int z,n,*const Oz=&z,*const*const OOz=&Oz;
int*const Ow=w,*const*const OOw=&Ow;
const qBc*na,*nb,*const*const Ona=&na,*const*const Onb=&nb;
na=sel?qB_nwa:qB_bta;nb=sel?qB_nwb:qB_btb;n=sel?qB_nwn:qB_btn;
LOOPN(**OOz,n)
BEGIN
 WHEN(*(*OOw+*(*Ona+*Oz))>*(Ow+*(*Onb+**OOz))) SWAP2(*(Ow+*(na+z)),*(*OOw+*(nb+z)));
END
END

/* Stein */
static qBu qB_gcd(qBu a,qBu b)
BEGIN
int sh=0;qBu t,*const Oa=&a,*const Ob=&b,*const*const OOb=&Ob;
WHEN(NOT a) RET b;
WHEN(NOT b) RET a;
while(NOT ODD(*Oa|**OOb)) BEGIN a=HALF(a);*Ob=HALF(b);INCR(sh); END
while(NOT ODD(*Oa)) *Oa=HALF(a);
do BEGIN
 while(NOT ODD(**OOb)) b=HALF(*Ob);
 WHEN(a>b) BEGIN t=*Oa;*Oa=b;**OOb=t; END
 *Ob-=a;
END while(b);
RET a<<sh;
END

/* cycle type in S_n; order = lcm of cycle lengths */
static int qB_cyc(const int*a,int n,qBu*ord)
BEGIN
qBu seen=0u,L=1u,*const Os=&seen,*const*const OOs=&Os;int z,y,len;
*ord=0u;
LOOPN(z,n) WHEN((unsigned)*(a+z)>=(unsigned)n) RET 0;
LOOPN(z,n) WHEN(NOT ODD(**OOs>>z))
BEGIN
 len=0;y=z;
 while(NOT ODD(*Os>>y)) BEGIN **OOs|=1u<<y;y=*(a+y);INCR(len); END
 WHEN(y ISNOT z) RET 0;
 L=L/qB_gcd(L,(qBu)len)*(qBu)len;
END
*ord=L;
RET 1;
END

/* pi^e == id ? */
static int qB_pid(const int*a,int n,qBu e)
BEGIN
int r[32],b[32],t[32],z;
LOOPN(z,n) BEGIN r[z]=z;b[z]=*(a+z); END
while(e)
BEGIN
 WHEN(ODD(e)) BEGIN LOOPN(z,n) t[z]=b[r[z]];LOOPN(z,n) r[z]=t[z]; END
 LOOPN(z,n) t[z]=b[b[z]];LOOPN(z,n) b[z]=t[z];
 e=HALF(e);
END
LOOPN(z,n) WHEN(r[z] ISNOT z) RET 0;
RET 1;
END

#define qB_SS(X) X(qB_tA,0x4E1) X(qB_tB,0x13C) X(qB_tC,0x2AF) X(qB_tD,0x37A) X(qB_tE,0x0D5) X(qB_tF,0x1E8)
#define qB_XS(nm,v) nm=v,
enum qB_sse { qB_SS(qB_XS) qB_tZ=0 };
#undef qB_XS

/* Jacobi (a/n), n odd */
static int qB_jac(qBu a,qBu n)
BEGIN
int t=1;qBu r,*const Oa=&a,*const On=&n,*const*const OOn=&On;
*Oa%=n;
while(a)
BEGIN
 while(NOT ODD(*Oa)) BEGIN *Oa=HALF(a);r=**OOn&7u;WHEN(r IS 3u OR r IS 5u) t=-t; END
 r=a;*Oa=n;**OOn=r;
 WHEN((a&3u) IS 3u AND (*On&3u) IS 3u) t=-t;
 *Oa%=**OOn;
END
RET n IS 1u?t:0;
END

/* base-26 by schoolbook long division over base-256 limbs */
static qBu qB_b26c(qBu u)
BEGIN
qBc lb[4],dg[8];int z,n=0;qBu rem,cur,nz,w=0u,*const Ow=&w,*const*const OOw=&Ow;
LOOPN(z,4) lb[z]=(qBc)(u>>(24-TWICE(TWICE(TWICE(z)))));
do BEGIN
 rem=0u;nz=0u;
 LOOPN(z,4) BEGIN cur=(rem<<8)|lb[z];lb[z]=(qBc)(cur/(qBu)M);rem=cur-(qBu)M*lb[z];nz|=lb[z]; END
 dg[n]=(qBc)rem;INCR(n);
END while(nz);
while(n) BEGIN n--;**OOw=*Ow*(qBu)M+dg[n]; END
RET w;
END

/* GF(257): 4th roots of unity, Lagrange basis */
#define qB_LD 4
static qBu qB_lx[qB_LD],qB_lc[qB_LD][qB_LD];
static int qB_lok=0;

static void qB_b_lag(void)
BEGIN
qBu g,w,nm[qB_LD+1],dn,iv,t;int z,y,k,ok=1;
for(g=2u;g<qB_NP;INCR(g)) WHEN(qB_pw64(g,HALF(qB_NP-1u),qB_NP) ISNOT 1u) break;
w=qB_pw64(g,(qB_NP-1u)/qB_LD,qB_NP);
LOOPN(z,qB_LD) qB_lx[z]=qB_pw64(w,(qBu)z,qB_NP);
LOOPN(z,qB_LD)
BEGIN
 LOOPN(k,qB_LD+1) nm[k]=0u;
 nm[0]=1u;dn=1u;
 LOOPN(y,qB_LD) WHEN(y ISNOT z)
 BEGIN
  for(k=qB_LD;k>0;k--) nm[k]=(nm[k-1]+(qB_NP-qB_lx[y])*nm[k])%qB_NP;
  nm[0]=((qB_NP-qB_lx[y])*nm[0])%qB_NP;
  dn=(dn*((qB_lx[z]+qB_NP-qB_lx[y])%qB_NP))%qB_NP;
 END
 iv=qB_pw64(dn,qB_NP-2u,qB_NP);
 WHEN((dn*iv)%qB_NP ISNOT 1u) ok=0;
 LOOPN(k,qB_LD) qB_lc[z][k]=(nm[k]*iv)%qB_NP;
END
LOOPN(y,qB_LD) LOOPN(k,qB_LD)
BEGIN
 t=0u;
 LOOPN(z,qB_LD) t=(t+qB_lc[z][k]*qB_pw64(qB_lx[z],(qBu)y,qB_NP))%qB_NP;
 WHEN(t ISNOT (qBu)(y IS k)) ok=0;
END
qB_lok=ok;
END

/* bytes -> values of a cubic at the 4th roots of unity -> Lagrange back */
static qBu qB_lag(qBu u)
BEGIN
qBu c[qB_LD],v[qB_LD],t,*const Oc=c,*const Ov=v,*const*const OOv=&Ov;int z,k;
WHEN(NOT qB_lok) RET u;
LOOPN(z,qB_LD) *(Oc+z)=(u>>TWICE(TWICE(TWICE(z))))&0xFFu;
LOOPN(z,qB_LD)
BEGIN
 *(*OOv+z)=0u;
 for(k=qB_LD-1;k>=0;k--) *(Ov+z)=(*(Ov+z)*qB_lx[z]+*(Oc+k))%qB_NP;
END
LOOPN(k,qB_LD)
BEGIN
 t=0u;
 LOOPN(z,qB_LD) t=qB_MADD(t,*(*OOv+z)*qB_lc[z][k]);
 *(Oc+k)=t%qB_NP;
END
t=0u;
for(k=qB_LD-1;k>=0;k--) t=qB_MOR(t<<8,*(Oc+k));
RET t;
END

/* Z/2^16 x Z/(2^16+1), Garner */
#define qB_F4 65537u
static qBu qB_f4i=0u;
static int qB_f4ok=0;

static void qB_b_f4(void)
BEGIN
qB_f4i=qB_pw64(qB_LO16+qB_ONE,qB_F4-2u,qB_F4);
qB_f4ok=(qB_mr(qB_F4) AND ((qBw)qB_f4i*(qBw)(qB_F4-1u))%qB_F4 IS 1u);
END

static qBu qB_fcr(qBu u)
BEGIN
qBu a=u&qB_LO16,b=u>>qB_W16,t,*const Ob=&b,*const*const OOb=&Ob;
WHEN(NOT qB_f4ok) RET u;
**OOb=qB_CSUB(a+(qB_F4-*Ob),qB_F4);
t=(qBu)((((qBw)qB_MSUB(*Ob+qB_F4,a)%qB_F4)*qB_f4i)%qB_F4);
RET qB_MADD(a,t<<qB_W16);
END

/* roundtrip bytecode */
#define qB_OPS(X) X(qB_oFE,0x51) X(qB_oMK,0x2E) X(qB_oDC,0x7B) X(qB_oMI,0x13) X(qB_oFD,0x6C) X(qB_oJQ,0x45) X(qB_oJP,0x3D) X(qB_oBX,0x6A)                   X(qB_oLA,0x29) X(qB_oFC,0x58) X(qB_oJF,0x77) X(qB_oNG,0x1F) X(qB_oHL,0x00)
#define qB_XO(nm,v) nm=v,
enum qB_ope { qB_OPS(qB_XO) qB_oNN=0xFF };
#undef qB_XO
#define qB_JPRIME 65521u
static const qBc qB_rtp[]={qB_oFE,qB_oJQ,6,qB_oBX,qB_oJP,15,qB_oMK,qB_oLA,qB_oJF,11,qB_oNG,qB_oDC,qB_oFC,qB_oBX,qB_oMI,qB_oFD,qB_oHL};

static qBu qB_vm(const qBc*pc,qBu acc)
BEGIN
const qBc*const p0=pc;
qBu*const Oa=&acc,*const*const OOa=&acc==Oa?&Oa:0,h;
FOREVER switch(*pc++)
BEGIN
 case qB_oFE: **OOa=qB_fe(*Oa,1);break;
 case qB_oMK: *Oa*=qB_K;break;
 case qB_oDC: **OOa=qB_dc(**OOa);break;
 case qB_oMI: **OOa*=qB_Ki;break;
 case qB_oFD: *Oa=qB_fe(**OOa,-1);break;
 case qB_oBX: *Oa=qB_b26c(*Oa);break;
 case qB_oJQ: h=*Oa&qB_LO16;pc=qB_jac((h*h)%qB_JPRIME,qB_JPRIME)+1?p0+*pc:pc+1;break;
 case qB_oJP: pc=p0+*pc;break;
 case qB_oLA: *Oa=qB_lag(**OOa);break;
 case qB_oFC: **OOa=qB_fcr(*Oa);break;
 case qB_oNG: *Oa=0u-*Oa;break;
 case qB_oJF: h=*Oa&qB_LO16;pc=qB_pw(h,M/TWICE(qB_ONE),M/TWICE(qB_ONE)) IS h%(qBu)(M/TWICE(qB_ONE))?p0+*pc:pc+1;break;
 default: RET acc;
END
END

#endif
