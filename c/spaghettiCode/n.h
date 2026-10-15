#ifndef qC_NUMTH_H
#define qC_NUMTH_H
#include "c.h"
#include <stdint.h>

typedef uint32_t qCu32;
typedef uint64_t qCu64;

#define qC_P61 2305843009213693951ULL           /* 2^61-1 */
#define qC_M61 0x1fffffffffffffffULL
#define qC_FNV0 2166136261u
#define qC_FNVP 16777619u
#define qC_NP 12289u                            /* 3*2^12+1 */
#define qC_NLG 12

/* 64x64 -> mod (2^61-1), 32-bit limbs */
static qCu64 qCmm61(qCu64 a,qCu64 b)
BEGIN
qCu64 a0=a&0xffffffffULL,a1=a>>32,b0=b&0xffffffffULL,b1=b>>32;
qCu64 p00=a0*b0,p01=a0*b1,p10=a1*b0,p11=a1*b1;
qCu64 mid,lo,hi,cmid,c1,r;
mid=p01+p10;cmid=(mid<p01)?1ULL:0ULL;
lo=p00+(mid<<32);c1=(lo<p00)?1ULL:0ULL;
hi=p11+(mid>>32)+(cmid<<32)+c1;
r=(lo&qC_P61)+(((hi<<3)|(lo>>61))&qC_M61)+((hi>>61)<<3);
r=(r&qC_P61)+(r>>61);
r=(r&qC_P61)+(r>>61);
WHEN(r>=qC_P61) r-=qC_P61;
RET r;
END

static qCu64 qCadd61(qCu64 a,qCu64 b)
BEGIN qCu64 r=a+b; r=(r&qC_P61)+(r>>61); WHEN(r>=qC_P61) r-=qC_P61; RET r; END

/* MBA: x+y==(x^y)+2(x&y); x-y==(x^~y)+2(x&~y)+1; x^y==(x|y)-(x&y) (mod 2^32) */
static qCu32 qCmbaA(qCu32 x,qCu32 y) BEGIN RET (qCu32)((x^y)+((x&y)<<1)); END
static qCu32 qCmbaS(qCu32 x,qCu32 y) BEGIN RET (qCu32)((x^~y)+((x&~y)<<1)+1u); END
static qCu32 qCmbaX(qCu32 x,qCu32 y) BEGIN RET (qCu32)((x|y)-(x&y)); END

/* Newton-Hensel: a*x==1 (mod 2^32), a odd; 3->6->12->24->48 bits */
static qCu32 qCninv(qCu32 a)
BEGIN
qCu32 x=a;
x=x*(2u-a*x);
x=x*(2u-a*x);
x=x*(2u-a*x);
x=x*(2u-a*x);
x=x*(2u-a*x);
RET x;
END

/* E(x)=A*x+B, D(y)=A^-1*(y-B) over Z/2^32 */
#define qC_AFA 2654435761u
#define qC_AFB 1013904223u
static qCu32 qCaffE(qCu32 x) BEGIN RET qCmbaA(x*qC_AFA,qC_AFB); END
static qCu32 qCaffD(qCu32 y) BEGIN RET qCninv(qC_AFA)*qCmbaS(y,qC_AFB); END

#define qC_A8 181u
#define qC_B8 97u
static unsigned qCaff8E(unsigned x) BEGIN RET (unsigned)((x*qC_A8+qC_B8)&0xffu); END
static unsigned qCninv8(unsigned a)
BEGIN unsigned x=a; x=(x*(2u-a*x))&0xffu; x=(x*(2u-a*x))&0xffu; x=(x*(2u-a*x))&0xffu; RET x&0xffu; END
static unsigned qCaff8D(unsigned y) BEGIN RET (unsigned)((qCninv8(qC_A8)*((y-qC_B8)&0xffu))&0xffu); END

static qCu32 qCgcd(qCu32 a,qCu32 b) BEGIN while(b){ qCu32 t=a%b; a=b; b=t; } RET a; END
static qCu32 qClcm(qCu32 a,qCu32 b) BEGIN WHEN(NOT a OR NOT b) RET 0; RET a/qCgcd(a,b)*b; END

