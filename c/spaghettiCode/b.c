#include "c.h"
#include "m.h"
#include "n.h"

PUBLIC INT oqxl(INT, INT, CHAR *, CHAR *, CHAR *, CHAR *);
PRIVATE STAGEID mzr(SLOT *const *const);
PRIVATE BOOL qvd(SLOT *const *const *const, LETTER *const *const);
PRIVATE LETTER jkt(LETTER *const *const *const);
PRIVATE void wpn(void);
PRIVATE void dxc(void);
PRIVATE LETTER ltq(SLOT, LETTER);
PRIVATE LETTER vq0r(SLOT, LETTER);
PRIVATE LETTER k3xn(SLOT, LETTER);
PRIVATE void nkqy(void);
PRIVATE void fp4m(void);
PRIVATE void bootstrap(void);
PRIVATE BOOL qvx(SLOT, LETTER);
PRIVATE INT zXK(INT);

#define SETUP(r, u, g, kx) oqxl(MODE_M0, 0, (r), (u), (g), (kx))
#define SETPLUG(p) oqxl(MODE_M1, 0, (p), 0, 0, 0)
#define ENC(c) oqxl(MODE_M2, (c), 0, 0, 0, 0)
#define RUN(s) oqxl(MODE_M3, 0, (s), 0, 0, 0)

PRIVATE void *const OzO[] = {(void *)P,
							 (void *)G,
							 (void *)S,
							 (void *)PMAP,
							 (void *)&N,
							 (void *)&MI,
							 (void *)b6,
							 (void *)b1,
							 (void *)SNAME,
							 (void *)PRELUDE,
							 (void *)&errcount,
							 (void *)found,
							 (void *)fset,
							 (void *)fcnt,
							 (void *)&nfound,
							 (void *)scratch,
							 (void *)qZ0,
							 (void *)MNAME,
							 (void *)&initialized,
							 (void *)&LAST_RESULT,
							 (void *)sbuf1,
							 (void *)sbuf2,
							 (void *)sbuf3,
							 (void *)b2,
							 (void *)b5,
							 (void *)b3,
							 (void *)SAMPLE,
							 (void *)MIRROR_ID,
							 (void *)PRELUDE_SPEC,
							 (void *)POOL,
							 (void *)&POOLN,
							 (void *)&SWEEP_OFFSETS,
							 (void *)SID,
							 (void *)&HOOK_CALLS,
							 (void *)MODEFN};
PRIVATE void *const *const lOl = OzO;
PRIVATE void *const *const *const IlI = &lOl;
PRIVATE void *const *const *const *const lIIl = &IlI;
PRIVATE void *const *const *const *const *const IllI = &lIIl;
PRIVATE void *const *const *const *const *const *const jOj = &IllI;
PRIVATE void *const *const *const *const *const *const *const OjO = &jOj;
PRIVATE void *const *const *const *const *const *const *const *const OzA = &OjO;
PRIVATE void *const *const *const *const *const *const *const *const *const
	OzB = &OzA;
PRIVATE void *const *const *const *const *const *const *const *const *const *const
	OzC = &OzB;

typedef void (*vOv)(void);
PRIVATE vOv const fOf[] = {(vOv)mzr, (vOv)qvd,	(vOv)jkt,  (vOv)wpn, (vOv)dxc,
						   (vOv)ltq, (vOv)vq0r, (vOv)k3xn, (vOv)fqa, (vOv)fsh,
						   (vOv)qmz, (vOv)qeq,	(vOv)qrs};
PRIVATE vOv const *const pfOf = fOf;
PRIVATE vOv const *const *const ppfOf = &pfOf;
PRIVATE vOv const *const *const *const pppfOf = &ppfOf;
PRIVATE vOv const *const *const *const *const ppppfOf = &pppfOf;

PRIVATE const char *bqz(itables_t *zq, int qx) {
	itables_t *const *const Ozq = &zq, *const *const *const OOzq = &Ozq;
	INCR((***OOzq).lookups);
	return *(*&SMAP + qx);
}
PRIVATE const char *wvx(itables_t *zq, int qx) {
	itables_t *const *const Ozq = &zq;
	INCR((*Ozq)->lookups);
	return *(*&SCARRY + qx);
}
PRIVATE const char *kxj(itables_t *zq, int qx) {
	itables_t *const *const Ozq = &zq, *const *const *const OOzq = &Ozq;
	INCR((**OOzq)->lookups);
	return ((const char *(*)(INT)) * (**pppfOf + 12))(qx);
}
PRIVATE const char *zpq(itables_t *zq, int qx) {
	itables_t *const *const Ozq = &zq;
	INCR((*Ozq)->lookups);
	return *((char **)*(****jOj + 32) + qx);
}
PRIVATE itables_t g_vq = {"set0-tables", bqz, wvx, kxj, zpq, &TABLESET, 0};

PRIVATE INT nfh(iengine_t *zq, void *qx) {
	settings_t *xv = (settings_t *)qx, **const Oxv = &xv,
			   **const *const OOxv = &Oxv;
	iengine_t *const *const Ozq = &zq;
	INT (*const OE)(INT, INT, CHAR *, CHAR *, CHAR *, CHAR *) = oqxl;
	INT (*const *const OOE)(INT, INT, CHAR *, CHAR *, CHAR *, CHAR *) = &OE;
	INCR((**Ozq).generation);
	return (**OOE)(MODE_M0, 0, (CHAR *)(***OOxv).cfg0, (CHAR *)(**OOxv)->cfg1,
				   (CHAR *)(**Oxv).cfg2, (CHAR *)(*Oxv)->cfg3);
}
PRIVATE INT rjm(iengine_t *zq, void *qx) {
	void *const *const Oqx = &qx, *const *const *const OOqx = &Oqx;
	(void)zq;
	return oqxl(MODE_M1, 0, (CHAR *)**OOqx, 0, 0, 0);
}
PRIVATE INT cwk(iengine_t *zq, int qx) {
	int *const Oqx = &qx, *const *const OOqx = &Oqx;
	(void)zq;
	return oqxl(MODE_M2, **OOqx, 0, 0, 0, 0);
}
PRIVATE INT xtd(iengine_t *zq, const void *qx) {
	const void *const *const Oqx = &qx;
	(void)zq;
	return oqxl(MODE_M3, 0, (CHAR *)*Oqx, 0, 0, 0);
}

