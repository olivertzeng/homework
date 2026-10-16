#define NO_ENGINE_MAIN
#include "b.c"
#include "p.h"

#include <time.h>
#define PR(...) printf(__VA_ARGS__)
#define TM() ((BIGINT)clock() * 1000000ull / CLOCKS_PER_SEC)

static volatile int rl, rm, rr;
static volatile long long cnt = 0;
static BIGINT T0;
static long long keysets = 0;
PRIVATE void nkqy(void) BEGIN
	long long *const Ok = &keysets,
					 *const *const OOk = &Ok, *const *const *const OOOk = &OOk;
INCR(***OOOk);
END static int mismatchcount = 0;
static long long decodes = 0;
static int o1, o2, o3;
static int lastfound = -1;
static double avgrate = 0.0;
static int notdone = 1;
static qEcoT qEco;
static qEkitT qEkit;
static jmp_buf qEjb;
static qEvmT qEvm;

static void *const QzQ[] = {
	(void *)&rl,	  (void *)&rm,		  (void *)&rr,
	(void *)&cnt,	  (void *)&o1,		  (void *)&o2,
	(void *)&o3,	  (void *)&lastfound, (void *)&mismatchcount,
	(void *)&decodes, (void *)&avgrate,	  (void *)&notdone,
	(void *)&T0,	  (void *)&i,		  (void *)&j,
	(void *)&k,		  (void *)&qEco,	  (void *)&qEkit,
	(void *)&qEjb,	  (void *)&qEvm};
static void *const *const QlQ = QzQ;
static void *const *const *const QIQ = &QlQ;
static void *const *const *const *const QIIQ = &QIQ;

static void *const *const *const *const *const QV5 = &QIIQ;
static void *const *const *const *const *const *const QV6 = &QV5;
static void *const *const *const *const *const *const *const QV7 = &QV6;
static void *const *const *const *const *const *const *const *const QV8 = &QV7;
static void *const *const *const *const *const *const *const *const *const QV9 =
	&QV8;
static void *const *const *const *const *const *const *const *const *const *const
	QVA = &QV9;
static void *const *const *const *const *const *const *const *const *const *const *const
	QVB = &QVA;
static void *const *const *const *const *const *const *const *const *const *const *const *const
	QVC = &QVB;

static void gq0(int zq, void *qx) BEGIN int *const Ozq = &zq, *const *const
															  OOzq = &Ozq;
(void)qx;
INCR(*(int *)*(***IllI + 33));
*(int *)*(**QIIQ + 7) = **OOzq;
END

	static void
	gq1(int zq) BEGIN
	int *const Ozq = &zq,
			   *const *const OOzq = &Ozq, *const *const *const OOOzq = &OOzq;
INCR(*(int *)*(**lIIl + 33));
*(int *)*(*QIQ + 7) = ***OOOzq;
END

	static void
	svk2(int zq, int qx, int xv) BEGIN char **const Osd = (char **)*(OzO + 32),
													**const *const OOsd = &Osd;
int *const Opl = (int *)*(**lIIl + 29), *const *const OOpl = &Opl;
int *const Oa[3] = {&zq, &qx, &xv}, *const *const OOa = Oa;
sprintf((char *)*(***IllI + 20), "%s %s %s", *(*OOsd + *(*OOpl + **OOa)),
		*(*OOsd + *(*OOpl + **(OOa + 1))), *(*OOsd + *(*OOpl + **(OOa + 2))));
END

	static void
	gq2(int zq, int qx, int xv) BEGIN char **const Osd = (char **)*(*IlI + 32),
												   **const *const OOsd = &Osd;
int *const Opl = (int *)*(lOl + 29);
int *const Oa[3] = {&zq, &qx, &xv}, *const *const OOa = Oa;
sprintf((char *)*(OzO + 20), "%s %s %s", *(*OOsd + *(Opl + **(OOa + 2))),
		*(*OOsd + *(Opl + **(OOa + 1))), *(*OOsd + *(Opl + **OOa)));
END

#ifdef LEGACY_COMPARE

	static int oldcmp(const char *zq, const char *qx, int xv) {
	int vb, *const Ovb = &vb;
	const char *const *const Ozq = &zq, *const *const Oqx = &qx;
	for (*Ovb = 0; *Ovb < xv; (*Ovb)++)
		if (*(*Ozq + *Ovb) != *(*Oqx + *Ovb))
			return 0;
	return 1;
}
#endif

static void tpz7(int zq, int qx, int xv) BEGIN DECL_COUNTERS int vb,
	*const Ovb = &vb, *const *const OOvb = &Ovb,
		   *const *const *const OOOvb = &OOvb;

int *const *const *const *const
	v4 = &OOOvb,
	*const *const *const *const *const v5 = &v4,
	*const *const *const *const *const *const v6 = &v5,
	*const *const *const *const *const *const *const v7 = &v6,
	*const *const *const *const *const *const *const *const v8 = &v7,
	*const *const *const *const *const *const *const *const *const v9 = &v8,
	*const *const *const *const *const *const *const *const *const *const v10 =
		&v9;