/* a*x+b*y=g */
static long qCeg(long a,long b,long*x,long*y)
BEGIN
long x0=1,x1=0,y0=0,y1=1,q0,t;
while(b){ q0=a/b; t=a-q0*b; a=b; b=t; t=x0-q0*x1; x0=x1; x1=t; t=y0-q0*y1; y0=y1; y1=t; }
*x=x0; *y=y0; RET a;
END

static int qCi2m13=0;
static int qCinv2m13(void)
BEGIN
long x,y;
WHEN(qCi2m13) RET qCi2m13;
qCeg(2,13,&x,&y);
x%=13; WHEN(x<0) x+=13;
qCi2m13=(int)x; RET qCi2m13;
END

/* Z/26 = Z/2 x Z/13 */
static int qCcrt26(int r2,int r13)
BEGIN
int r;
r2=((r2%2)+2)%2; r13=((r13%13)+13)%13;
r=(13*r2*1 + 2*r13*qCinv2m13());
r%=26; WHEN(r<0) r+=26; RET r;
END

/* a^e mod m, m<2^32 */
static qCu32 qCpowm(qCu32 a,qCu32 e,qCu32 m)
BEGIN
qCu64 r=1u%m,b=a%m;
while(e) BEGIN WHEN(e&1u) r=(r*b)%m; b=(b*b)%m; e>>=1; END
RET (qCu32)r;
END

/* Miller-Rabin, deterministic below 2^32 for witnesses {2,7,61} */
static int qCmr(qCu32 n)
BEGIN
static const qCu32 wv[3]={2u,7u,61u};
qCu32 d,x;int s,r,t;
WHEN(n<2u) RET 0;
WHEN(n<4u) RET 1;
WHEN(NOT(n&1u)) RET 0;
d=n-1u;s=0;
while(NOT(d&1u)) BEGIN d>>=1; s++; END
LOOPN(t,3)
BEGIN
 WHEN(wv[t]%n IS 0u) continue;
 x=qCpowm(wv[t],d,n);
 WHEN(x IS 1u OR x IS n-1u) continue;
 for(r=1;r<s;r++) BEGIN x=(qCu32)(((qCu64)x*x)%n); WHEN(x IS n-1u) break; END
 WHEN(r>=s) RET 0;
END
RET 1;
END

static qCu32 qCnextprime(qCu32 n) BEGIN while(NOT qCmr(n)) n++; RET n; END

/* GF(13)^* = <g>, Zech: 1+g^n = g^Z(n) */
static int qCg13=0,qClg13[13],qCex13[2*qC_NLG],qCzc13[qC_NLG];
static void qCgf13_build(void)
BEGIN
qCu32 g;int z,v;
WHEN(qCg13) RET;
for(g=2u;g<13u;g++) BEGIN WHEN(qCpowm(g,6u,13u) ISNOT 1u AND qCpowm(g,4u,13u) ISNOT 1u) break; END
qCex13[0]=1;
for(z=1;z<2*qC_NLG;z++) qCex13[z]=(int)(((qCu32)qCex13[z-1]*g)%13u);
qClg13[0]=-1;
LOOPN(z,qC_NLG) qClg13[qCex13[z]]=z;
LOOPN(z,qC_NLG) BEGIN v=(1+qCex13[z])%13; qCzc13[z]=v?qClg13[v]:-1; END
qCg13=(int)g;
END

static int qCzadd13(int a,int b)
BEGIN
int la,lb,d,zc;
qCgf13_build();
WHEN(a IS 0) RET b;
WHEN(b IS 0) RET a;
la=qClg13[a]; lb=qClg13[b];
d=lb-la; WHEN(d<0) d+=qC_NLG;
zc=qCzc13[d];
WHEN(zc<0) RET 0;
RET qCex13[la+zc];
END

