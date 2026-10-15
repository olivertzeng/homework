#ifndef UTIL_H
#define UTIL_H
#include "c.h"

#define PH_NONE  0
#define PH_INIT  1
#define PH_PLUG  2
#define PH_READY 3
static int PHASE=PH_NONE;
static int PHASE_PREV=PH_NONE;
#define ENTER_PHASE(p) (PHASE_PREV=PHASE,PHASE=(p))
#define REQUIRE_PHASE(p) do{ errcount+=(int)(((unsigned)PHASE-(unsigned)(p))>>(TWICE(TWICE(TWICE(TWICE(TWICE(1)))))-1)); }while(0)
#define PHASE_OK (PHASE>=PH_PLUG)

typedef INT (*modefn)(INT,CHAR*,CHAR*,CHAR*,CHAR*);
typedef modefn modetab[4];
static modetab MODEFN;
static int DISPATCH_READY=0;

#define MODE_LIST(X) X(0,INIT) X(1,PLUG) X(2,CHAR) X(3,TEXT)
#define XDECL(n,nm) PRIVATE INT GLUE2(do_,nm)(INT,CHAR*,CHAR*,CHAR*,CHAR*);
MODE_LIST(XDECL)
#undef XDECL

#define DISPATCH(m,a,x1,x2,x3,x4) (MODEFN[(m)]((a),(x1),(x2),(x3),(x4)))

static char SAMPLE[]="ILZLRTOXDBNLRYVJUISBUSHQFYFPXITKCXYKFUNWDTDLKYNTJOGGOFBXTXXABJNZVFCUTBKMPQUPMVECQXDSDQYXFJAPQFLMRAKFGKYGECCUDNIMVXBOTXIGANJSHOOIONSIWLJGVKNHQCQIQCGSONCZGBWKGPFQYVIODFHKJSLUGCPECZHTJYJIOQDUDVHCVLWSUFBUVZFQYSXNRECUFTYTIBGCDGEREFXSWGYIMURTRGOKITEMDRBSUYFAGVLTONXSCOKHWKJHNTPBBMODRXENRENDMWGTFBADFUBZZTAKXGSBGVCSXQNGAFYSQYPDHZCFQTUOYSXENBIBENFLNTYARFMMDNYRNMZJDMSTYOCILEEGJBKLSGAVSVAUSNYWJWDHCGQMKFOSOQIRVVUHOMONEMVMSLEPCWHCQXJFGCSNLBVGNHGCRTOZYSRAEGHDIJWZMDSNBXLHNJLJKSVREDJBPAVDLOHAGASXQJACICPEIFWFGKMAIIXPGHSNIDGZSYSYDKAKTCHJBJOINJDCYBMWLAJROPGLXZDKRWSPGUGSGIYGSKYLHDSWPTHJPVUUDQOCJISIOYFNCQWZGQJLEPWBYYYVJCWCLQMQIFCRIQRGEBJNNNLXCPCFKXAEHKOSGCTCHXSFPEJXFKIDOOLYZVKQJRWGQCOWJJYMRBBHJKJTHURCGPAUWXQUZRWKYWRWKOAVMHOKVCMFSZYMIMFUTXYOYZNQEQPVXGGAVXLMQJMSXRWJCSYBKAZCDAOFXQWGAIRVEEFIZYPEBQCXUNSZKBUTMBKYVNJQTLJLSMMLPPIWBFGGLLEARNGBKJGOABIFKHXFJWHZHMXLFYKQCAHUDTCPWORUPGBEJDFMITKJRSPBKVWQXJOVHZNBCLBDNPYVQNZHYICGNICZWNBHISLMUBELOZPNDIFDCNUYYWCZIRUGVEEVGPBPSXNCNBKZXOVYHIFPBJQXKIWNNVXTTXPDEWQOKWEPKQIEUSPRVXPXSYHKFOHLXKSRRKGXCVLCIYNFDXCFUTJAVWCTDCYTWCBYZKDQOWIDLBJNKQJRNHHLBQAANDEHPQEZABXZCCZGRZACEDNHPPSIDOTMMBCWFDEGVMAWRQQWCROJVCPFBGVTZCCUOAPHGIGALJCANYRSINUBFJBKXDUDHFRWQGHRYEWCKXMIEHDPMJMDNFMHIUASWESPCBYEOKHELJFYZDAJ";
static const int qZ0i[12]={7,4,0,3,4,17,12,0,17,10,4,17};
static char qZ0[16];
static char MIRROR_ID[]="V1";
static char PRELUDE_SPEC[]="";
static int POOL[5]={0,1,2,3,4};
static int POOLN=5;
static int SWEEP_OFFSETS=0;