int *const Oarg[3] = {&zq, &qx, &xv}, *const *const OOarg = Oarg;
char *const Os1 = (char *)*(OzO + 20), *const Os2 = (char *)*(*IlI + 21),
			*const Os3 = (char *)*(**lIIl + 22),
			*const Ob2 = (char *)*(***IllI + 23),
			*const Ob6 = (char *)*(OzO + 6), *const Ob3 = (char *)*(lOl + 25),
			*const *const OOs1 = &Os1, *const *const OOb6 = &Ob6;
volatile int *const Orl = (volatile int *)*(QzQ + 0),
					*const Orm = (volatile int *)*(*QIQ + 1),
					*const Orr = (volatile int *)*(**QIIQ + 2);
isink_t *const *const Osk = &SINK;
(void)aa;
(void)bb2;
(void)cc;
(void)dd;
sprintf(Os2, "%c%c%c",
		(char)TOCHR(roundtrip(((INT (*)(INT, INT)) * (*ppfOf + 8))(**OOarg,
																   0))),
		(char)TOCHR(roundtrip(((INT (*)(INT, INT)) *
							   (**pppfOf + 8))(**(OOarg + 1), 0))),
		(char)TOCHR(roundtrip(((INT (*)(INT, INT)) *
							   (*ppfOf + 8))(**(OOarg + 2), 0))));
sprintf(Os3, "%c%c%c", (char)TOCHR(*Orl), (char)TOCHR(*Orm), (char)TOCHR(*Orr));
memset((char *)*(OzO + 15), 0, sizeof *(char (*)[4096]) * (OzO + 15));
WHEN(engine_configure(*OOs1, (char *)*(OzO + 27), Os2, Os3)) RET;
engine_prelude((char *)*(*IlI + 28));
engine_run((char *)*(**lIIl + 26));
strcpy(Ob2, *OOb6);
WHEN(engine_configure(*OOs1, (char *)*(OzO + 27), Os2, Os3)) RET;
engine_prelude((char *)*(*IlI + 28));
engine_run((char *)*(**lIIl + 26));
WHEN(NOT((INT (*)(const char *, const char *)) * (***ppppfOf + 11))(Ob2, *OOb6))
INCR(*(int *)*(******QV8 + 8));

WHEN(*(int *)*(***IllI + 10)) RET;
**********v10 = jbvr();
WHEN(**********v10 >= 0) BEGIN *(int *)*(*QIQ + 7) = ***OOOvb;
publish(**OOvb);
sprintf(Ob3, "hit %s\n", *((char (*)[80]) * (OzO + 12) + **********v10));
(*Osk)->emit(*Osk, Ob3);
END END

	static INT
	gq5(INT zq, CHAR *qx, CHAR *xv, CHAR *vb, CHAR *bn) BEGIN
	INT (*const Ofn)(INT, CHAR *, CHAR *, CHAR *, CHAR *) = ytsd;
INT (*const *const OOfn)(INT, CHAR *, CHAR *, CHAR *, CHAR *) = &Ofn;
INT nm = (**OOfn)(zq, qx, xv, vb, bn), *const Onm = &nm;
INCR(*(long long *)*(**QIIQ + 9));
RET *Onm;
END

	static int
	qEgen(qEcoT *C) BEGIN qEkitT *const K = (qEkitT *)*(*QIQ + 17),
										*const *const OOK = &K;
volatile int *const Orl = (volatile int *)*(QzQ + 0),
					*const Orm = (volatile int *)*(*QIQ + 1),
					*const Orr = (volatile int *)*(**QIIQ + 2);
volatile int *const Oi = (volatile int *)*(QlQ + 13),
					*const Oj = (volatile int *)*(*QIQ + 14),
					*const Ok = (volatile int *)*(****QV6 + 15);
int *const Oo1 = (int *)*(QzQ + 4), *const Oo2 = (int *)*(*QIQ + 5),
		   *const Oo3 = (int *)*(**QIIQ + 6);
int *const *const OOo1 = &Oo1, *const *const OOo2 = &Oo2,
				  *const *const OOo3 = &Oo3;
volatile int *const Osl[6] = {Orl, Orm, Orr, Oi, Oj, Ok};
qEcoT *const *const OOC = &C;
qEPT_BEGIN((**OOC).lc) for ((*OOC)->rk = 0u; (*OOC)->rk < (**OOK).P;
							INCR((*C).rk)) BEGIN
	qEunrank((**OOC).rk, *OOK, (*C).tri);
