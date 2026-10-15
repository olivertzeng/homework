#ifndef qA_IH
#define qA_IH
#include <stdint.h>
#include "c.h"

typedef uint32_t qAu;
typedef unsigned long long qAw;
typedef long long qAl;
typedef struct qA_mgs { qAu p,ni,r1,r2,g; } qA_mg;

#define qA_MM(c,a,b) qA_rc((c),(qAw)(a)*(qAw)(b))
#define qA_AD(c,a,b) ((a)+(b)>=(c)->p?(a)+(b)-(c)->p:(a)+(b))
#define qA_SB(c,a,b) ((a)>=(b)?(a)-(b):(a)+(c)->p-(b))
#define qA_SH 23
#define qA_TOPC 127u
#define qA_GF0 26u
#define qA_2OPI 0.63661977236758134308
#define qA_PIO2A 1.57079632673412561417e+00
#define qA_PIO2B 6.07710050650619224932e-11
#define qA_BIGA 1048576.0

static qA_mg qA_M1,qA_M2;
static qAu qA_sp=0,qA_sgn=0,qA_i12=0,qA_rdy=0;
static qAu qA_gk=0,qA_crcv=0,qA_lc=0,qA_pv=0,qA_ov=0;
static INT qA_l13[13],qA_e13[12];
static void qA_boot(void);

/* z*o mod 26 by crt(2,13); the GF(13) factor through discrete logs */
#define qA_M13(a,b) ((((a)%13) IS 0 OR ((b)%13) IS 0)?0:qA_e13[(qA_l13[(a)%13]+qA_l13[(b)%13])%12])
#define qA_ZX(a,b) ((13*((a)&(b)&1)+14*qA_M13((a),(b)))%26)

static qAw qA_pw(qAw a,qAw e,qAw m)
BEGIN
qAw r=1u%m,*const Or=&r,*const*const OOr=&Or;
a%=m;
while(e) BEGIN WHEN(e&1u) **OOr=*Or*a%m; a=a*a%m; e>>=1; END
RET **OOr;
END

static INT qA_mr(qAu n)
BEGIN
static const qAu B[4]={2u,3u,5u,7u};
qAu d;INT s,z,r;qAw x,*const Ox=&x,*const*const OOx=&Ox;
WHEN(n<2u) RET 0;
LOOPN(z,4) BEGIN WHEN(n IS B[z]) RET 1; WHEN(n%B[z] IS 0u) RET 0; END
d=n-1u;s=0;while(NOT(d&1u)) BEGIN d>>=1;INCR(s); END
LOOPN(z,4)
BEGIN
 **OOx=qA_pw(B[z],d,n);
 WHEN(*Ox IS 1u OR *Ox IS (qAw)n-1u) continue;
 for(r=1;r<s;r++) BEGIN **OOx=*Ox**Ox%n; WHEN(**OOx IS (qAw)n-1u) break; END
 WHEN(r>=s) RET 0;
END
RET 1;
END

static qAl qA_eg(qAl a,qAl b,qAl*x,qAl*y)
BEGIN
qAl x0=1,y0=0,x1=0,y1=1,q,t;
while(b)
BEGIN
 q=a/b;
 t=a-q*b;a=b;b=t;
 t=x0-q*x1;x0=x1;x1=t;
 t=y0-q*y1;y0=y1;y1=t;
END
*x=x0;*y=y0;
RET a;
END

static qAu qA_iv(qAu a,qAu m)
BEGIN
qAl x,y,*const Ox=&x,*const*const OOx=&Ox;
qA_eg((qAl)(a%m),(qAl)m,*OOx,&y);
**OOx%=(qAl)m;WHEN(*Ox<0) *Ox+=(qAl)m;
RET (qAu)x;
END

static qAu qA_pr(qAu p)
BEGIN
qAu f[16],m=p-1u,q,g;INT nf=0,z;
qAu*const Of=f,*const*const OOf=&Of;
for(q=2u;q*q<=m;q++) WHEN(m%q IS 0u) BEGIN *(*OOf+nf)=q;INCR(nf); while(m%q IS 0u) m/=q; END
WHEN(m>1u) BEGIN *(Of+nf)=m;INCR(nf); END
for(g=2u;g<p;g++)
BEGIN
 LOOPN(z,nf) BEGIN WHEN(qA_pw(g,(p-1u)/ *(*OOf+z),p) IS 1u) break; END
 WHEN(z IS nf) RET g;
END
RET 0u;
END

static qAu qA_hz(qAu p)
BEGIN
qAu x=p;INT z;
LOOPN(z,5) x=x*(2u-p*x);
RET x;
END

static qAu qA_rc(const qA_mg*c,qAw t)
BEGIN
qAu m=(qAu)t*c->ni;
qAw u=(t+(qAw)m*c->p)>>32;
RET (qAu)(u>=c->p?u-c->p:u);
END

static void qA_mi(qA_mg*c,qAu p)
BEGIN
qA_mg*const*const Oc=&c;
(*Oc)->p=p;(**Oc).ni=0u-qA_hz(p);
(*Oc)->r1=(qAu)(((qAw)1u<<32)%p);
(**Oc).r2=(qAu)((qAw)c->r1*c->r1%p);
(*Oc)->g=qA_pr(p);
END

