#ifndef qD_OH
#define qD_OH
#include <stdint.h>
#include <limits.h>
#include "c.h"

#define qD_LC(x) ((unsigned)(((unsigned)(x)*40503u)^0x5BD1u))
#define qD_PB(c) switch(c){case 0u:
#define qD_PY(c) do{(c)=qD_LC(__LINE__);RET 0;case qD_LC(__LINE__):;}while(0)
#define qD_PE(c) }(c)=0u;RET 1;
#define qD_W  (2+2+2+2)
#define qD_FV 2166136261u
#define qD_FP 16777619u
#define qD_PL 0xEDB88320u
#define qD_HB 131u
#define qD_BM 0x2545F491u
#define qD_K8 40320u

static const char*const qD_dcy[qD_W]={"R9 R8 R7","V4","ZZZ","QQQ","","R0 R0 R0 R0","V2","AAAAA"};

static uint32_t qD_crt[256];
static int qD_crk=0;

static void qD_cri(void)
BEGIN
uint32_t c,*const Oc=&c,*const*const OOc=&Oc;int z,w;
WHEN(qD_crk) RET;
LOOPN(z,256) BEGIN **OOc=(uint32_t)z; LOOPN(w,8) *Oc=(*Oc&1u)?(*Oc>>1)^qD_PL:(*Oc>>1); *(qD_crt+z)=**OOc; END
qD_crk=1;
END

static uint32_t qD_crT(uint32_t c,const char*s)
BEGIN
const unsigned char*u=(const unsigned char*)s,*const*const Ou=&u;
qD_cri();
WHEN(*Ou) while(**Ou) BEGIN c=*(qD_crt+((c^**Ou)&0xFFu))^(c>>8);INCR(u); END
RET *(qD_crt+(c&0xFFu))^(c>>8);
END

static uint32_t qD_crB(uint32_t c,const char*s)
BEGIN
const unsigned char*u=(const unsigned char*)s;uint32_t b,m,h,*const Oc=&c,*const*const OOc=&Oc;int w;
for(;;)
BEGIN
 b=(u AND *u)?(uint32_t)*u:0u;
 **OOc=(*Oc|b)-(*Oc&b);
 LOOPN(w,8) BEGIN m=qD_PL&(0u-(**OOc&1u)); h=*Oc>>1; *Oc=(h|m)-(h&m); END
 WHEN(NOT b) break;
 INCR(u);
END
RET c;
END

static uint32_t qD_c4T(const char*const*v) BEGIN uint32_t c=0xFFFFFFFFu;int z; LOOPN(z,4) c=qD_crT(c,*(v+z)); RET ~c; END
static uint32_t qD_c4B(const char*const*v) BEGIN uint32_t c=0xFFFFFFFFu;int z; LOOPN(z,4) c=qD_crB(c,*(v+z)); RET ~c; END

static uint32_t qD_fnv(const char*s)
BEGIN
uint32_t h=qD_FV,*const Oh=&h;
WHEN(s) while(*s) BEGIN *Oh^=(uint32_t)(unsigned char)*s;*Oh*=qD_FP;INCR(s); END
RET h;
END

static uint32_t qD_phH(const char*s)
BEGIN
uint32_t h=0u;
WHEN(s) while(*s) BEGIN h=h*qD_HB+(uint32_t)(unsigned char)*s;INCR(s); END
RET h;
END

static uint32_t qD_phS(const char*s)
BEGIN
uint32_t h=0u,w=1u,*const Ow=&w,*const*const OOw=&Ow;size_t n=0u;
WHEN(NOT s) RET 0u;
while(*(s+n)) INCR(n);
while(n) BEGIN n--; h+=**OOw*(uint32_t)(unsigned char)*(s+n); *Ow*=qD_HB; END
RET h;
END

static uint32_t qD_fac(int n) BEGIN uint32_t f=1u; while(n>1) BEGIN f*=(uint32_t)n;n--; END RET f; END

