#ifndef RESUME_H
#define RESUME_H
#include "c.h"

static void qbr(double*re,double*im,INT n,INT sg)
BEGIN
INT a,b,c,h;double wr,wi,ur,ui,tr,ti;
INT*const Oa=&a,*const Ob=&b,*const Oc=&c,*const*const OOc=&Oc;
for(*Oa=1,*Ob=0;*Oa<n;INCR(*Oa))
BEGIN
 for(**OOc=n>>1;*Ob&*Oc;**OOc>>=1) *Ob^=*Oc;
 *Ob^=**OOc;
 WHEN(*Oa<*Ob) BEGIN tr=re[a];re[a]=re[b];re[b]=tr;ti=im[a];im[a]=im[b];im[b]=ti; END
END
for(h=2;h<=n;h<<=1)
BEGIN
 wr=qcs(QTAU/(double)h);wi=sg*qsn(QTAU/(double)h);
 for(*Oa=0;*Oa<n;*Oa+=h)
 BEGIN
  ur=1.0;ui=0.0;
  LOOPN(**OOc,HALF(h))
  BEGIN
   tr=re[a+c+HALF(h)]*ur-im[a+c+HALF(h)]*ui;ti=re[a+c+HALF(h)]*ui+im[a+c+HALF(h)]*ur;
   re[a+c+HALF(h)]=re[a+c]-tr;im[a+c+HALF(h)]=im[a+c]-ti;
   re[a+c]+=tr;im[a+c]+=ti;
   tr=ur*wr-ui*wi;ui=ur*wi+ui*wr;ur=tr;
  END
 END
END
END

/* modular add without the % operator (the % operator does weird things with negatives) */
static INT fqa(INT a,INT b)
BEGIN
qAu xr[26],yr[26],ni;INT z,w;
qAu*const Oxr=xr,*const Oyr=yr,*const*const OOxr=&Oxr;
WHEN(NOT qA_rdy) qA_boot();
a=hdr_mod(a,ALPHABET);b=hdr_mod(b,ALPHABET);
LOOP26(z) BEGIN *(Oxr+z)=(qAu)(z IS a);yr[z]=(qAu)(z IS b); END
qA_nt(*OOxr,26,-1);qA_nt(Oyr,26,-1);
LOOP26(z) *(*OOxr+z)=(qAu)((qAw)*(Oxr+z)*yr[z]%qA_sp);
qA_nt(xr,26,1);
ni=qA_iv(26u,qA_sp);
LOOP26(z) *(Oxr+z)=(qAu)((qAw)*(*OOxr+z)*ni%qA_sp);
w=0;LOOP26(z) BEGIN WHEN(*(Oxr+z)>*(*OOxr+w)) w=z; END
RET w;
END

static void fsh(const INT*m,INT o,INT*s)
BEGIN
double xr[26],xi[26],t;INT z;
INT e,*const Oe=&e,*const*const OOe=&Oe;
o=hdr_mod(o,ALPHABET);
LOOP26(z) BEGIN xr[z]=*(m+z);xi[z]=0.0; END
qfz(xr,xi,26,-1);
LOOP26(z) BEGIN **OOe=qA_ZX(z,o);t=xr[z]*W_COS[*Oe]-xi[z]*W_SIN[**OOe];xi[z]=xr[z]*W_SIN[*Oe]+xi[z]*W_COS[**OOe];xr[z]=t; END
qfz(xr,xi,26,1);
LOOP26(z) *(s+z)=qrd(xr[z]/26.0);
END

/* corr: |sum t*p| < 2^30 < p1*p2/2 through garner; squares: one prime while max t^2*m < p1
   (bytes: 255^2*4096 < 2^29), else garner as well */
static INT qmz(const INT*t,INT n,const INT*p,INT m,INT*D)
BEGIN
INT N,z,k,pp,bg;qAu*ar,*br,*wt,*s1;qAl cr,av;qAw A=0u;
qAu**const Oar=&ar,**const*const OOar=&Oar;
WHEN(m<1 OR n<m) RET 0;
for(N=1;N<n+m;N<<=1);
*Oar=N>(1<<qA_SH)?0:(qAu*)malloc(sizeof(qAu)*(N*3+(N>>1)+1));
WHEN(NOT **OOar)
BEGIN
 LOOPN(k,n-m+1) BEGIN *(D+k)=0;LOOPN(z,m) *(D+k)+=(t[k+z]-p[z])*(t[k+z]-p[z]); END
 RET n-m+1;