/* (a+b) mod 26: Z/2 by xor, GF(13) by Zech, CRT */
static int qCadd26(int a,int b)
BEGIN
int r2,a13,b13;
r2=(int)(((qCu32)a^(qCu32)b)&1u);
a13=a%13; WHEN(a13<0) a13+=13;
b13=b%13; WHEN(b13<0) b13+=13;
RET qCcrt26(r2,qCzadd13(a13,b13));
END

/* x(x+1), QR mod 7, Euler mod 13, Legendre mod 61 */
static int qCop_even(qCu32 x) BEGIN RET (int)(((x*x+x)&1u)==0u); END
static int qCop_qr7(qCu32 x,qCu32 y) BEGIN qCu32 xr=x%7u,yr=y%7u; RET (int)(((xr*xr)%7u)!=((7u*((yr*yr)%7u)+6u)%7u)); END
static int qCop_tri(qCu32 n) BEGIN RET (int)((((n*(n+1u))>>1)*2u)==(n*n+n)); END
static int qCop_eul(qCu32 x) BEGIN qCu32 y=x%13u; RET (int)(qCpowm((y*y)%13u,6u,13u)<=1u); END

/* Jacobi (a|n), n odd */
static int qCjac(qCu32 a,qCu32 n)
BEGIN
int t=1;qCu32 r;
a%=n;
while(a)
BEGIN
 while(NOT(a&1u)) BEGIN a>>=1; r=n&7u; WHEN(r IS 3u OR r IS 5u) t=-t; END
 r=a; a=n; n=r;
 WHEN((a&3u) IS 3u AND (n&3u) IS 3u) t=-t;
 a%=n;
END
RET (n IS 1u)?t:0;
END
static int qCop_jac(qCu32 x) BEGIN qCu32 y=x%61u; RET qCjac((y*y)%61u,61u)>=0; END

static qCu32 qCfnv(const char*p,int n)
BEGIN
qCu32 h=qC_FNV0; int z;
LOOPN(z,n) BEGIN h^=(qCu32)(unsigned char)p[z]; h*=qC_FNVP; END
RET h;
END

/* CRC-32, reflected 0xEDB88320 */
static qCu32 qCcrct[256];
static int qCcrc_ok=0;
static qCu32 qCcrc(const char*p)
BEGIN
qCu32 c,z,b;
WHEN(NOT qCcrc_ok)
BEGIN
 LOOPN(z,256u) BEGIN c=z; LOOPN(b,8u) c=(c&1u)?(0xEDB88320u^(c>>1)):(c>>1); qCcrct[z]=c; END
 qCcrc_ok=1;
END
c=0xFFFFFFFFu;
while(*p) BEGIN c=qCcrct[(c^(qCu32)(unsigned char)*p)&0xffu]^(c>>8); INCR(p); END
RET c^0xFFFFFFFFu;
END

/* h = sum p[z]*B^(n-1-z) mod 2^61-1, B = first prime >= 10^6 */
static qCu64 qChb=0;
static qCu64 qCroll(const int*p,int n)
BEGIN
qCu64 h=0; int z;
WHEN(NOT qChb) qChb=(qCu64)qCnextprime(1000000u);
LOOPN(z,n) h=qCadd61(qCmm61(h,qChb),(qCu64)((unsigned)(p[z]&0xff)));
RET h;
END

/* Berlekamp-Massey over GF(2): s[0..n) -> C(x), deg L; n<64 */
static int qCbm(const unsigned char*s,int n,unsigned char*c)
BEGIN
unsigned char b[64],t[64];int L=0,m=-1,i,j,d;
LOOPN(i,n+1) BEGIN c[i]=0; b[i]=0; END
c[0]=1; b[0]=1;
LOOPN(i,n)
BEGIN
 d=s[i];
 for(j=1;j<=L;j++) d^=c[j]&s[i-j];
 WHEN(d)
 BEGIN
  LOOPN(j,n+1) t[j]=c[j];
  for(j=0;j+i-m<=n;j++) c[j+i-m]^=b[j];
  WHEN(2*L<=i) BEGIN L=i+1-L; m=i; LOOPN(j,n+1) b[j]=t[j]; END
 END
END
RET L;
END