static void qD_lehm(uint32_t c,int n,unsigned char*pm)
BEGIN
unsigned char av[qD_W],*const Oav=av,*const*const OOav=&Oav;uint32_t f;int z,w,d;
c%=qD_fac(n);
LOOPN(z,n) *(Oav+z)=(unsigned char)z;
LOOPN(z,n)
BEGIN
 f=qD_fac(n-1-z); d=(int)(c/f); c%=f;
 *(pm+z)=*(*OOav+d);
 for(w=d;w<n-1-z;w++) *(Oav+w)=*(*OOav+w+1);
END
END

static uint32_t qD_gcd(uint32_t a,uint32_t b) BEGIN uint32_t t; while(b) BEGIN t=a%b;a=b;b=t; END RET a; END

static void qD_pinv(const unsigned char*pm,int n,unsigned char*iv)
BEGIN
unsigned char sn[qD_W],r[qD_W],t[qD_W];uint32_t od=1u,ln,e;int z,w;
LOOPN(z,n) sn[z]=0;
LOOPN(z,n)
BEGIN
 WHEN(sn[z]) continue;
 ln=0u;w=z;
 do BEGIN sn[w]=1;w=*(pm+w);INCR(ln); END while(w ISNOT z);
 od=od/qD_gcd(od,ln)*ln;
END
LOOPN(z,n) r[z]=(unsigned char)z;
for(e=1u;e<od;e++) BEGIN LOOPN(z,n) t[z]=*(pm+r[z]); LOOPN(z,n) r[z]=t[z]; END
LOOPN(z,n) *(iv+z)=r[z];
END

typedef struct qD_chs {
 unsigned qDlp,qDlc;
 const char*qDit[qD_W];
 const char*qDsl[qD_W];
 unsigned char qDpm[qD_W],qDtm[qD_W],qDiv[qD_W];
 uint32_t qDka,qDkb;
 int qDn,qDk,qDj,qDmd,qDqh,qDqn;
 unsigned char qDqs[2];
 const char*qDqp[2];
} qD_ch_t;

static void qD_chi(qD_ch_t*c,int n,int md,uint32_t ka)
BEGIN
int z;qD_ch_t*const*const Oc=&c;
(**Oc).qDlp=0u;(*Oc)->qDlc=0u;c->qDn=n;c->qDmd=md;c->qDka=ka;c->qDkb=0u;
c->qDk=0;c->qDj=0;c->qDqh=0;c->qDqn=0;
LOOPN(z,qD_W) BEGIN (*Oc)->qDit[z]=*(qD_dcy+z);c->qDsl[z]=0;c->qDpm[z]=0;c->qDtm[z]=0;c->qDiv[z]=0; END
LOOPN(z,2) BEGIN c->qDqs[z]=0;(**Oc).qDqp[z]=0; END
END

static int qD_coP(qD_ch_t*c)
BEGIN
qD_PB(c->qDlp)
 WHEN(NOT c->qDmd) c->qDkb=qD_c4B(c->qDit);
 OTHERWISE c->qDkb=qD_phS(c->qDit[0]);
 qD_lehm(c->qDka,qD_W,c->qDpm);
 for(c->qDk=0;c->qDk<qD_W;INCR(c->qDk))
 BEGIN
  while(c->qDqn>=2) qD_PY(c->qDlp);
  c->qDqs[(c->qDqh+c->qDqn)&1]=c->qDpm[c->qDk];
  c->qDqp[(c->qDqh+c->qDqn)&1]=c->qDit[c->qDk];
  INCR(c->qDqn);
  c->qDit[c->qDk]=*(qD_dcy+(qD_W-1-c->qDk));
 END
qD_PE(c->qDlp)
END

static int qD_coC(qD_ch_t*c)
BEGIN
qD_PB(c->qDlc)
 for(c->qDj=0;c->qDj<qD_W;INCR(c->qDj))
 BEGIN
  while(c->qDqn<=0) qD_PY(c->qDlc);
  c->qDsl[c->qDqs[c->qDqh]]=c->qDqp[c->qDqh];
  c->qDqh^=1;c->qDqn--;
 END
 qD_lehm(c->qDkb,qD_W,c->qDtm);
 qD_pinv(c->qDtm,qD_W,c->qDiv);
 for(c->qDj=0;c->qDj<qD_W;INCR(c->qDj)) WHEN(c->qDiv[c->qDj]<c->qDn) c->qDit[c->qDiv[c->qDj]]=c->qDsl[c->qDj];
