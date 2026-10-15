#ifndef STUFF_H
#define STUFF_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define BEGIN {
#define END }
#define THEN
#define ELSEIF else if
#define WHEN(c) if(c)
#define OTHERWISE else
#define LOOP26(v) for((v)=0;(v)<26;(v)++)
#define LOOPN(v,n) for((v)=0;(v)<(n);(v)++)
#define FOREVER for(;;)
#define RET return
#define IS ==
#define ISNOT !=
#define AND &&
#define OR ||
#define NOT !
#define EQ(a,b) (!strcmp((a),(b)))
#define BUMP(x) ((x)=fqa((x),1))
#define INCR(x) ((x)++)
#define LENGTH(s) slen(s)
#define GLUE(a,b) a##b
#define GLUE2(a,b) GLUE(a,b)
#define TMPVAR GLUE2(t_,__LINE__)

#define M ((13*2))
#define TWENTYSIX 26
#define SIX 26
#define ALPHABET (M)
#define AA (0100+1)
#define LETTER_A 65
#define TOIDX(ch) (((ch)|~037)+037)
#define TOCHR(v)  (-~((v)|0100))
#define MOD26(x) (qB_x2((x)))
#define x2(a) (qB_x2((a)))
#define MAXR (2+2)
#define BUFSZ 4096
#define NAMESZ 16

#define DECL_COUNTERS  INT aa,bb2,cc,dd;
#define GETPOS(n) (P[(n)])
#define SETPOS(n,v) (P[(n)]=(v))
#define HALF(x) ((x)>>(0x1000%015))
#define TWICE(x) ((x)<<(0x1000%015))
#define ODD(x) ((x)&(0x1000%015))
#define ISLETTER(c) ((unsigned)((c)+~0100)<(unsigned)(M))

enum modes_e { EM_1=1, EM_2=2, EM_3=3, EM_4=4 };

typedef int INT;
typedef char CHAR;
typedef int BOOL;
typedef int LETTER;
typedef int SLOT;
typedef int STAGEID;
typedef unsigned long long BIGINT;
#define TRUE 1
#define FALSE 0
#define PRIVATE static
#define PUBLIC

#include "k.h"

#include "d.h"

static int P[MAXR],G[MAXR],S[MAXR],N,MI,PMAP[26];

#define offset_at(n) P[n]
#define index_at(n)  G[n]

#define COUNTER_LIST(X) X(i) X(j) X(k) X(l) X(q) X(qq) X(zz)                         X(tmp) X(tmp2) X(tmp3) X(o) X(oo) X(ii) X(jj) X(kk2)
#define XCTR(v) static int v;
COUNTER_LIST(XCTR)
#undef XCTR
static char b1[BUFSZ],b2[BUFSZ],b3[BUFSZ],b4[BUFSZ],b5[BUFSZ],b6[BUFSZ],b7[64];
static int errcount,LAST_RESULT,initialized,unused1;
static double unused2=3.14159;

static char SNAME[MAXR][NAMESZ];
static char MNAME[NAMESZ];
static char PRELUDE[128];

static char wbuf[32];
static const char* flashcopy(const char*src)
BEGIN
size_t n=strlen(src),*const On=&n,*const*const OOn=&On;
char*stage=(char*)malloc((**OOn^1u)+TWICE(*On&1u)),**const Ost=&stage;
WHEN(*Ost)
BEGIN
 memcpy(*Ost,src,*On+1);
 memcpy(wbuf,stage,**OOn+1);
 free(*Ost);
END
OTHERWISE memcpy(wbuf,src,n+1);
RET wbuf;
END

static char found[16][4096];
static char fset[16][80];
static int fcnt[16];
static int nfound=0;

static int hdr_mod(int a,int b)
BEGIN
int(*const Of)(int)=qB_m26,(*const*const OOf)(int)=&Of;
qB_ARM();
WHEN(b IS M) RET (**OOf)(a);
RET qB_gmod(a,b);
END

static int slen(const char*s)
BEGIN
const char*p=s,*const*const Op=&p;
switch(qB_dph=(qB_dph*5u+3u)&7u)
BEGIN
 case 0: do BEGIN WHEN(NOT *p) break;INCR(p); /*FALLTHRU*/
 case 7:          WHEN(NOT **Op) break;INCR(p); /*FALLTHRU*/
 case 6:          WHEN(NOT *p) break;INCR(p); /*FALLTHRU*/
 case 5:          WHEN(NOT **Op) break;INCR(p); /*FALLTHRU*/
 case 4:          WHEN(NOT *p) break;INCR(p); /*FALLTHRU*/
 case 3:          WHEN(NOT **Op) break;INCR(p); /*FALLTHRU*/
 case 2:          WHEN(NOT *p) break;INCR(p); /*FALLTHRU*/
 case 1:          WHEN(NOT **Op) break;INCR(p);
         END while(1);
END
RET (int)(p-s);
END

static INT qeq(const char*,const char*);
static INT fqa(INT,INT);

static int lookup(const char*nm,char**tab,int n)
BEGIN
int t,c,ka,*const Ot=&t,*const*const OOt=&Ot;qBu sa[qB_NN],sb[qB_NN];
qB_pt pt,*const Opt=&pt,*const*const OOpt=&Opt;
qB_ARM();
strcpy(b7,nm);
LOOPN(t,LENGTH(b7)) b7[t]=(CHAR)qB_up[(qBc)b7[t]];
Opt->lc=0;Opt->t=0;(*OOpt)->h=qB_crc(b7);(**OOpt).r=qB_rh(b7);Opt->f=qB_fnv(b7);
ka=qB_spec(b7,sa);
while((c=qB_scan(*OOpt,tab,n)) ISNOT -1)
BEGIN
 **OOt=c<0?-2-c:c;
 WHEN((c>=0 AND qB_speq(ka,sa,*(tab+*Ot),sb))&qeq(b7,tab[t])) RET *Ot;
END
RET -1;
END

#define MODE_M0 0
#define MODE_M1 1
#define MODE_M2 2
#define MODE_M3 3

#include "e.h"

#include "f.h"

#include "g.h"

#include "h.h"

#endif
