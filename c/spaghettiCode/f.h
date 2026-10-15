#ifndef FASTPATH_H
#define FASTPATH_H
#include "c.h"

#define QPI 3.14159265358979323846
#define QTAU (QPI+QPI)
#define QHALF (QPI/2)
#define QMAXN 8192

static double QZR[QMAXN],QZI[QMAXN];

/* octant series: q&1 selects cos, q&2 negates */
static double qA_ts(double r,INT q)
BEGIN
double t,u,v;INT z;
double*const Ot=&t,*const Ou=&u,*const*const OOt=&Ot,*const*const OOu=&Ou;
v=r*r;
WHEN(q&1) BEGIN **OOt=1.0;**OOu=1.0; for(z=1;z<14;z++) BEGIN *Ot=-*Ot*v/(double)((2*z-1)*(2*z));**OOu+=**OOt; END END
OTHERWISE BEGIN **OOt=r;**OOu=r; for(z=1;z<14;z++) BEGIN **OOt=-**OOt*v/(double)((2*z)*(2*z+1));*Ou+=*Ot; END END
RET (q&2)?-u:u;
END

static double qA_ra(double x,INT*q)
BEGIN
double k;
WHEN(NOT(x<qA_BIGA)) BEGIN while(x>=QTAU) x-=QTAU; END
k=(double)(long long)(x*qA_2OPI+0.5);
*q=(INT)((long long)k&3);
RET (x-k*qA_PIO2A)-k*qA_PIO2B;
END

static double qsn(double x)
BEGIN
double s=1.0,r;INT q;
WHEN(x ISNOT x) RET x;
WHEN(x<0.0) BEGIN x=-x;s=-s; END
r=qA_ra(x,&q);
RET s*qA_ts(r,q);
END

static double qcs(double x)
BEGIN
double r;INT q;
WHEN(x ISNOT x) RET x;
WHEN(x<0.0) x=-x;
r=qA_ra(x,&q);
RET qA_ts(r,(q+1)&3);
END

static INT qrd(double x)
BEGIN
WHEN(x<0.0) RET -(INT)(-x+0.5);
RET (INT)(x+0.5);
END

static void qdz(double*re,double*im,INT n,INT sg)
BEGIN
INT k,z;double xr,xi,c,s;
LOOPN(k,n)
BEGIN
 xr=0.0;xi=0.0;
 LOOPN(z,n)
 BEGIN
  c=qcs(QTAU*(double)((k*z)%n)/(double)n);s=sg*qsn(QTAU*(double)((k*z)%n)/(double)n);
  xr+=re[z]*c-im[z]*s;xi+=re[z]*s+im[z]*c;
 END
 QZR[k]=xr;QZI[k]=xi;
END
LOOPN(k,n) BEGIN re[k]=QZR[k];im[k]=QZI[k]; END
END

#include "j.h"

/* 26 = 2*13 prime factor split; 13 by rader over 12 = 4*3 */
static void qfz(double*re,double*im,INT n,INT sg)
BEGIN
double*const Ore=re,*const Oim=im,*const*const OOre=&Ore,*const*const*const OOOre=&OOre;
WHEN(n<2) RET;
WHEN(NOT qA_rdy) qA_boot();
INCR(qA_ep);
qA_fz(**OOOre,Oim,n,sg);
END

#endif