static qAu qA_to(const qA_mg*c,qAu a) BEGIN RET qA_MM(c,a%c->p,c->r2); END

static qAu qA_mp(const qA_mg*c,qAu a,qAu e)
BEGIN
qAu r=c->r1,*const Or=&r;
while(e) BEGIN WHEN(e&1u) *Or=qA_MM(c,*Or,a); a=qA_MM(c,a,a); e>>=1; END
RET r;
END

static qAl qA_gn(qAu r1,qAu r2)
BEGIN
qAw d,h,x,Mw;
d=((qAw)r2+qA_M2.p-(qAw)r1%qA_M2.p)%qA_M2.p;
h=d*qA_i12%qA_M2.p;
x=(qAw)r1+(qAw)qA_M1.p*h;
Mw=(qAw)qA_M1.p*qA_M2.p;
RET x>Mw/2u?-(qAl)(Mw-x):(qAl)x;
END

static qAu qA_gcd(qAu a,qAu b) BEGIN qAu t; while(b) BEGIN t=a%b;a=b;b=t; END RET a; END
static qAu qA_lcm(qAu a,qAu b) BEGIN RET a/qA_gcd(a,b)*b; END

static INT qA_cy(const INT*s,INT n,qAu*ord)
BEGIN
char v[64];INT z,c=0,l,y;qAu o=1u,*const Oo=&o;
LOOPN(z,n) v[z]=0;
LOOPN(z,n)
BEGIN
 WHEN(v[z]) continue;
 l=0;y=z;
 while(y>=0 AND y<n AND NOT v[y]) BEGIN v[y]=1;y=s[y];INCR(l); END
 INCR(c);*Oo=qA_lcm(*Oo,(qAu)l);
END
*ord=o;
RET c;
END

static void qA_pp(const INT*s,INT n,qAu e,INT*o)
BEGIN
INT b[64],t[64],z;
LOOPN(z,n) BEGIN o[z]=z;b[z]=s[z]; END
while(e)
BEGIN
 WHEN(e&1u) BEGIN LOOPN(z,n) t[z]=b[o[z]]; LOOPN(z,n) o[z]=t[z]; END
 LOOPN(z,n) t[z]=b[b[z]];
 LOOPN(z,n) b[z]=t[z];
 e>>=1;
END
END

static qAu qA_ctb[256];static INT qA_ctk=0;
static qAu qA_crc(qAu c,const char*s,INT n)
BEGIN
INT z,k;qAu r;
WHEN(NOT qA_ctk)
BEGIN
 LOOPN(z,256) BEGIN r=(qAu)z; LOOPN(k,8) r=(r&1u)?(r>>1)^0xEDB88320u:(r>>1); qA_ctb[z]=r; END
 qA_ctk=1;
END
c=~c;
LOOPN(z,n) c=qA_ctb[(c^(qAu)(unsigned char)s[z])&0xFFu]^(c>>8);
RET ~c;
END

static void qA_nw(const qAu*x,const qAu*y,INT n,qAu p,qAu*c)
BEGIN
INT i,j;
LOOPN(i,n) c[i]=y[i]%p;
for(j=1;j<n;j++) for(i=n-1;i>=j;i--)
 c[i]=(qAu)((qAw)((c[i]+p-c[i-1])%p)*qA_iv((x[i]+p-x[i-j]%p)%p,p)%p);
END

static qAu qA_ne(const qAu*x,const qAu*c,INT n,qAu p,qAu t)
BEGIN
INT i;qAw r=c[n-1];
for(i=n-2;i>=0;i--) r=(r*(((qAw)t+p-x[i]%p)%p)+c[i])%p;
RET (qAu)r;
END

static INT qA_bm(const qAu*s,INT n,qAu p,qAu*C)
BEGIN
qAu B[40],T[40],d,b=1u,cf;INT L=0,m=1,i,j;
LOOPN(i,n+1) BEGIN C[i]=0u;B[i]=0u; END
C[0]=1u;B[0]=1u;
LOOPN(i,n)
BEGIN
 d=s[i]%p;
 for(j=1;j<=L;j++) d=(qAu)(((qAw)d+(qAw)C[j]*s[i-j])%p);
 WHEN(d IS 0u) BEGIN INCR(m); continue; END
 cf=(qAu)((qAw)d*qA_iv(b,p)%p);
 WHEN(2*L<=i)
 BEGIN
  LOOPN(j,n+1) T[j]=C[j];
  for(j=m;j<=n;j++) C[j]=(qAu)(((qAw)C[j]+p-(qAw)cf*B[j-m]%p)%p);
  L=i+1-L;
  LOOPN(j,n+1) B[j]=T[j];
  b=d;m=1;
 END
 OTHERWISE
 BEGIN
  for(j=m;j<=n;j++) C[j]=(qAu)(((qAw)C[j]+p-(qAw)cf*B[j-m]%p)%p);
  INCR(m);
 END
END
RET L;
END

static double qA_sq(double a)
BEGIN
double x=a>1.0?a:1.0;INT z;
LOOPN(z,64) x=0.5*(x+a/x);
RET x;
END

#endif