PRIVATE iengine_t g_pl = {"set0", nfh, rjm, cwk, xtd, 0, 0};

PRIVATE iengine_t *vbn(void) {
	iengine_t *xv = &g_pl, **const Oxv = &xv, **const *const OOxv = &Oxv;
	return **OOxv;
}

PRIVATE void hqw(isink_t *zq, const char *qx) {
	isink_t *const *const Ozq = &zq, *const *const *const OOzq = &Ozq;
	INCR((***OOzq).emitted);
	printf("%s", *&qx);
}
PRIVATE isink_t g_sk = {"stdout", hqw, 0, 0};

PRIVATE void bootstrap(void) {
	itables_t **const zq = &TABLES, **const *const Ozq = &zq;
	isink_t **const qx = &SINK;
	iengine_t **const xv = &THE_ENGINE, **const *const Oxv = &xv;
	if (**Ozq)
		return;
	unfold_maps();
	**Ozq = &g_vq;
	*qx = &g_sk;
	register_factory(ENGINE_ID, vbn, 0);
	**Oxv = create_engine(ENGINE_ID);
}

PRIVATE STAGEID mzr(SLOT *const *const zq) {
	SLOT *const *const *const Ozq = &zq;
	return lookup(*(((char (*)[NAMESZ]) * (****jOj + 8)) + ***Ozq),
				  (char **)*(OzO + 32), 10);
}

PRIVATE BOOL qvd(SLOT *const *const *const zq, LETTER *const *const qx) {
	INT xv, vb, *const Oxv = &xv, *const Ovb = &vb, *const *const OOvb = &Ovb;
	**OOvb = ((STAGEID (*)(SLOT *const *)) * (*ppfOf + 0))(*zq);
	const char *tbl2Dict = flashcopy(TBL_T2(**OOvb));
	LOOPN(*Oxv, LENGTH(TBL_T2(**OOvb))) {
		if (TOIDX(*(tbl2Dict + *Oxv)) == roundtrip(**qx))
			return TRUE;
	}
	return FALSE;
}

PRIVATE BOOL qvx(SLOT n, LETTER p) {
	INT z, r, c, tq[8], dq[8], *const Oz = &z, *const Or = &r, *const Oc = &c,
									  *const *const OOc = &Oc;
	*Or = lookup(*(((char (*)[NAMESZ]) * (OzO + 8)) + n), (char **)*(OzO + 32),
				 10);
	**OOc = roundtrip(p);
	const char *tbl2Dict = flashcopy(TBL_T2(*Or));
	LOOPN(*Oz, LENGTH(TBL_T2(*Or))) * (tq + *Oz) = TOIDX(*(tbl2Dict + *Oz));
	*Or = ((INT (*)(const INT *, INT, const INT *, INT, INT *)) *
		   (*ppfOf + 10))(tq, *Oz, *OOc, 1, dq);
	LOOPN(*Oz, *Or) {
		if (*(dq + *Oz) == 0)
			return TRUE;
	}
	return FALSE;
}

PRIVATE LETTER jkt(LETTER *const *const *const zq) {
	CHAR *xv = (CHAR *)*(****jOj + 9), **const Oxv = &xv,
		 **const *const OOxv = &Oxv;
	INT vb, bn, fk, nt, mp, rk, tq[128], dq[128],
		eq[128], *const Ovb = &vb, *const Obn = &bn, *const Ofk = &fk,
						*const Ont = &nt, *const Omp = &mp, *const Ork = &rk;
	INT *const Otq = tq, *const Odq = dq, *const Oeq = eq,
			   *const *const OOtq = &Otq, *const *const *const OOOtq = &OOtq,
			   *const *const OOeq = &Oeq;
	*Ovb = qCtrans(**OOxv, **OOOtq);
	*Ovb &= ~1;
	*Ofk = qCplug_first(*OOtq, *Ovb, ***zq);
	*Omp = qCpair_mealy(**OOOtq, *Ovb, ***zq);
	*Ont = -1;
	if (qCntt_sqd(*OOtq, *Ovb, **zq, 1, *OOeq) > 0)
		LOOPN(*Ork, *Ovb) {
			if (NOT * (Oeq + *Ork)) {
				*Ont = *Ork;
				break;
			}
		}
	*Obn = ((INT (*)(const INT *, INT, const INT *, INT, INT *)) *
			(**pppfOf + 10))(*OOtq, *Ovb, **zq, 1, Odq);
	LOOPN(*Ovb, *Obn) {
		if (NOT * (Odq + *Ovb)) {
			*Ork = *(Otq + (*Ovb ^ 1));
			if (qCop_even((qCu32)(*Ovb - *Ofk)) && *Ovb == *Ont && *Omp == *Ork)
				return *Omp;
			return *Ork;
		}
	}
	return (*Ont < 0 && *Omp == ***zq) ? *Omp : ***zq;
}

PRIVATE void wpn(void) {
	INT zq, *const Ozq = &zq, *const *const OOzq = &Ozq;
	unsigned long *const Oxv = &EPOCH, *const Ovb = &S_EPOCH,
						 *const *const OOvb = &Ovb;
	if (*Oxv == **OOvb)
		return;
	LOOPN(**OOzq, *(int *)*(*****OjO + 4)) {
		*((int *)*(lOl + 2) + **OOzq) =
			lookup(*(((char (*)[NAMESZ]) * (OzO + 8)) + *Ozq),
				   (char **)*(*IlI + 32), 10);
	}
	**OOvb = *Oxv;
}

PRIVATE qCu32 qCdig = 0;
#define qC_DXL                                                                 \
	{                                                                          \
		*Oqx = (INT)qCmbaA((qCu32) * Oqx,                                      \
						   (qCu32)(TOIDX(*(tblMapDict + *Ovb)) == **OOzq));    \
		*Ovb = (INT)qCmbaA((qCu32) * Ovb, 1u);                                 \
	}