qD_PE(c->qDlc)
END

static void qD_pump(qD_ch_t*c)
BEGIN
int dp=0,dc=0,*const Odp=&dp,*const Odc=&dc,*const*const OOdc=&Odc;
while(NOT(*Odp AND **OOdc)) BEGIN WHEN(NOT dp) *Odp=qD_coP(c); WHEN(NOT *Odc) **OOdc=qD_coC(c); END
END

static uint32_t qD_frf(uint32_t x,uint32_t k) BEGIN RET ((x*0x9E37u+k)^(x>>5))&0xFFFFu; END
static uint32_t qD_fe(uint32_t v,uint32_t k)
BEGIN
uint32_t l=v>>16,r=v&0xFFFFu,t;int z;
LOOPN(z,4) BEGIN t=r;r=l^qD_frf(r,k+(uint32_t)z*0x3C6Fu);l=t; END
RET (l<<16)|r;
END
static uint32_t qD_fd(uint32_t v,uint32_t k)
BEGIN
uint32_t l=v>>16,r=v&0xFFFFu,t;int z;
for(z=3;z>=0;z--) BEGIN t=l;l=r^qD_frf(l,k+(uint32_t)z*0x3C6Fu);r=t; END
RET (l<<16)|r;
END
static uint32_t qD_hns(uint32_t a) BEGIN uint32_t x=a;int z; LOOPN(z,5) x*=2u-a*x; RET x; END
static uint32_t qD_i2u(int v) BEGIN RET (uint32_t)v; END
static int qD_u2i(uint32_t u) BEGIN WHEN(u<=(uint32_t)INT_MAX) RET (int)u; RET -(int)(~u)-1; END