/* keystream: 2L seed bits -> BM -> LFSR -> bytes */
#define qC_KSN 22
#define qC_KSEED 0xb6b2u
static unsigned char qCks[qC_KSN];
static int qCks_ok=0;
static void qCks_build(void)
BEGIN
unsigned char s[8*qC_KSN],c[17];int L,z,j,v;
WHEN(qCks_ok) RET;
LOOPN(z,16) s[z]=(unsigned char)((qC_KSEED>>z)&1u);
L=qCbm(s,16,c);
for(z=16;z<8*qC_KSN;z++) BEGIN v=0; for(j=1;j<=L;j++) v^=c[j]&s[z-j]; s[z]=(unsigned char)v; END
LOOPN(z,qC_KSN) BEGIN v=0; LOOPN(j,8) v|=s[8*z+j]<<j; qCks[z]=(unsigned char)v; END
qCks_ok=1;
END

/* ---- S_26 ---- */
static void qCperm_inv(const int*m,int*inv)
BEGIN
int seen[26],i,j,prev;
LOOP26(i) BEGIN seen[i]=0; inv[i]=i; END
LOOP26(i)
BEGIN
 WHEN(seen[i]) continue;
 prev=i; j=m[i];
 while(NOT seen[prev]) BEGIN seen[prev]=1; inv[m[prev]]=prev; prev=j; j=m[j]; END
END
END

static int qCperm_ord(const int*m)
BEGIN
int seen[26],i,j,len,ord=1;
LOOP26(i) seen[i]=0;
LOOP26(i)
BEGIN
 WHEN(seen[i]) continue;
 len=0; j=i;
 while(NOT seen[j]) BEGIN seen[j]=1; j=m[j]; len++; END
 ord=(int)qClcm((qCu32)ord,(qCu32)len);
END
RET ord;
END

/* cycle type: sum cnt[len]*27^len (mod 2^32) */
static qCu32 qCperm_ctype(const int*m)
BEGIN
int seen[26],cnt[27],i,j,len;qCu32 h=0u;
LOOP26(i) seen[i]=0;
LOOPN(i,27) cnt[i]=0;
LOOP26(i)
BEGIN
 WHEN(seen[i]) continue;
 len=0; j=i;
 while(NOT seen[j]) BEGIN seen[j]=1; j=m[j]; len++; END
 INCR(cnt[len]);
END
for(i=26;i>=1;i--) h=qCmbaA(h*27u,(qCu32)cnt[i]);
RET h;
END

static void qCperm_compose(const int*a,const int*b,int*out)
BEGIN int i; LOOP26(i) out[i]=a[b[i]]; END

static void qCperm_pow(const int*m,int e,int*out)
BEGIN
int bs[26],ac[26],tw[26],i;
LOOP26(i) BEGIN ac[i]=i; bs[i]=m[i]; END
while(e>0)
BEGIN
 WHEN(e&1) BEGIN qCperm_compose(ac,bs,tw); LOOP26(i) ac[i]=tw[i]; END
 e>>=1;
 WHEN(e) BEGIN qCperm_compose(bs,bs,tw); LOOP26(i) bs[i]=tw[i]; END
END
LOOP26(i) out[i]=ac[i];
END

/* sigma = (0 1 ... 25); qCsig[k] = sigma^k */
static int qCsig[26][26];
static int qCsig_ok=0;
static void qCsig_build(void)
BEGIN
int cy[26],z;
WHEN(qCsig_ok) RET;
LOOP26(z) cy[z]=(z+1)%26;
LOOP26(z) qCperm_pow(cy,z,qCsig[z]);
qCsig_ok=1;
END

/* sigma^-o . pi . sigma^o */
static void qCperm_conj(const int*pi,int o,int*out)
BEGIN
int tw[26];
qCsig_build();
o=((o%26)+26)%26;
qCperm_compose(pi,qCsig[o],tw);
qCperm_compose(qCsig[(26-o)%26],tw,out);
END