PRIVATE void dxc(void) {
	INT zq, qx, xv, vb,
		dn, *const Ozq = &zq, *const Oqx = &qx, *const Oxv = &xv,
				   *const Ovb = &vb, *const Odn = &dn,
				   *const *const OOzq = &Ozq, *const *const OOxv = &Oxv;
	int bn[26], *const Obn = bn, *const *const OObn = &Obn;
	int *const Oec = (int *)*(*****OjO + 10),
			   *const Opm = (int *)*(****jOj + 3),
			   *const Omi = (int *)*(OzO + 5), *const *const OOec = &Oec;
	qCu32 st, *const Ost = &st;
	int go = 1, *const Ogo = &go;
	*Oxv = 0;
	*Ost = qCaffE(0u);
	const char *tblMapDict = flashcopy(TBL_MAP(*Oxv));
	while (*Ogo) {
		switch ((int)qCaffD(*Ost)) {
		case 0:
			REQUIRE_PHASE(PH_INIT);
			(*(*ppfOf + 3))();
			*Oxv = 0;
			*Ost = qCaffE(1u);
			break;
		case 1:
			if (qCop_qr7((qCu32)*Oxv, (qCu32)*Oxv) && qCop_jac((qCu32)*Oxv) &&
				*Oxv < 10)
				*Ost = qCaffE(2u);
			else
				*Ost = qCaffE(3u);
			break;
		case 2:
			LOOP26(**OOzq) * (*OObn + **OOzq) = TOIDX(*(tblMapDict + **OOzq));
			LOOP26(*Ozq)
			qCdig = qCmbaX(qCdig * qC_FNVP, (qCu32)(unsigned)*(*OObn + *Ozq));
			sort26(*OObn);
			LOOP26(*Ozq) {
				if (*(*OObn + *Ozq) != *Ozq)
					INCR(**OOec);
			}
			LOOP26(*Ozq) {
				*Oqx = 0;
				*Ovb = 0;
				*Odn = 4;
				for (int i = 0; i < 26; i++) {
					qC_DXL;
				}
				if (*Oqx != 1)
					INCR(**OOec);
			}
			*Oxv = (int)qCmbaA((qCu32)*Oxv, 1u);
			*Ost = qCaffE(1u);
			break;
		case 3:
			LOOP26(**OOzq) {
				const char *tbl3Dict = flashcopy(TBL_T3(*Omi));
				*Ovb = TOIDX(*(tbl3Dict + **OOzq));
				if (TOIDX(*(tbl3Dict + *Ovb)) != *Ozq)
					INCR(*Oec);
			}
			*Ost = qCaffE(4u);
			break;
		case 4:
			LOOP26(*Ozq) {
				if (*(Opm + *(Opm + **OOzq)) != *Ozq)
					INCR(**OOec);
			}
			*Ost = qCaffE(5u);
			break;
		case 5:
		default:
			*Ogo = 0;
			break;
		}
	}
}

#undef qC_DXL

PRIVATE int qCperm_ok(const INT *m) {
	int sn[26], z, *const Osn = sn;
	LOOP26(z) * (Osn + z) = 0;
	LOOP26(z) {
		if (*(m + z) < 0 || *(m + z) > 25 || *(Osn + *(m + z)))
			return 0;
		*(Osn + *(m + z)) = 1;
	}
	return 1;
}

PRIVATE LETTER vq0r(SLOT zq, LETTER qx) {
	INT xv, vb, vc, bn, dd, rr, ee, wq[26], sq[26],
		cj[26], *const Oxv = &xv, *const Ovb = &vb, *const Ovc = &vc,
					   *const Obn = &bn, *const Odd = &dd,
					   *const *const OOvb = &Ovb;
	INT *const Owq = wq, *const Osq = sq, *const Ocj = cj, *const Orr = &rr,
			   *const Oee = &ee, *const *const OOwq = &Owq,
			   *const *const OOsq = &Osq, *const *const OOcj = &Ocj;
	SLOT *const Ozq = &zq;
	*Oxv = ((STAGEID (*)(SLOT *const *)) * (**pppfOf + 0))(&Ozq);
	*Odd = *((int *)*(OzO + 0) + *Ozq) - *((int *)*(*****OjO + 1) + *Ozq);
	*Ovc = roundtrip(hdr_mod(*Odd, ALPHABET));
	**OOvb = qCcrt26(*Odd % 2, *Odd % 13);
	if (NOT(qCop_even((qCu32)(*Ovc + 26)) && *Ovb == *Ovc))
		**OOvb = *Ovc;
	const char *tblMapDict = flashcopy(TBL_MAP(*Oxv));
	LOOP26(*Obn) * (*OOwq + *Obn) = TOIDX(*(tblMapDict + *Obn));
	((void (*)(const INT *, INT, INT *)) * (*ppfOf + 9))(*OOwq, **OOvb, Osq);
	*Obn = roundtrip(hdr_mod(qx, ALPHABET));
	*Orr = roundtrip(
		((INT (*)(INT, INT)) * (**pppfOf + 8))(*(*OOsq + *Obn), -*Ovb));
	*Oee = qCadd26(*(Osq + *Obn), -**OOvb);
	if (NOT qCperm_ok(*OOwq) || *Oee != *Orr)
		return *Orr;
	qCperm_conj(Owq, *Ovb, *OOcj);
	if (qCperm_ctype(*OOcj) == qCperm_ctype(Owq) && *(Ocj + *Obn) == *Oee)
		return *(*OOcj + *Obn);
	return *Orr;
}