static char sbuf1[64],sbuf2[64],sbuf3[64];
static char scratch[4096];

typedef void (*hookfn)(int);
static hookfn ON_MATCH=0;
static int HOOK_CALLS=0;

#define qB_SL(X) X(f0,0,qB_sa) X(f1,1,qB_sa) X(f2,2,qB_sa) X(f3,3,qB_sa)                      X(r0,0,qB_sb) X(r1,1,qB_sb) X(r2,2,qB_sb) X(r3,3,qB_sb)

#define qB_TK(a,b,c) do{ qB_mos(o1,o2,o3); qB_tp((a),(b),(c)); }while(0)

static unsigned long EPOCH=0,S_EPOCH=(unsigned long)-1;

#define PROF_LIST(X) X(letters) X(fwcalls) X(bwcalls) X(carryhits)                      X(plugswaps) X(tablechecks) X(cachemiss) X(strcopies)
#define XPROF(nm) static unsigned long GLUE2(PROF_,nm)=0;
PROF_LIST(XPROF)
#undef XPROF
#define PROF_BUMP(nm) (GLUE2(PROF_,nm)++)

static void prof_dump(void)
BEGIN
#define XPD(nm) printf("  %-12s %lu\n",#nm,GLUE2(PROF_,nm));
printf("profile:\n");
PROF_LIST(XPD)
#undef XPD
END

PUBLIC void note_key(void);

#define SWAP2(a,b) do{ int TMPVAR=(a);(a)=(b);(b)=TMPVAR; }while(0)

#include "l.h"

static int roundtrip(int v)
BEGIN
qBu(*const Ovm)(const qBc*,qBu)=qB_vm,(*const*const OOvm)(const qBc*,qBu)=&Ovm;
qB_ARM();
RET qB_s32((**OOvm)(qB_rtp,(qBu)v));
END

static INT qsrt(int*);

static void sort26(int*arr)
BEGIN
int s1,s2=0,pm=0,st=qB_tA,wk[qB_NW],*const Oa=arr,*const*const OOa=&Oa,*const Ow=wk;qBu od=0u,*const Od=&od;
qB_ARM();
FOREVER switch(st)
BEGIN
 case qB_tA: LOOPN(s1,qB_NW) *(Ow+s1)=s1<M?*(*OOa+s1):qB_SENT;pm=qB_cyc(*OOa,M,Od);st=qB_tB;break;
 case qB_tB: s2=qsrt(arr);st=(pm AND NOT (*Od%qB_P29))?qB_tF:qB_tC;break;
 case qB_tC: INCR(qB_sct);qB_bnet(Ow,qB_jac(qB_sct,(qBu)(M/TWICE(qB_ONE)))>0);st=pm?qB_tD:qB_tE;break;
 case qB_tD: s1=0;while(s1<M AND *(Ow+s1) IS s1) INCR(s1);s2&=s1 IS M;st=qB_tE;break;
 case qB_tE: LOOP26(s1) BEGIN WHEN(*(Oa+s1) ISNOT wk[s1]) BEGIN *(*OOa+s1)=*(Ow+s1);s2=0; END END
             (void)s2;RET;
 case qB_tF: WHEN(qB_pid(Oa,M,od)) LOOP26(s1) wk[s1]=s1;st=qB_tE;break;
 default: RET;
END
END

#endif