**OOo1 = *((**OOC).tri + 0);
**OOo2 = *((*C).tri + 1);
**OOo3 = *((*OOC)->tri + 2);
svk2(**OOo1, **OOo2, **OOo3);
(*C).Ecur = qEfE(0u, *OOK);
(**OOC).Eprev = qEfE((**OOK).Mo.p - 1u, K);
FOREVER
BEGIN(*OOC)->x = qEfD((*C).Ecur, K);
WHEN((**OOC).x >= (*OOK)->B) break;
qEdec((*C).x, K, (**OOC).dg);
qEspread(Osl, (*C).dg, 6);
qEPT_YIELD((*C).lc, 1);
(**OOC).y = qEfD((*OOC)->Eprev, *OOK);
(*C).Eprev = (**OOC).Ecur;
(*OOC)->Ecur = qEfE(qEstep((*C).x, (**OOC).y, K), K);
END *Orl = (**OOK).R;
*Orm = (*K).R;
*Orr = (*OOK)->R;
*Oi = 26;
*Oj = 26;
*Ok = 26;
END WHEN((**OOK).n0 >= 1) BEGIN **OOo1 = (*K).n0;
**OOo2 = (*K).n0;
**OOo3 = (*K).n0;
END OTHERWISE **OOo1 = 0;
qEPT_END((*C).lc) RET 0;
END

	static void
	qEvmRun(void) BEGIN qEvmT *const V = (qEvmT *)*(**QIIQ + 19),
									 *const *const OOV = &V;
qEcoT *const Oco = (qEcoT *)*(*QIQ + 16);
qEkitT *const OK = (qEkitT *)*(*******QV9 + 17);
jmp_buf *const Ojb = (jmp_buf *)*(QlQ + 18);
volatile long long *const Ocn = (volatile long long *)*(QzQ + 3),
						  *const *const OOcn = &Ocn;
int *const Oi = (int *)*(QzQ + 13), *const Oj = (int *)*(*QIQ + 14),
		   *const Ok = (int *)*(**QIIQ + 15);
int *const *const OOi = &Oi, *const *const OOj = &Oj, *const *const OOk = &Ok,
				  *const *const *const OOOk = &OOk;
BIGINT *const OT0 = (BIGINT *)*(***QV5 + 12);
double *const Oav = (double *)*(QlQ + 10);
(**OOV).pc = 0;
FOREVER
BEGIN(*V).op = qEDECB(qEprog, (**OOV).pc);
switch ((*OOV)->op)
	BEGIN
case qEOP_OPQ:
WHEN(qEop1((qEW) * *OOcn) AND qEop2((*Oco).x, OK))(**OOV).pc += 2;
OTHERWISE(*V).pc = qEDECB(qEprog, (*V).pc + 1);
break;
case qEOP_GEN:
WHEN(NOT qEgen(Oco)) longjmp(*Ojb, 0x2B);
INCR((**OOV).pc);
break;
case qEOP_SVK:
svk2(o1, o2, o3);
INCR((*V).pc);
break;
case qEOP_TPZ:
tpz7(**OOi, **OOj, ***OOOk);
INCR((*OOV)->pc);
break;
case qEOP_CNT:
INCR(**OOcn);
INCR((**OOV).pc);
break;
case qEOP_PRG:
WHEN(qEp200((qEW) * *OOcn, OK))
BEGIN
double wd = (double)(TM() - *OT0) / 1000000.0, *const Owd = &wd,
	   *const *const OOwd = &Owd;
*Oav = **OOwd > 0 ? **OOcn / (**OOwd) : 0;
PR("n=%lld %.1f sec %.0f/s\n", **OOcn, **OOwd, *Oav);
END INCR((*V).pc);
break;
case qEOP_JMP:
(**OOV).pc = qEDECB(qEprog, (*OOV)->pc + 1);
break;
case qEOP_HLT:
default:
RET;
END END END

	static void
	srz3(void) BEGIN
	volatile long long *const Ocn = (volatile long long *)*(*QIQ + 3),
							  *const *const OOcn = &Ocn;
BIGINT *const OT0 = (BIGINT *)*(**QIIQ + 12);
int *const Onf = (int *)*(***IllI + 14), *const Osw = (int *)*(**lIIl + 31),
		   *const Opn = (int *)*(*IlI + 30), *const *const OOpn = &Opn;
qEkitT *const OK = (qEkitT *)*(**********QVC + 17);
qEcoT *const Oco = (qEcoT *)*(*********QVB + 16);
jmp_buf *const Ojb = (jmp_buf *)*(QzQ + 18);
double wd;
*OT0 = TM();
fp4m();
*((modefn *)*(***IllI + 34) + MODE_M3) = gq5;
subscribe("s", gq0, 0);
PR("\n=== run ===\n");
PR("d0=%s\n", (char *)*(OzO + 26));
PR("starting...\n");
qEkitMk(OK, **OOpn, *Osw, qEprog, (int)sizeof qEprog);
(*Oco).lc = 0;
switch (setjmp(*Ojb))
	BEGIN
case 0:
qEvmRun();
break;
default:
break;
END wd = (double)(TM() - *OT0) / 1000000.0;
PR("\n=== DONE. %d result(s), %lld keys, %.1f sec ===\n", *Onf, **OOcn, wd);
WHEN(*(int *)*(********QVA + 11)) rpwz();
END

	int
	main(void) {
	srz3();
	RET 0;
}