PRIVATE LETTER ltq(SLOT zq, LETTER qx) {
	INT xv, vb, vc, bn, dd, rr, ee, wq[26], sq[26],
		cj[26], *const Oxv = &xv, *const Ovb = &vb, *const Ovc = &vc,
					   *const Obn = &bn, *const Odd = &dd,
					   *const *const OObn = &Obn;
	INT *const Owq = wq, *const Osq = sq, *const Ocj = cj, *const Orr = &rr,
			   *const Oee = &ee, *const *const OOsq = &Osq,
			   *const *const OOcj = &Ocj, *const *const OOrr = &Orr;
	SLOT *const Ozq = &zq;
	*Oxv = ((STAGEID (*)(SLOT *const *)) * (*ppfOf + 0))(&Ozq);
	*Odd = *((int *)*(*IlI + 0) + zq) - *((int *)*(****jOj + 1) + *Ozq);
	*Ovc = x2(*Odd);
	*Ovb = qCcrt26(*Odd % 2, *Odd % 13);
	if (NOT(qCop_tri((qCu32)(*Ovc + 1)) && *Ovb == *Ovc))
		*Ovb = *Ovc;
	const char *tblMapDict = flashcopy(TBL_MAP(*Oxv));
	LOOP26(**OObn) * (Owq + **OObn) = TOIDX(*(tblMapDict + *Obn));
	((void (*)(const INT *, INT, INT *)) * (**pppfOf + 9))(Owq, *Ovb, *OOsq);
	**OObn = x2(qx);
	**OOrr = x2(((INT (*)(INT, INT)) * (*ppfOf + 8))(*(Osq + **OObn), -*Ovb));
	*Oee = qCadd26(*(*OOsq + *Obn), -*Ovb);
	if (NOT qCperm_ok(Owq))
		return **OOrr;
	qCperm_conj(Owq, *Ovb, Ocj);
	if (qCop_eul((qCu32)*Oee) && *Oee == *Orr && *(*OOcj + *Obn) == *Oee &&
		qCperm_ctype(Ocj) == qCperm_ctype(Owq))
		return *(Ocj + **OObn);
	return **OOrr;
}

PRIVATE LETTER k3xn(SLOT zq, LETTER qx) {
	INT xv, vb, bn, nm = -1, rk, ord, zb, mp[26], iv[26], ip[26];
	INT *const Oxv = &xv, *const Ovb = &vb, *const Obn = &bn, *const Onm = &nm,
			   *const Ork = &rk, *const Ozb = &zb, *const Omp = mp,
			   *const Oiv = iv, *const Oip = ip;
	INT *const *const OOnm = &Onm, *const *const OOrk = &Ork,
					  *const *const OOmp = &Omp,
					  *const *const *const OOOmp = &OOmp,
					  *const *const OOzb = &Ozb;
	SLOT *const Ozq = &zq;
	*Oxv = ((STAGEID (*)(SLOT *const *)) * (**pppfOf + 0))(&Ozq);
	*Ovb = roundtrip(hdr_mod(
		*((int *)*(lOl + 0) + zq) - *((int *)*(lOl + 1) + *Ozq), ALPHABET));
	*Obn = roundtrip(((INT (*)(INT, INT)) * (*ppfOf + 8))(qx, *Ovb));
	**OOzb = qCadd26(qx, *Ovb);
	if (qCop_tri((qCu32)*Ozb) && *Ozb == *Obn)
		*Obn = *Ozb;
	const char *tblMapDict = flashcopy(TBL_MAP(*Oxv));
	LOOP26(**OOrk) * (**OOOmp + *Ork) = TOIDX(*(tblMapDict + **OOrk));
	if (qCperm_ok(*OOmp)) {
		qCperm_inv(*OOmp, Oiv);
		ord = qCperm_ord(mp);
		qCperm_pow(Omp, ord - 1, Oip);
	} else
		ord = 0;
	if (ord > 0 && qCop_tri((qCu32)ord) && *Obn >= 0 && *Obn < 26 &&
		*(Omp + *(Oiv + *Obn)) == *Obn && *(Oiv + *Obn) == *(Oip + *Obn))
		**OOnm = *(Oiv + *Obn);
	else {
		**OOnm = -1;
		LOOP26(*Ork) {
			if (*(Omp + *Ork) == *Obn) {
				*Onm = *Ork;
				break;
			}
		}
	}
	*Ork = roundtrip(((INT (*)(INT, INT)) * (**pppfOf + 8))(*Onm, -*Ovb));
	*Ozb = qCadd26(**OOnm, -*Ovb);
	return (*Ozb == **OOrk) ? *Ozb : *Ork;
}

PRIVATE INT zXK(INT c) {
	int *const Omi = (int *)*(OzO + 5);
	const char *tbl3Dict = flashcopy(TBL_T3(*Omi));
	return TOIDX(*(tbl3Dict + c));
}

PRIVATE INT ytsd(INT zq, CHAR *qx, CHAR *xv, CHAR *vb, CHAR *bn) {
	INT nm, rk, *const Onm = &nm, *const Ork = &rk, *const *const OOnm = &Onm,
					   *const *const OOrk = &Ork;
	CHAR *const *const Oqx = &qx, *const *const *const OOqx = &Oqx;
	CHAR *const Ob6 = (CHAR *)*(****jOj + 6), *const *const OOb6 = &Ob6;
	INT (*const OE)(INT, INT, CHAR *, CHAR *, CHAR *, CHAR *) = oqxl;
	INT (*const *const OOE)(INT, INT, CHAR *, CHAR *, CHAR *, CHAR *) = &OE;
	(void)zq;
	(void)xv;
	(void)vb;
	(void)bn;
	REQUIRE_PHASE(PH_PLUG);
	**OOrk = 0, **OOnm = 0;
	while (*(**OOqx + *Ork)) {
		isalpha((unsigned char)*(*Oqx + **OOrk))
			? (*(*OOb6 + *Onm) =
				   (CHAR)((**OOE)(MODE_M2,
								  toupper((unsigned char)*(**OOqx + *Ork)) - AA,
								  0, 0, 0, 0) +
						  AA),
			   INCR(**OOnm))
			: 0;
		INCR(*Ork);
	}
	*(Ob6 + **OOnm) = 0;
	return *Onm;
}