#ifndef NO_ENGINE_MAIN
#include <setjmp.h>
#define qD_NBJ 16
#define qD_NLG 10
#define qD_NCR 9
#define qD_NMS 11
#define qD_NBL 135
static const unsigned char qD_ntA[74]={
 0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x72,0xAA,0x5F,0xDD,0xED,0x3A,0x5F,0xC1,0x27,
 0xA9,0x24,0x4E,0x02,0x05,0xD7,0xA3,0x4D,0x9C,0xD6,0x48,0x43,0x35,0x1E,0x0F,0xB5,
 0xF3,0x2B,0xC4,0xFD,0x93,0x08,0x66,0xA6,0xDE,0x91,0xD4,0x4E,0xB0,0x2D,0x80,0xC8,
 0x3C,0x8D,0xF2,0x91,0x60,0x3C,0xFF,0x27,0x8D,0xB6,0x02,0x00,0x00,0x56,0x46,0x0B,
 0x00,0x00,0xFF,0x9A,0x6D,0xCF,0x81,0x17,0x00,0x00
};
static const unsigned char qD_ntO[16]={
 0,1,2,3,4,5,6,32,59,60,61,64,
 65,66,72,73
};
static const unsigned char qD_ntC[16]={
 1,1,1,1,1,1,26,27,1,1,3,1,
 1,6,1,1
};
static const unsigned char qD_ntR[80]={
 0xB5,0x1D,0x00,0x00,0x00,0xBF,0x02,0x00,0x00,0x00,0x77,0x40,0x07,0x00,0x00,
 0x35,0xD4,0x14,0x00,0x00,0xE5,0x1F,0x00,0x00,0x00,0x82,0x3B,0x00,0x00,0x00,
 0x19,0x21,0x37,0x1D,0x60,0x6D,0x87,0x80,0x70,0x7F,0x67,0x1D,0x00,0x00,0x00,
 0x1C,0x41,0x00,0x00,0x00,0xA0,0x4F,0x9F,0xAE,0x30,0xC1,0x1A,0x01,0x00,0x00,
 0x67,0x47,0x00,0x00,0x00,0x03,0x4D,0x61,0x9E,0x97,0x02,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00
};
static const unsigned char qD_ntB[5]={
 0xC3,0x1F,0x95,0x3D,0xA7
};
static const uint16_t qD_lgY[92]={
 5595,63792,61566,28326,10891,51223,7306,1720,61642,60273,
 59815,46013,43687,46186,18976,58793,30505,63714,52088,50682,
 24063,49264,1730,11982,36000,15760,48239,62784,24090,34960,
 52185,45469,20301,17469,1818,2701,59491,64229,64042,2392,
 29553,30684,49845,56024,34018,22983,46001,30308,44157,23273,
 47694,57778,58067,18151,19013,8331,29440,21444,47330,43459,
 7716,40653,39358,41836,23745,41416,16620,33827,43619,25215,
 56601,3715,24092,62347,2138,57334,29572,2364,49600,42247,
 20937,20523,39708,6171,26721,41817,54617,47145,61962,60760,
 39333,40181
};
static const unsigned char qD_lgO[10]={
 0,8,10,18,20,37,45,50,61,63
};
static const unsigned char qD_lgC[10]={
 8,2,8,2,17,8,5,11,2,29
};
static const uint16_t qD_crP[19]={
 0x018,0x1F2,0x018,0x203,0x018,0x00C,0x018,0x050,0x018,0x099,0x018,0x0E2,
 0x018,0x221,0x0F1,0x212,0x0D9,0x090,0x16B
};
static const unsigned char qD_crO[9]={
 0,2,4,6,8,10,12,14,16
};
static const unsigned char qD_crC[9]={
 2,2,2,2,2,2,2,2,3
};
static const uint32_t qD_msS[2]={
 0xC0DE1A5Du,0xE40FB9F3u
};
static const unsigned char qD_msE[135]={
 0x0B,0x84,0x18,0xA9,0x7C,0x4C,0xD5,0x1C,0x57,0x9D,0x2C,0xB2,0x2C,0x39,0x0D,0xF4,
 0x4E,0xBD,0xE1,0xAB,0x0F,0x25,0x55,0x56,0x40,0xE1,0x13,0x29,0x4E,0x86,0xFF,0x6F,
 0xD8,0x96,0x02,0x7A,0x0A,0xAC,0x59,0x76,0x93,0x94,0x3A,0x2E,0x0C,0x7E,0x64,0x77,
 0x21,0x94,0x78,0xA2,0x67,0x86,0x5A,0x05,0x35,0xD3,0x94,0x80,0x70,0x21,0x5B,0xAC,
 0x75,0x76,0x40,0x41,0x7F,0xE8,0x8D,0xBC,0xE2,0x1D,0x8B,0x55,0xFE,0xA6,0x7F,0x21,
 0x92,0xD9,0x52,0x6A,0x67,0x14,0x6B,0x62,0x2A,0xC8,0x71,0xB4,0x4C,0x1E,0xDA,0x0B,
 0x25,0x59,0xD5,0x48,0xFE,0x7E,0x93,0xF7,0xAE,0x0B,0x3C,0x59,0x9B,0x33,0x97,0x44,
 0x1E,0x49,0x14,0x3C,0xC8,0xFE,0x08,0x9F,0x23,0x31,0xC0,0x0C,0x30,0xE2,0xA6,0x10,
 0xE2,0xF3,0x1F,0xBB,0xA9,0x69,0x65
};
static const unsigned char qD_msO[11]={
 0,10,22,35,48,58,81,114,120,128,132
};
static const unsigned char qD_phT[16]={
 0,2,0,6,7,1,5,0,0,0,4,0,0,3,0,0
};
static const unsigned char qD_dfT[81]={
 0x22,0xC4,0x08,0x23,0x36,0xAC,0x41,0xC9,0x3B,
 0x01,0xF1,0x21,0x01,0x51,0x51,0x61,0x41,0x49,
 0x91,0xD1,0x81,0x11,0x81,0xA1,0x61,0x21,0x19,
 0x81,0x31,0xD1,0xE1,0xD1,0x51,0xC1,0x31,0x69,
 0x91,0x01,0xA1,0xB1,0x81,0x61,0xD1,0x61,0xE9,
 0x71,0xD1,0x81,0x81,0x91,0x61,0x11,0x41,0xB9,
 0x21,0xE1,0x01,0xF1,0xD1,0x31,0x31,0xB1,0x19,
 0x8B,0x9B,0xDB,0x9B,0x6B,0xEB,0x0B,0x5B,0x2B,
 0x29,0x89,0xD9,0x39,0x89,0x39,0xD9,0x49,0x79
};
static const unsigned char qD_dfA[81]={
 1,4,1,0,2,3,3,6,2,
 4,6,2,0,5,0,1,3,3,
 6,4,0,7,5,1,3,6,1,
 3,1,0,7,5,1,6,4,3,
 5,0,5,4,6,7,0,2,2,
 0,2,6,4,1,4,5,7,3,
 2,0,4,3,1,5,7,2,1,
 0,2,3,4,6,2,5,7,3,
 1,4,1,0,2,3,4,6,2
};
#define qD_TDK 0x32FACFF8u
#define qD_PHS 0xE9C9D5B8u
static const uint32_t qD_tdR[24]={
 0x000000A2u,0xD520B32Fu,0x19AE04F2u,
 0x000000A3u,0xB8CBC544u,0x759F1EDDu,
 0x000000A5u,0x5ECC14D1u,0x4F8BAAF2u,
 0x000000A7u,0x4F5834D4u,0x4F8BA83Bu,
 0x000000A1u,0x0B24C7CEu,0x2F405F66u,
 0x000000A6u,0x41AAB9F6u,0x4F8BA85Cu,
 0x000000A0u,0xF7A5F217u,0xB628F5E7u,
 0x000000A4u,0x577E0493u,0x4F8BAA16u
};
static const unsigned char qD_snw[38]={
 0,1,2,3,4,5,6,7,0,2,1,3,4,6,5,7,1,2,5,6,0,4,1,5,2,6,3,7,2,4,3,5,1,2,3,4,5,6
};
#define qD_NAT (qD_NBJ+qD_NLG+qD_NCR)
#define qD_NP 998244353u
#define qD_M(k) (qD_mb+*(qD_msO+(k)))
#define qD_ROW(s) ((int)*(qD_l13+((s)&15u)))