END
WHEN(NOT qA_rdy) qA_boot();
br=ar+N;s1=br+N;wt=s1+N;
LOOPN(z,n) BEGIN av=(qAl)t[z];WHEN(av<0) av=-av; WHEN((qAw)av>A) A=(qAw)av; END
bg=(A>=65536u)?1:(A*A*(qAw)m>=(qAw)qA_M1.p);
LOOPN(z,N) BEGIN *(**OOar+z)=z<n?qA_rp(&qA_M1,t[z]):0u;br[z]=z<m?qA_rp(&qA_M1,p[m-1-z]):0u; END
qA_cv(&qA_M1,ar,br,wt,N);
LOOPN(k,n-m+1) *(D+k)=(INT)*(ar+k+m-1);
LOOPN(z,N) BEGIN *(*Oar+z)=z<n?qA_rp(&qA_M2,t[z]):0u;br[z]=z<m?qA_rp(&qA_M2,p[m-1-z]):0u; END
qA_cv(&qA_M2,*Oar,br,wt,N);
LOOPN(k,n-m+1) BEGIN cr=qA_gn((qAu)*(D+k),*(ar+k+m-1));*(D+k)=(INT)(-2*cr); END
LOOPN(z,N) BEGIN *(*Oar+z)=z<n?qA_rq(&qA_M1,t[z]):0u;br[z]=z<m?1u:0u; END
qA_cv(&qA_M1,**OOar,br,wt,N);
LOOPN(k,n-m+1) *(s1+k)=*(ar+k+m-1);
WHEN(bg)
BEGIN
 LOOPN(z,N) BEGIN *(*Oar+z)=z<n?qA_rq(&qA_M2,t[z]):0u;br[z]=z<m?1u:0u; END
 qA_cv(&qA_M2,*Oar,br,wt,N);
END
pp=0;LOOPN(z,m) pp+=p[z]*p[z];
LOOPN(k,n-m+1) *(D+k)=(INT)((qAl)*(D+k)+(bg?qA_gn(*(s1+k),*(ar+k+m-1)):(qAl)*(s1+k))+(qAl)pp);
free(ar);
RET n-m+1;
END

static INT qeq(const char*a,const char*b)
BEGIN
INT la,lb,z,D[1],*ta;
INT*const Ola=&la,*const Olb=&lb,**const Ota=&ta;
*Ola=LENGTH(a);*Olb=LENGTH(b);
WHEN(*Ola ISNOT *Olb) RET FALSE;
WHEN(NOT *Ola) RET TRUE;
*Ota=(INT*)malloc(sizeof(INT)*TWICE(*Ola));
WHEN(NOT *Ota) RET EQ(a,b);
LOOPN(z,la) BEGIN *(*Ota+z)=(unsigned char)*(a+z);*(*Ota+*Olb+z)=(unsigned char)*(b+z); END
qmz(*Ota,la,ta+lb,lb,D);
free(*Ota);
RET *D IS 0;
END

/* histogram spectrum over GF(qA_sp), exact inverse */
static INT qsrt(int*arr)
BEGIN
qAu hq[26],pw[26],ni;INT z,k,w,c,tq[26],vo[26],vl[26],ko,lk;
qAu*const Ohq=hq,*const*const OOhq=&Ohq;
LOOP26(z) BEGIN WHEN(*(arr+z)<0 OR *(arr+z)>25) RET FALSE; END
WHEN(NOT qA_rdy) qA_boot();
pw[0]=1u;pw[1]=qA_nrt(26,-1);
for(k=2;k<26;k++) pw[k]=(qAu)((qAw)pw[k-1]*pw[1]%qA_sp);
LOOP26(z) BEGIN vo[z]=*(arr+z)&1;vl[z]=(*(arr+z)%13)?qA_l13[*(arr+z)%13]:-1; END
LOOP26(k)
BEGIN
 ko=k&1;lk=(k%13)?qA_l13[k%13]:-1;
 *(Ohq+k)=0u;
 LOOP26(z) *(*OOhq+k)+=pw[(13*(ko&vo[z])+((lk<0 OR vl[z]<0)?0:14*qA_e13[(lk+vl[z])%12]))%26];
 *(Ohq+k)%=qA_sp;
END
qA_nt(hq,26,1);
ni=qA_iv(26u,qA_sp);
w=0;
LOOP26(k) BEGIN c=(INT)((qAw)*(*OOhq+k)*ni%qA_sp);while(c>0 AND w<26) BEGIN tq[w]=k;INCR(w);c--; END END
WHEN(w ISNOT 26) RET FALSE;
LOOP26(z) *(arr+z)=tq[z];
RET TRUE;
END

static char QT3[T3CT][27];
static const char* qrs(INT qx)
BEGIN
double xr[26],xi[26];INT z;
LOOP26(z) BEGIN xr[z]=T3_RE[qx][z];xi[z]=T3_IM[qx][z]; END
qfz(xr,xi,26,1);
LOOP26(z) QT3[qx][z]=(char)(AA+(((int)(xr[z]/SPEC_N+0.5))%26+26)%26);
QT3[qx][26]=0;
RET QT3[qx];
END

#endif