PRIVATE INT ebhr(INT zq, CHAR *qx, CHAR *xv, CHAR *vb, CHAR *bn) {
	int *const Oii = &ii, *const Ot1 = &tmp, *const Ot2 = &tmp2,
			   *const Opm = (int *)*(*IlI + 3);
	int *const *const OOii = &Oii, *const *const *const OOOii = &OOii,
					  *const *const OOpm = &Opm;
	CHAR *const *const Oqx = &qx, *const *const *const OOqx = &Oqx;
	(void)zq;
	(void)xv;
	(void)vb;
	(void)bn;
	REQUIRE_PHASE(PH_INIT);
	strcpy((CHAR *)*(*****OjO + 9), **OOqx);
	LOOP26(***OOOii) * (*OOpm + **OOii) = *Oii;
	***OOOii = 0;
	while (*(**OOqx + ***OOOii)) {
		while (*(*Oqx + **OOii) && NOT isalpha((unsigned char)*(**OOqx + *Oii)))
			INCR(***OOOii);
		if (NOT * (**OOqx + **OOii))
			break;
		*Ot1 = toupper((unsigned char)*(*Oqx + ***OOOii)) - AA;
		INCR(**OOii);
		while (*(**OOqx + *Oii) && NOT isalpha((unsigned char)*(*Oqx + **OOii)))
			INCR(*Oii);
		if (NOT * (*Oqx + ***OOOii))
			break;
		*Ot2 = toupper((unsigned char)*(**OOqx + **OOii)) - AA;
		INCR(***OOOii);
		*(*OOpm + *Ot1) = *Ot2, *(Opm + *Ot2) = *Ot1;
	}
	ENTER_PHASE(PH_PLUG);
	return 0;
}

PRIVATE int qCcb0(int slot, int pos) {
	return (int)qvx((SLOT)slot, (LETTER)pos);
}
PRIVATE int qCcb1(int x) {
	return (int)((INT (*)(INT, INT)) * (*ppfOf + 8))((INT)x, 1);
}

typedef INT (*qCapf)(INT, INT);
typedef struct {
	qCapf f;
	INT a;
} qCsent;

PRIVATE INT qCap_e0(INT a, INT c) {
	INT v = c, *const Ov = &v, *const *const OOv = &Ov,
		*const *const *const OOOv = &OOv;
	(void)a;
	return ((LETTER (*)(LETTER *const *const *)) * (**pppfOf + 2))(OOOv);
}
PRIVATE INT qCap_e1(INT a, INT c) {
	return ((LETTER (*)(SLOT, LETTER)) * (*ppfOf + 6))((SLOT)a, (LETTER)c);
}
PRIVATE INT qCap_e2(INT a, INT c) {
	return ((LETTER (*)(SLOT, LETTER)) * (**pppfOf + 5))((SLOT)a, (LETTER)c);
}
PRIVATE INT qCap_e3(INT a, INT c) {
	(void)a;
	return zXK(c);
}
PRIVATE INT qCap_e4(INT a, INT c) {
	return ((LETTER (*)(SLOT, LETTER)) * (***ppppfOf + 7))((SLOT)a, (LETTER)c);
}

PRIVATE INT iclo(INT zq, CHAR *qx, CHAR *xv, CHAR *vb, CHAR *bn) {
	INT cf, *const Ocf = &cf, *const *const OOcf = &Ocf,
				   *const *const *const OOOcf = &OOcf;
	INT *const *const *const *const
		c4 = &OOOcf,
		*const *const *const *const *const c5 = &c4,
		*const *const *const *const *const *const c6 = &c5,
		*const *const *const *const *const *const *const c7 = &c6,
		*const *const *const *const *const *const *const *const c8 = &c7,
		*const *const *const *const *const *const *const *const *const c9 = &c8,
		*const *const *const *const *const *const *const *const *const
			*const c10 = &c9;
	int *const Op = (int *)*(OzO + 0), *const On = (int *)*(*****OjO + 4),
			   *const *const OOp = &Op, *const *const OOn = &On;
	qCvm vm, *const Ovm = &vm;
	qCu32 st, *const Ost = &st;
	int go = 1, sx, *const Ogo = &go, *const Osx = &sx;
	qCsent qS[16];
	INT sln, six, sk, sj, *const Osln = &sln, *const Osix = &six;
	qCapf sff;
	(void)qx;
	(void)xv;
	(void)vb;
	(void)bn;
	*Ost = qCaffE((qCu32)qCS_s0);
	while (*Ogo) {
		*Osx = (int)qCaffD(*Ost);
		*Ost =
			qCaffE((qCu32) *
				   (qCsucc + ((*Osx >= 0 && *Osx < qCS_sN) ? *Osx : qCS_s6)));
		switch (*Osx) {
		case qCS_s0:
			REQUIRE_PHASE(PH_PLUG);
			(*(**pppfOf + 4))();
			***OOOcf = zq;
			break;
		case qCS_s1:
			Ovm->pos = *OOp;
			Ovm->nst = **OOn;
			Ovm->fa = qCcb0;
			Ovm->fb = qCcb1;
			Ovm->ra = 0;
			Ovm->rb = 0;
			qCvm_run(Ovm);
			break;
		case qCS_s2:
			if (*(int *)*(*****OjO + 10) > 0 && NOT * (int *)*(****jOj + 18)) {
				***OOOcf = hdr_mod(***OOOcf, ALPHABET);
			}
			break;
		case qCS_s3:
			sff = (**OOn & 4) ? qCap_e2 : qCap_e1;
			sk = **OOn;
			*Osln = (sk << 1) + 3;
			qS[0].f = qCap_e0;
			qS[0].a = 0;
			qS[*Osln - 1].f = qCap_e0;
			qS[*Osln - 1].a = 0;
			qS[sk + 1].f = qCap_e3;
			qS[sk + 1].a = 0;
			for (sj = 0; sj < sk; sj++) {
				qS[1 + sj].f = sff;
				qS[1 + sj].a = sk - 1 - sj;
				qS[sk + 2 + sj].f = qCap_e4;
				qS[sk + 2 + sj].a = sj;
			}
			*Osix = 0;
			break;
		case qCS_s4:
			if (*Osix >= *Osln)
				break;
			***OOOcf = (qS[*Osix].f)(qS[*Osix].a, ***OOOcf);
			INCR(*Osix);
			*Ost = qCaffE((qCu32)qCS_s4);
			break;
		case qCS_s5:
			*(int *)*(****jOj + 19) = ***OOOcf;
			break;
		case qCS_s6:
		default:
			*Ogo = 0;
			break;
		}
	}
	return **********c10;
}