static char qD_ab[qD_NAT][64];
static uint32_t qD_tdV[8][3];
static uint32_t qD_phk=0u,qD_tdm=0u;
static char qD_mb[qD_NBL];
static unsigned char qD_l13[16],qD_zch[12];
static int qD_rdy=0;

static uint32_t qD_pw(uint32_t b,uint32_t e,uint32_t m)
BEGIN
uint64_t r=1u%m,x=b%m,*const Or=&r,*const*const OOr=&Or;
while(e) BEGIN WHEN(e&1u) **OOr=*Or*x%m; x=x*x%m; e>>=1; END
RET (uint32_t)r;
END

static int qD_mr(uint32_t n)
BEGIN
static const uint32_t bs[4]={2u,3u,5u,7u};
uint32_t d,x;int s,z,w;
WHEN(n<2u) RET 0;
LOOPN(z,4) BEGIN WHEN(n IS bs[z]) RET 1; WHEN(n%bs[z] IS 0u) RET 0; END
d=n-1u;s=0;
while(NOT(d&1u)) BEGIN d>>=1;INCR(s); END
LOOPN(z,4)
BEGIN
 x=qD_pw(bs[z],d,n);
 WHEN(x IS 1u OR x IS n-1u) continue;
 for(w=1;w<s;w++) BEGIN x=(uint32_t)((uint64_t)x*x%n); WHEN(x IS n-1u) break; END
 WHEN(w>=s) RET 0;
END
RET 1;
END

