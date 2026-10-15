#ifndef qC_VM_H
#define qC_VM_H
#include "c.h"
#include "n.h"

/* ---- stepping VM ---- */
enum qCop_e {
 qCV_HALT=0, qCV_NA=1, qCV_NB=2, qCV_JZA=3, qCV_JZB=4, qCV_JMP=5, qCV_BMP=6, qCV_NOP=7
};

typedef struct {
 int *pos;
 int  nst;
 int  (*fa)(int,int);
 int  (*fb )(int);
 int  ra,rb;
} qCvm;

/* rom[2i]=E8(op)^ks[2i], rom[2i+1]=arg^ks[2i+1] */
static const unsigned char qCrom[qC_KSN]={
 0xa4,0xb6,0x49,0xdc,0xa4,0x05,0x08,0x38,0x9d,0x1b,0xc5,
 0xf5,0x26,0xc3,0xc8,0x1c,0x66,0x93,0x76,0xf5,0x8d,0x4e
};

static unsigned qCfetch(int ip,int hi)
BEGIN
int o=(int)qCmbaA((qCu32)ip<<1,(qCu32)hi);
qCks_build();
RET (unsigned)(qCrom[o]^qCks[o]);
END

static void qCvm_run(qCvm*c)
BEGIN
int ip=0,guard=0,idx;unsigned op,ag,rw;
FOREVER
BEGIN
 WHEN(guard++>64 OR ip<0 OR ip>=(qC_KSN>>1)) break;
 rw=qCfetch(ip,0); op=qCaff8D(rw); ag=qCfetch(ip,1);
 WHEN(qCaff8E(op) ISNOT rw) break;
 switch(op)
 BEGIN
  case qCV_NA: c->ra=c->fa(c->nst>>1,*(c->pos+(c->nst>>1))); ip=(int)qCmbaA((qCu32)ip,1u); break;
  case qCV_NB: c->rb=c->fa((int)qCmbaS((qCu32)c->nst,1u),*(c->pos+(c->nst-1))); ip=(int)qCmbaA((qCu32)ip,1u); break;
  case qCV_JZA: ip=c->ra?ip+1:(int)ag; break;
  case qCV_JZB: ip=c->rb?ip+1:(int)ag; break;
  case qCV_JMP: ip=(int)ag; break;
  case qCV_BMP:
   idx=(int)qCmbaA((qCu32)c->nst,qCmbaS(ag,3u));
   *(c->pos+idx)=c->fb(*(c->pos+idx)); ip=(int)qCmbaA((qCu32)ip,1u); break;
  case qCV_HALT: RET;
  default: RET;
 END
END
END

/* ---- pair transducer ---- */
enum { qCD_GAP=0, qCD_RUN=1 };
static int qCcls[256];
static int qCdfa_next[2][2];
static int qCdfa_ready=0;

static void qCdfa_build(void)
BEGIN
int z;
WHEN(qCdfa_ready) RET;
LOOPN(z,256) qCcls[z]=isalpha(z)?1:0;
qCdfa_next[qCD_GAP][0]=qCD_GAP; qCdfa_next[qCD_GAP][1]=qCD_RUN;
qCdfa_next[qCD_RUN][0]=qCD_GAP; qCdfa_next[qCD_RUN][1]=qCD_RUN;
qCdfa_ready=1;
END

static int qCtrans(const char*s,int*out)
BEGIN
int st=qCD_GAP,n=0,c;const unsigned char*p=(const unsigned char*)s;
qCdfa_build();
while(*p)
BEGIN
 c=qCcls[*p];
 st=qCdfa_next[st][c];
 WHEN(st==qCD_RUN) *(out+n++)=toupper(*p)-AA;
 INCR(p);
END
RET n;
END

static int qCplug_first(const int*tq,int vb,int target)
BEGIN
int k;
LOOPN(k,vb) WHEN(*(tq+k)==target) RET k;
RET -1;
END

/* Mealy pair machine */
enum { qCM_WANT=0, qCM_HOLD=1 };
static int qCpair_mealy(const int*tq,int n,int t)
BEGIN
int st=qCM_WANT,a=0,z;
LOOPN(z,n)
BEGIN
 switch(st)
 BEGIN
  case qCM_WANT: a=*(tq+z); st=qCM_HOLD; break;
  default:
   WHEN(a IS t) RET *(tq+z);
   WHEN(*(tq+z) IS t) RET a;
   st=qCM_WANT; break;
 END
END
RET t;
END

/* ---- separator DFA ---- */
enum { qCT_SEP=0, qCT_TOK=1 };
static int qCtcls[256];
static int qCtnext[2][3];
static int qCtok_ok=0;
static int qCtok(char*s,char**out,int mx)
BEGIN
int st=qCT_SEP,n=0,c,z;unsigned char*p=(unsigned char*)s;
WHEN(NOT qCtok_ok)
BEGIN
 LOOPN(z,256) qCtcls[z]=2;
 qCtcls[0]=0; qCtcls[' ']=1; qCtcls[',']=1;
 qCtnext[qCT_SEP][0]=-1; qCtnext[qCT_SEP][1]=qCT_SEP; qCtnext[qCT_SEP][2]=qCT_TOK;
 qCtnext[qCT_TOK][0]=-1; qCtnext[qCT_TOK][1]=qCT_SEP; qCtnext[qCT_TOK][2]=qCT_TOK;
 qCtok_ok=1;
END
FOREVER
BEGIN
 c=qCtcls[*p];
 z=qCtnext[st][c];
 WHEN(z<0) break;
 WHEN(st IS qCT_SEP AND z IS qCT_TOK) BEGIN WHEN(n>=mx) break; *(out+n++)=(char*)p; END
 WHEN(st IS qCT_TOK AND z IS qCT_SEP) *p=0;
 st=z; INCR(p);
END
RET n;
END

/* ---- state ids: conjugation-walk flattening ---- */
enum qCst_e {
 qCS_s0=0, qCS_s1, qCS_s2, qCS_s3, qCS_s4, qCS_s5, qCS_s6, qCS_sN
};
static const unsigned char qCsucc[qCS_sN]={
 qCS_s1, qCS_s2, qCS_s3, qCS_s4, qCS_s5, qCS_s6, qCS_s6
};

#endif