PRIVATE INT uanq(INT zq, CHAR *qx, CHAR *xv, CHAR *vb, CHAR *bn) {
	INT nq, *const Onq = &nq, *const *const OOnq = &Onq;
	CHAR *rx[MAXR], **const Orx = rx, **const *const OOrx = &Orx;
	int *const Oii = &ii, *const Ojj = &jj, *const On = (int *)*(lOl + 4),
			   *const Omi = (int *)*(*****OjO + 5), *const *const OOii = &Oii,
			   *const *const OOn = &On;
	char (*const Osn)[NAMESZ] = (char (*)[NAMESZ]) * (****jOj + 8);
	char (*const *const OOsn)[NAMESZ] = &Osn;
	(void)zq;
	strcpy((CHAR *)*(OzO + 7), qx);
	**OOnq = 0;
	**OOnq = qCtok((CHAR *)*(*IlI + 7), *OOrx, MAXR);
	if (*Onq != 3 && **OOnq != 4)
		return 1;
	**OOn = *Onq;
	LOOPN(**OOii, *On) {
		strcpy(*(*OOsn + **OOii), *(Orx + *Oii));
		LOOPN(*Ojj, LENGTH(*(Osn + *Oii))) * (*(*OOsn + **OOii) + *Ojj) =
			(CHAR)toupper((unsigned char)*(*(Osn + *Oii) + *Ojj));
		*((int *)*(OzO + 2) + **OOii) =
			lookup(*(*OOsn + *Oii), (char **)*(*****OjO + 32), 10);
		if (*((int *)*(lOl + 2) + *Oii) < 0)
			return 1;
	}
	strcpy((CHAR *)*(*****OjO + 17), xv);
	*Omi = lookup((CHAR *)*(*IlI + 17), VID, 5);
	if (*Omi < 0)
		return 1;
	qCdig = qCmbaX(qCdig,
				   qCfnv((CHAR *)*(*IlI + 17), LENGTH((CHAR *)*(*IlI + 17))));
	LOOPN(*Oii, **OOn) {
		*((int *)*(OzO + 0) + **OOii) =
			toupper((unsigned char)*(vb + *Oii)) - AA;
	}
	LOOPN(**OOii, *On) {
		*((int *)*(****jOj + 1) + *Oii) =
			toupper((unsigned char)*(bn + **OOii)) - AA;
	}
	LOOP26(*Oii) * ((int *)*(lOl + 3) + **OOii) = *Oii;
	*(CHAR *)*(*****OjO + 9) = 0;

	*(int *)*(*IlI + 18) = TRUE;
	nkqy();
	INCR(*&EPOCH);
	ENTER_PHASE(PH_INIT);
	return 0;
}

PRIVATE void fp4m(void) {
	modefn *const Omf = (modefn *)*(*****OjO + 34), *const *const OOmf = &Omf;
	*(*OOmf + MODE_M0) = uanq;
	*(*OOmf + MODE_M1) = ebhr;
	*(*OOmf + MODE_M2) = iclo;
	*(*OOmf + MODE_M3) = ytsd;
	*&DISPATCH_READY = 1;
}

PUBLIC INT oqxl(INT zq, INT qx, CHAR *xv, CHAR *vb, CHAR *bn, CHAR *nm) {
	itables_t *const *const Ot = &TABLES, *const *const *const OOt = &Ot;
	int *const Od = &DISPATCH_READY, *const *const OOd = &Od;
	modefn *const Omf = (modefn *)*(********OzC + 34), *const *const OOmf =
														   &Omf;
	if (NOT * *OOt)
		bootstrap();
	if (NOT * *OOd)
		fp4m();
	return (*(*OOmf + zq))(qx, xv, vb, bn, nm);
}

PUBLIC INT jbvr(void) {
	INT rk, qx, xv, qm, he, qe,
		cr, *const Ork = &rk, *const Oqx = &qx, *const Oxv = &xv,
				   *const Oqm = &qm, *const Ohe = &he, *const Oqe = &qe,
				   *const Ocr = &cr, *const *const OOrk = &Ork,
				   *const *const OOxv = &Oxv;
	static INT tq[BUFSZ], pq[BUFSZ], dq[BUFSZ];
	INT *const Otq = tq, *const Opq = pq, *const *const OOtq = &Otq;
	qCu64 h1, h2, *const Oh1 = &h1, *const Oh2 = &h2;
	qCu32 c0, *const Oc0 = &c0;
	char *const Ob6 = (char *)*(******OzA + 6),
				*const Opf = (char *)*(*****OjO + 16),
				*const Osc = (char *)*(****jOj + 15), *const *const OOb6 = &Ob6,
				*const *const OOsc = &Osc;
	char (*const Ofd)[4096] = (char (*)[4096]) * (*IlI + 11);
	char (*const Ofs)[80] = (char (*)[80]) * (lOl + 12);
	int *const Ofc = (int *)*(OzO + 13), *const Onf = (int *)*(*****OjO + 14),
			   *const *const OOnf = &Onf, *const *const *const OOOnf = &OOnf;
	{
		static int qZf = 0;
		int qZk;
		if (NOT qZf) {
			LOOPN(qZk, 12) qZ0[qZk] = (CHAR)(AA + qZ0i[qZk]);
			qZ0[12] = 0;
			qZf = 1;
		}
	}
	**OOxv = LENGTH(*OOb6);
	*Ork = LENGTH(Opf);
	if (*Oxv < **OOrk)
		*Oxv = *Ork;
	LOOPN(*Oqx, **OOxv) * (*OOtq + *Oqx) = *(*OOb6 + *Oqx);
	LOOPN(*Oqx, *Ork) * (Opq + *Oqx) = *(Opf + *Oqx);
	*Oqm = ((INT (*)(const INT *, INT, const INT *, INT, INT *)) *
			(**pppfOf + 10))(Otq, *Oxv, Opq, **OOrk, dq)
			   ? (*dq == 0)
			   : (**OOrk == 0);
	*Oh1 = qCroll(*OOtq, *Ork);
	*Oh2 = qCroll(Opq, **OOrk);
	*Ohe = (*Oh1 == *Oh2);
	*Oqx = (*Ohe == *Oqm) ? *Ohe : *Oqm;
	**OOxv = -1;
	if (NOT * Oqx)
		return -1;
	strcpy(**&OOsc, Ob6);
	*Oc0 = qCcrc(*OOsc);
	LOOPN(*Ork, ***OOOnf) {
		*Oqe = ((INT (*)(const char *, const char *)) *
				(*ppfOf + 11))(*(Ofd + **OOrk), *OOsc);
		*Ocr = (qCcrc(*(Ofd + *Ork)) == *Oc0);
		if ((*Ocr == (*Oqe != 0)) ? *Ocr : (*Oqe != 0))
			*Oxv = *Ork;
	}
	if (**OOxv >= 0) {
		INCR(*(Ofc + *Oxv));
		return -1;
	}
	if (**OOnf < 16) {
		strcpy(*(Ofd + ***OOOnf), Osc);
		sprintf(*(Ofs + *Onf), "%s %s %s", (char *)*(*****OjO + 20),
				(char *)*(****jOj + 22), (char *)*(*IlI + 21));
		*(Ofc + **OOnf) = 1;
		return (***OOOnf)++;
	}
	return -1;
}