static void qD_ntt(uint32_t*a,int n,int iv)
BEGIN
int i,j,b,ln,k,h;uint32_t w,wn,u,v,t,*const*const Oa=&a;
for(i=1,j=0;i<n;i++)
BEGIN
 for(b=n>>1;j&b;b>>=1) j^=b;
 j^=b;
 WHEN(i<j) BEGIN t=*(a+i);*(a+i)=*(*Oa+j);*(*Oa+j)=t; END
END
for(ln=2;ln<=n;ln<<=1)
BEGIN
 h=ln>>1;
 w=qD_pw(3u,(qD_NP-1u)/(uint32_t)ln,qD_NP);
 WHEN(iv) w=qD_pw(w,qD_NP-2u,qD_NP);
 for(i=0;i<n;i+=ln)
 BEGIN
  wn=1u;
  LOOPN(k,h)
  BEGIN
   u=*(a+i+k);v=(uint32_t)((uint64_t)*(*Oa+i+k+h)*wn%qD_NP);
   *(a+i+k)=(u+v)%qD_NP;*(*Oa+i+k+h)=(u+qD_NP-v)%qD_NP;
   wn=(uint32_t)((uint64_t)wn*w%qD_NP);
  END
 END
END
WHEN(iv) BEGIN w=qD_pw((uint32_t)n,qD_NP-2u,qD_NP); LOOPN(i,n) *(a+i)=(uint32_t)((uint64_t)*(a+i)*w%qD_NP); END
END

static void qD_bj(int k,char*o)
BEGIN
uint32_t fa[32],fb[32],wl[20],cur,q,r,car,*const Ofa=fa,*const*const OOfa=&Ofa;
unsigned char by[34];int la=*(qD_ntC+k),n=8,z,nl,len=0,nz;
while(n<la+5) n<<=1;
LOOPN(z,n) BEGIN *(Ofa+z)=z<la?(uint32_t)*(qD_ntA+*(qD_ntO+k)+z):0u; fb[z]=z<5?(uint32_t)*(qD_ntB+z):0u; END
qD_ntt(*OOfa,n,0);qD_ntt(fb,n,0);
LOOPN(z,n) *(*OOfa+z)=(uint32_t)((uint64_t)*(Ofa+z)*fb[z]%qD_NP);
qD_ntt(fa,n,1);
car=0u;
LOOPN(z,n+2) BEGIN cur=(z<n?*(Ofa+z):0u)+(z<5?(uint32_t)*(qD_ntR+5*k+z):0u)+car; by[z]=(unsigned char)(cur&0xFFu); car=cur>>8; END
nl=(n+2)>>1;
LOOPN(z,nl) wl[z]=(uint32_t)by[2*z]|((uint32_t)by[2*z+1]<<8);
for(;;)
BEGIN
 nz=0; LOOPN(z,nl) nz|=(wl[z] ISNOT 0u);
 WHEN(NOT nz) break;
 for(z=0;wl[z] IS 0u;z++) wl[z]=0xFFFFu;
 wl[z]--;
 r=0u;
 for(z=nl-1;z>=0;z--) BEGIN cur=(r<<16)|wl[z]; q=(uint32_t)(((uint64_t)cur*165191050u)>>32); r=cur-q*26u; wl[z]=q; END
 *(o+len)=(char)(AA+(int)r);INCR(len);
END
*(o+len)=0;
END

static uint32_t qD_rdc(uint64_t T,uint32_t p,uint32_t pi)
BEGIN
uint32_t m=(uint32_t)(T&0xFFFFFFFFu)*pi;uint64_t t=(T+(uint64_t)m*p)>>32;
RET (uint32_t)(t>=p?t-p:t);
END
#define qD_MM(a,b) qD_rdc((uint64_t)(a)*(uint64_t)(b),p,pi)
#define qD_TO(a) ((uint32_t)(((uint64_t)(a)<<32)%p))

static uint32_t qD_mpw(uint32_t b,uint32_t e,uint32_t p,uint32_t pi)
BEGIN
uint32_t r=qD_TO(1u),*const Or=&r,*const*const OOr=&Or;
while(e) BEGIN WHEN(e&1u) **OOr=qD_MM(*Or,b); b=qD_MM(b,b); e>>=1; END
RET r;
END