/* ---- NTT over GF(12289) ---- */
#define qC_NMAX 256
#define qC_NHLF (qC_NMAX>>1)
static qCu32 qCnW[qC_NHLF],qCnWi[qC_NHLF],qCnli[qC_NLG+1];
static int qCnt_ok=0;
static void qCnt_build(void)
BEGIN
qCu32 g,w,wi;int s;
WHEN(qCnt_ok) RET;
for(g=2u;g<qC_NP;g++) BEGIN WHEN(qCpowm(g,(qC_NP-1u)/2u,qC_NP) ISNOT 1u AND qCpowm(g,(qC_NP-1u)/3u,qC_NP) ISNOT 1u) break; END
w=qCpowm(g,(qC_NP-1u)/(qCu32)qC_NMAX,qC_NP);
wi=qCpowm(w,qC_NP-2u,qC_NP);
qCnW[0]=1u; qCnWi[0]=1u;
for(s=1;s<qC_NHLF;s++) BEGIN qCnW[s]=(qCnW[s-1]*w)%qC_NP; qCnWi[s]=(qCnWi[s-1]*wi)%qC_NP; END
for(s=0;s<=qC_NLG;s++) qCnli[s]=qCpowm(1u<<s,qC_NP-2u,qC_NP);
qCnt_ok=1;
END

static void qCntt(qCu32*a,int n,int lg,int inv)
BEGIN
int i,j,h,s,k,hl,sd;qCu32 u,v,t;const qCu32*W=inv?qCnWi:qCnW;
for(i=1,j=0;i<n;i++)
BEGIN
 for(h=n>>1;j&h;h>>=1) j^=h;
 j^=h;
 WHEN(i<j) BEGIN t=a[i];a[i]=a[j];a[j]=t; END
END
for(s=1;s<=lg;s++)
BEGIN
 hl=1<<(s-1); sd=qC_NHLF>>(s-1);
 for(i=0;i<n;i+=hl<<1)
 BEGIN
  LOOPN(k,hl)
  BEGIN
   u=a[i+k]; v=(a[i+k+hl]*W[k*sd])%qC_NP;
   t=u+v; WHEN(t>=qC_NP) t-=qC_NP; a[i+k]=t;
   t=u+qC_NP-v; WHEN(t>=qC_NP) t-=qC_NP; a[i+k+hl]=t;
  END
 END
END
WHEN(inv) BEGIN LOOPN(i,n) a[i]=(a[i]*qCnli[lg])%qC_NP; END
END

/* D[k]=sum_z (t[k+z]-p[z])^2 mod 12289, exact while D<12289; t,p in [0,25].
   m==1: spectrum of a delta is flat. */
static int qCntt_sqd(const int*t,int n,const int*p,int m,int*D)
BEGIN
qCu32 A[qC_NMAX],B[qC_NMAX],C[qC_NMAX],E[qC_NMAX],pp=0u;int L=1,lg=0,z;
WHEN(m<1 OR n<m) RET 0;
while(L<n+m) BEGIN L<<=1; lg++; END
WHEN(L>qC_NMAX) RET -1;
qCnt_build();
LOOPN(z,L)
BEGIN
 A[z]=z<n?(qCu32)t[z]:0u; C[z]=(A[z]*A[z])%qC_NP;
 B[z]=z<m?(qCu32)p[m-1-z]:0u; E[z]=z<m?1u:0u;
END
LOOPN(z,m) pp=(pp+(qCu32)p[z]*(qCu32)p[z])%qC_NP;
qCntt(A,L,lg,0);qCntt(C,L,lg,0);
WHEN(m IS 1) LOOPN(z,L) BEGIN B[z]=B[0]; E[z]=1u; END
OTHERWISE BEGIN qCntt(B,L,lg,0);qCntt(E,L,lg,0); END
LOOPN(z,L) A[z]=((C[z]*E[z])%qC_NP+(qC_NP-2u)*((A[z]*B[z])%qC_NP))%qC_NP;
qCntt(A,L,lg,1);
LOOPN(z,n-m+1) D[z]=(int)((A[z+m-1]+pp)%qC_NP);
RET n-m+1;
END

#endif