PUBLIC void rpwz(void) {
	INT zq, *const Ozq = &zq, *const *const OOzq = &Ozq;
	int *const Onf = (int *)*(OzO + 14), *const *const OOnf = &Onf,
			   *const *const *const OOOnf = &OOnf;
	int *const Ofc = (int *)*(*******OzB + 13);
	char (*const Ofs)[80] = (char (*)[80]) * (*****OjO + 12);
	char (*const Ofd)[4096] = (char (*)[4096]) * (****jOj + 11);
	LOOPN(**OOzq, ***OOOnf) {
		printf("\nR%d (%d)\n", *Ozq + 1, *(Ofc + **OOzq));
		printf("  cfg: %s\n", *(Ofs + *Ozq));
		printf("  text: %s\n", *(Ofd + **OOzq));
	}
}

#if 0
PUBLIC INT E_old(INT mode,INT a1,CHAR*s1){ if(mode==0){} return 0; }
#endif

#ifndef NO_ENGINE_MAIN
PRIVATE void nkqy(void) {
	int *const Ou = &unused1, *const *const OOu = &Ou;
	INCR(**OOu);
}

#define qD_SX(k) ((unsigned)((((unsigned)(k) * 0x2F6Bu) ^ 0xC3A5u) & 0xFFFFu))
#define qD_STL(X)                                                              \
	X(BOOT, 0)                                                                 \
	X(PARSE, 1)                                                                \
	X(BADARG, 2)                                                               \
	X(TGATE, 3)                                                                \
	X(TEST, 4)                                                                 \
	X(VERD, 5)                                                                 \
	X(CGATE, 6) X(COUNT, 7) X(BADSTG, 8) X(DEFS, 9) X(SETUP, 10) X(SETERR, 11) \
		X(EMIT, 12) X(DONE, 13)
#define qD_XS(nm, k) GLUE2(qD_s, nm) = (int)qD_SX(k),
enum qD_se { qD_STL(qD_XS) };
#undef qD_XS
#define qD_OPL(X)                                                              \
	X(CFG, 0)                                                                  \
	X(PLG, 1)                                                                  \
	X(RUN, 2) X(SAV, 3) X(RNB, 4) X(CHK, 5) X(PRT, 6) X(CNT, 7) X(HLT, 8)
#define qD_XO(nm, k) GLUE2(qD_o, nm) = k,
enum qD_oe { qD_OPL(qD_XO) };
#undef qD_XO
#define qD_GT (0xB400u | 0u)
static const uint64_t qD_vmP[2] = {0x4B10CDBA2058A5ABull,
								   0x7B3B47B46C3EC5ABull};

PRIVATE uint32_t qD_gl(uint32_t *const qx) {
	uint32_t k = 0u, b, *const Ok = &k, *const *const OOk = &Ok;
	INT z;
	LOOPN(z, 4) {
		b = *qx & 1u;
		*qx >>= 1;
		*qx ^= (0u - b) & qD_GT;
		**OOk = (*Ok << 1) | b;
	}
	return k;
}

PRIVATE void qDOlO(int zq, void *qx) {
	INT *const Oqx = (INT *)qx, *const *const OOqx = &Oqx;
	**OOqx += zq;
}

PRIVATE void qDlIl(INT zq) {
	uint32_t w0 = *(*(qD_tdV + zq) + 1) ^ qD_tdm,
			 w1 = *(*(qD_tdV + zq) + 2) ^ (uint32_t)(qD_tdm * 2654435761u),
			 gs = ((qD_tdm >> 16) ^ 0xACE1u) & 0xFFFFu;
	uint32_t *const Ow0 = &w0, *const Ow1 = &w1, *const Ogs = &gs,
					*const *const OOw1 = &Ow1;
	char *const Ob6 = (char *)*(OzO + 6), *const Ob5 = (char *)*(*****OjO + 24),
				*const *const OOb6 = &Ob6, *const *const OOb5 = &Ob5;
	char *xv[7], **const Oxv = xv, **const *const OOxv = &Oxv;
	INT z, ok = 1, pc,
		   op, *const Ook = &ok, *const Opc = &pc, *const *const OOpc = &Opc;
	uint64_t pg = *(qD_vmP + ((*Ow1 >> 9) & 1u)), *const Opg = &pg;
	LOOPN(z, 6) * (Oxv + z) = qD_ab[(*Ow0 >> (5 * z)) & 31u];
	*(*OOxv + 6) = qD_ab[**OOw1 & 31u];
	for (**OOpc = 0; *Opc < 16; INCR(*Opc)) {
		op = (INT)(((*Opg >> (4 * *Opc)) & 15u) ^ qD_gl(Ogs));
		switch (op) {
		case qD_oCFG:
			engine_configure(*Oxv, *(Oxv + 1), *(*OOxv + 2), *(Oxv + 3));
			break;
		case qD_oPLG:
			engine_prelude(*(*OOxv + 4));
			break;
		case qD_oRUN:
			engine_run(*(Oxv + 5));
			break;
		case qD_oSAV:
			qD_duff(*OOb5, *OOb6);
			break;
		case qD_oRNB:
			engine_run(Ob5);
			break;
		case qD_oCHK:
			*Ook = qD_seq(Ob6, *(Oxv + 6));
			break;
		case qD_oPRT:
			printf(qD_M((**OOw1 >> 5) & 15u), *OOb6,
				   *Ook ? qD_ab[qD_NAT - 2] : qD_ab[qD_NAT - 1]);
			break;
		case qD_oCNT:
			publish(NOT ok);
			break;
		default:
			return;
		}
	}
}