static void qD_lag(int k,uint32_t p,char*o)
BEGIN
const uint16_t*y=qD_lgY+*(qD_lgO+k);int L=*(qD_lgC+k),t,j,m;
uint32_t x[32],dv[32],acc,nu,tm,pi=0u-qD_hns(p),*const Onu=&nu,*const*const OOnu=&Onu;
LOOPN(j,L) x[j]=qD_TO((1777u+37u*(uint32_t)j+101u*(uint32_t)k)%p);
LOOPN(j,L)
BEGIN
 **OOnu=qD_TO(1u);
 LOOPN(m,L) WHEN(m ISNOT j) *Onu=qD_MM(*Onu,(x[j]+p-x[m])%p);
 dv[j]=qD_MM(qD_mpw(nu,p-2u,p,pi),qD_TO(*(y+j)));
END
LOOPN(t,L)
BEGIN
 acc=0u;tm=qD_TO((uint32_t)t);
 LOOPN(j,L)
 BEGIN
  *Onu=dv[j];
  LOOPN(m,L) WHEN(m ISNOT j) **OOnu=qD_MM(nu,(tm+p-x[m])%p);
  acc=(acc+*Onu)%p;
 END
 *(o+t)=(char)qD_rdc((uint64_t)acc,p,pi);
END
*(o+L)=0;
END

static int qD_eg(int a,int m)
BEGIN
int r0=a%m,r1=m,s0=1,s1=0,q,t;
while(r1) BEGIN q=r0/r1; t=r0-q*r1;r0=r1;r1=t; t=s0-q*s1;s0=s1;s1=t; END
RET ((s0%m)+m)%m;
END

static void qD_crt3(int k,char*o)
BEGIN
int z,r5,r7,r9,x1,n=*(qD_crC+k);unsigned v;
LOOPN(z,n)
BEGIN
 v=*(qD_crP+*(qD_crO+k)+z);
 r5=(int)(v&7u);r7=(int)((v>>3)&7u);r9=(int)((v>>6)&15u);
 x1=r5+5*((((r7-r5)%7+7)*qD_eg(5,7))%7);
 *(o+z)=(char)(x1+35*((((r9-x1)%9+9)*qD_eg(35,9))%9));
END
*(o+n)=0;
END

static void qD_msg(void)
BEGIN
unsigned char s[64+8*qD_NBL],c[65],b[65],t[65];int L=0,m=1,n,i,d;
LOOPN(n,64) s[n]=(unsigned char)((*(qD_msS+(n>>5))>>(n&31))&1u);
LOOPN(i,65) BEGIN c[i]=0;b[i]=0; END
c[0]=1;b[0]=1;
LOOPN(n,64)
BEGIN
 d=s[n]; for(i=1;i<=L;i++) d^=c[i]&s[n-i];
 WHEN(NOT d) BEGIN INCR(m);continue; END
 WHEN(2*L<=n)
 BEGIN
  LOOPN(i,65) t[i]=c[i];
  for(i=0;i+m<65;i++) c[i+m]^=b[i];
  L=n+1-L;
  LOOPN(i,65) b[i]=t[i];
  m=1;
 END
 OTHERWISE BEGIN for(i=0;i+m<65;i++) c[i+m]^=b[i]; INCR(m); END
END
for(n=64;n<64+8*qD_NBL;n++) BEGIN d=0; for(i=1;i<=L;i++) d^=c[i]&s[n-i]; s[n]=(unsigned char)d; END
LOOPN(n,qD_NBL) BEGIN d=0; LOOPN(i,8) d|=s[64+8*n+i]<<i; *(qD_mb+n)=(char)(*(qD_msE+n)^d); END
END

static int qD_jac(uint32_t a,uint32_t n)
BEGIN
int t=1;uint32_t r,*const Or=&r,*const*const OOr=&Or;
a%=n;
while(a)
BEGIN
 while(NOT(a&1u)) BEGIN a>>=1; **OOr=n&7u; WHEN(*Or IS 3u OR *Or IS 5u) t=-t; END
 *Or=a;a=n;n=**OOr;
 WHEN((a&3u) IS 3u AND (n&3u) IS 3u) t=-t;
 a%=n;
END
RET n IS 1u?t:0;
END

static int qD_seq(const char*a,const char*b)
BEGIN
const char*const*const Oa=&a;
while(**Oa AND *a IS *b) BEGIN INCR(a);INCR(b); END
RET *a IS *b;
END

static int qD_cls(const char*a)
BEGIN
int f=*(qD_phT+((qD_fnv(a)*qD_phk)>>28));
RET (f AND qD_seq(a,qD_ab[qD_NBJ+qD_NLG+f-1]))?f-1:7;
END

static const unsigned char qD_tkT[6]={8,0,3,9,4,1};
static int qD_tok(char*s)
BEGIN
int n=0,st=0,c,e;char**const Os=&s;
for(;;)
BEGIN
 c=(**Os IS 0)?0:((*s IS ' ' OR *s IS ',')?1:2);
 e=*(qD_tkT+st*3+c);
 WHEN(e&8) break;
 WHEN(e&2) INCR(n);
 WHEN(e&4) **Os=0;
 st=e&1;INCR(s);
END
RET n;
END

static jmp_buf qD_jb;
static int qD_ej=0;

static void qD_duff(char*d,const char*s)
BEGIN
size_t n=strlen(s)+1u,k=(n+7u)>>3;
switch(n&7u)
BEGIN
 case 0u: do BEGIN *d++=*s++;
 case 7u: *d++=*s++;
 case 6u: *d++=*s++;
 case 5u: *d++=*s++;
 case 4u: *d++=*s++;
 case 3u: *d++=*s++;
 case 2u: *d++=*s++;
 case 1u: *d++=*s++;
 END while(--k>0u);
END
END

static void qD_srt(void)
BEGIN
uint32_t(*const Ov)[3]=qD_tdV,(*const*const OOv)[3]=&Ov;int z,w,a,b;
LOOPN(z,8) LOOPN(w,3) *(*(Ov+z)+w)=*(qD_tdR+3*z+w)^(w?0u:0xA5u);
LOOPN(z,19)
BEGIN
 a=*(qD_snw+TWICE(z));b=*(qD_snw+TWICE(z)+1);
 WHEN(**(*OOv+a)>**(Ov+b)) LOOPN(w,3) BEGIN *(*(Ov+a)+w)^=*(*(*OOv+b)+w);*(*(Ov+b)+w)^=*(*(Ov+a)+w);*(*(*OOv+a)+w)^=*(*(Ov+b)+w); END
END
END

static void qD_boot(void)
BEGIN
uint32_t p=65535u,e,c;int z;
WHEN(qD_rdy) RET;
while(NOT qD_mr(p)) p--;
LOOPN(z,qD_NBJ) qD_bj(z,qD_ab[z]);
LOOPN(z,qD_NLG) qD_lag(z,p,qD_ab[qD_NBJ+z]);
LOOPN(z,qD_NCR) qD_crt3(z,qD_ab[qD_NBJ+qD_NLG+z]);
qD_msg();
c=0xFFFFFFFFu; LOOPN(z,qD_NAT) c=qD_crT(c,qD_ab[z]); qD_tdm=qD_TDK^~c;
c=0xFFFFFFFFu; LOOPN(z,qD_NMS) c=qD_crT(c,qD_M(z)); qD_phk=qD_PHS^~c;
qD_srt();
LOOPN(z,16) *(qD_l13+z)=0xFFu;
e=1u; LOOPN(z,12) BEGIN *(qD_l13+e)=(unsigned char)z; e=(e<<1)%13u; END
e=1u; LOOPN(z,12) BEGIN c=(1u+e)%13u; *(qD_zch+z)=c?*(qD_l13+c):(unsigned char)12; e=(e<<1)%13u; END
qD_rdy=1;
END
#endif

#endif