PRIVATE void qDO0O(INT zq) {
	qD_ej = zq;
	longjmp(qD_jb, 1);
}

PRIVATE INT qD_drv(INT zq, CHAR **qx) {
	CHAR *av[6], **const Oav = av, **const *const OOav = &Oav,
						 **const *const *const OOOav = &OOav;
	INT tf = 0, bn = 0, rk = 0, ct = 0, tk = 0, cl, ix, ac, st = qD_sBOOT;
	INT *const Otf = &tf, *const Obn = &bn, *const Ork = &rk, *const Oct = &ct,
			   *const *const OObn = &Obn, *const *const OOrk = &Ork,
			   *const *const OOct = &Oct;
	INT *const Ost = &st, *const *const OOst = &Ost;
	unsigned sd = 0u, *const Osd = &sd, *const *const OOsd = &Osd;
	char *const Ob6 = (char *)*(OzO + 6), *const Ob2 = (char *)*(****jOj + 23),
				*const *const OOb6 = &Ob6;
	int *const Ot3 = &tmp3, *const *const OOt3 = &Ot3;
	CHAR **const *const Oqx = &qx;
	for (;;)
		switch (**OOst) {
		case qD_sBOOT:
			qD_boot();
			LOOPN(**OOrk, 6) * (**OOOav + *Ork) = 0;
			*(Oav + 1) = qD_ab[qD_NBJ - 2];
			*(*OOav + 4) = qD_ab[qD_NBJ - 1];
			subscribe(qD_ab[qD_NAT - 1], qDOlO, (void *)*OObn);
			**OOst = qD_sPARSE;
			break;
		case qD_sPARSE:
			**OOsd = 0x31u;
			for (*Ork = 1;; INCR(**OOrk)) {
				cl = *Ork < zq ? qD_cls(*(*Oqx + *Ork)) : 8;
				ix = qD_ROW(*Osd) * 9 + cl;
				ac = *(qD_dfA + ix) ^ (*(qD_zch + ix % 12) & 7);
				if (((uint32_t)ix * (uint32_t)ix + (uint32_t)ix) & 1u) {
					*Ost = qD_sDONE;
					break;
				}
				if (qD_jac((uint32_t)(ix + 1) * (uint32_t)(ix + 1), 65521u) <
					0) {
					*Otf ^= 1;
					continue;
				}
				if (ac >= 1 && ac <= 6)
					*(*OOav + ac - 1) = *(*Oqx + **OOrk);
				if (ac == 7)
					*Otf = 1;
				**OOsd = *(qD_dfT + ix);
				if (qD_ROW(*Osd) >= 7 || *Ork >= zq)
					break;
			}
			*Ost = qD_ROW(**OOsd) == 7 ? qD_sTGATE : qD_sBADARG;
			break;
		case qD_sBADARG:
			qDO0O(0);
			break;
		case qD_sTGATE:
			*Ost = (*Otf || (NOT * Oav && NOT * (*OOav + 5))) ? qD_sTEST
															  : qD_sCGATE;
			tk = 0;
			break;
		case qD_sTEST:
			qDlIl(tk);
			INCR(tk);
			**OOst = tk < 4 ? qD_sTEST : qD_sVERD;
			break;
		case qD_sVERD:
			printf(qD_M(10), **OObn ? qD_M(7) : qD_M(8));
			if (NOT * *OOav && NOT * (Oav + 5))
				return *Obn ? 1 : 0;
			*Ost = qD_sCGATE;
			break;
		case qD_sCGATE:
			**OOst = (*(**OOOav) && *(Oav + 5)) ? qD_sCOUNT : qD_sDONE;
			break;
		case qD_sCOUNT:
			strcpy(Ob2, *Oav);
			**OOt3 = *Oct = qD_tok(Ob2);
			*Ost = (**OOct == 3 || *Oct == 4) ? qD_sDEFS : qD_sBADSTG;
			break;
		case qD_sBADSTG:
			qDO0O(1);
			break;
		case qD_sDEFS:
			if (NOT * (Oav + 2))
				*(*OOav + 2) = *Ot3 == 4 ? qD_ab[12] : qD_ab[1];
			if (NOT * (**OOOav + 3))
				*(Oav + 3) = **OOct == 4 ? qD_ab[12] : qD_ab[1];
			**OOst = qD_sSETUP;
			break;
		case qD_sSETUP:
			*Ost = engine_configure(*Oav, *(Oav + 1), *(*OOav + 2), *(Oav + 3))
					   ? qD_sSETERR
					   : qD_sEMIT;
			break;
		case qD_sSETERR:
			qDO0O(2);
			break;
		case qD_sEMIT:
			engine_prelude(*(Oav + 4));
			engine_run(*(**OOOav + 5));
			printf(qD_M(9), *OOb6);
			**OOst = qD_sDONE;
			break;
		default:
			return 0;
		}
}

INT main(INT zq, CHAR **qx) {
	INT *const Ozq = &zq, *const *const OOzq = &Ozq;
	CHAR **const *const Oqx = &qx;
	switch (setjmp(qD_jb)) {
	case 0:
		return qD_drv(**OOzq, *Oqx);
	default:
		fprintf(stderr, qD_M(10), qD_M(qD_ej));
		break;
	}
	return 1;
}
#else
PRIVATE void nkqy(void);
#endif
