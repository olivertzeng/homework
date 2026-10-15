#ifndef qA_JH
#define qA_JH
#include "c.h"
#include "i.h"

#define qA_CN 56
#define qA_NMAX 64

static void qbr(double*,double*,INT,INT);
static void qA_fz(double*,double*,INT,INT);

static double qA_cat[qA_CN],qA_cp2[qA_CN],qA_ckg=1.0;

static void qA_cin(void)
BEGIN
INT i,k;double x,t,s,g=1.0;
qA_cp2[0]=1.0;qA_cat[0]=QPI/4.0;
for(i=1;i<qA_CN;i++)
BEGIN
 qA_cp2[i]=qA_cp2[i-1]*0.5;x=qA_cp2[i];t=x;s=x;
 for(k=1;k<48;k++) BEGIN t=-t*x*x;s+=t/(double)(2*k+1); END
 qA_cat[i]=s;
END
LOOPN(i,qA_CN) g*=1.0+qA_cp2[i]*qA_cp2[i];
qA_ckg=1.0/qA_sq(g);
END

/* rotation-mode cordic on the octant-reduced angle, first-order residual fold */
static void qA_cr(double th,double*co,double*si)
BEGIN
double x,y,z,d,t,sg=1.0,*const Ox=&x,*const Oy=&y,*const*const OOx=&Ox,*const*const OOy=&Oy;
qAl k;INT i,q;
WHEN(th<0.0) BEGIN th=-th;sg=-1.0; END
WHEN(NOT(th<qA_BIGA)) BEGIN *co=qcs(th);*si=sg*qsn(th);RET; END
k=(qAl)(th*qA_2OPI+0.5);
z=(th-(double)k*qA_PIO2A)-(double)k*qA_PIO2B;
q=(INT)(k&3);
**OOx=qA_ckg;**OOy=0.0;
LOOPN(i,qA_CN)
BEGIN
 d=(z>=0.0)?1.0:-1.0;
 t=*Ox-d**Oy*qA_cp2[i];**OOy=*Oy+d**Ox*qA_cp2[i];**OOx=t;
 z-=d*qA_cat[i];
END
t=x-z*y;y=y+z*x;x=t;
switch(q)
BEGIN
 case 0: *co=x;*si=y;break;
 case 1: *co=-y;*si=x;break;
 case 2: *co=-x;*si=-y;break;
 default: *co=y;*si=-x;break;
END
*si*=sg;
END

static void qA_k2(double*re,double*im)
BEGIN
double tr=re[0]-re[1],ti=im[0]-im[1];
re[0]+=re[1];im[0]+=im[1];re[1]=tr;im[1]=ti;
END

static void qA_k3(double*re,double*im,INT sg)
BEGIN
double c=qcs(QTAU/3.0),h=sg*qsn(QTAU/3.0),sr,si,dr,di,mr,mi;
double*const Or=re,*const Oi=im,*const*const OOr=&Or,*const*const OOi=&Oi;
sr=*(Or+1)+*(Or+2);si=*(Oi+1)+*(Oi+2);dr=*(*OOr+1)-*(*OOr+2);di=*(*OOi+1)-*(*OOi+2);
mr=*Or+c*sr;mi=*Oi+c*si;
**OOr+=sr;**OOi+=si;
*(Or+1)=mr-h*di;*(Oi+1)=mi+h*dr;
*(*OOr+2)=mr+h*di;*(*OOi+2)=mi-h*dr;
END

static void qA_k4(double*re,double*im,INT sg)
BEGIN
double ar=re[0]+re[2],ai=im[0]+im[2],br=re[0]-re[2],bi=im[0]-im[2];
double cr=re[1]+re[3],ci=im[1]+im[3],dr=re[1]-re[3],di=im[1]-im[3];
re[0]=ar+cr;im[0]=ai+ci;re[2]=ar-cr;im[2]=ai-ci;
re[1]=br-sg*di;im[1]=bi+sg*dr;
re[3]=br+sg*di;im[3]=bi-sg*dr;
END

/* smallest-prime mixed radix with explicit twiddles */
static void qA_ct(double*re,double*im,INT n,INT sg)
BEGIN
INT p,m,r,k,q,e;double*ar,*ai,*br,*bi,*wr,*wi,xr,xi;
double**const Oar=&ar,**const*const OOar=&Oar;
for(p=2;p*p<=n AND n%p;p++);
WHEN(p*p>n) p=n;
m=n/p;
*Oar=(double*)malloc(sizeof(double)*n*6);
WHEN(NOT **OOar) BEGIN qdz(re,im,n,sg);RET; END
ai=*Oar+n;br=ai+n;bi=br+n;wr=bi+n;wi=wr+n;
LOOPN(k,n) BEGIN *(wr+k)=qcs(QTAU*(double)k/(double)n);*(wi+k)=sg*qsn(QTAU*(double)k/(double)n); END
LOOPN(r,p) LOOPN(k,m) BEGIN *(**OOar+r*m+k)=*(re+r+p*k);*(ai+r*m+k)=*(im+r+p*k); END
WHEN(m>1) LOOPN(r,p) qA_fz(ar+r*m,ai+r*m,m,sg);
LOOPN(k,m) LOOPN(q,p)
BEGIN
 xr=0.0;xi=0.0;
 LOOPN(r,p)
 BEGIN
  e=(r*(k+m*q))%n;
  xr+=*(ar+r*m+k)**(wr+e)-*(ai+r*m+k)**(wi+e);
  xi+=*(ar+r*m+k)**(wi+e)+*(ai+r*m+k)**(wr+e);
 END
 *(br+k+m*q)=xr;*(bi+k+m*q)=xi;
END
LOOPN(k,n) BEGIN *(re+k)=*(br+k);*(im+k)=*(bi+k); END
free(**OOar);
END

/* good-thomas: ruritanian input map, crt output map, no inter-factor twiddles */
static void qA_gt(double*re,double*im,INT n1,INT n2,INT sg)
BEGIN
INT n=n1*n2,a,b,e1,e2;double*w,*wr,*wi,*vr,*vi;
double**const Ow=&w,**const*const OOw=&Ow;
**OOw=(double*)malloc(sizeof(double)*4*n);
WHEN(NOT *Ow) BEGIN qA_ct(re,im,n,sg);RET; END
wr=*Ow;wi=wr+n;vr=wi+n;vi=vr+n;
LOOPN(a,n1) LOOPN(b,n2) BEGIN *(wr+a*n2+b)=*(re+(a*n2+b*n1)%n);*(wi+a*n2+b)=*(im+(a*n2+b*n1)%n); END
LOOPN(a,n1) qA_fz(wr+a*n2,wi+a*n2,n2,sg);
LOOPN(b,n2)
BEGIN
 LOOPN(a,n1) BEGIN *(vr+b*n1+a)=*(wr+a*n2+b);*(vi+b*n1+a)=*(wi+a*n2+b); END
 qA_fz(vr+b*n1,vi+b*n1,n1,sg);
END
e1=n2*(INT)qA_iv((qAu)(n2%n1),(qAu)n1);e2=n1*(INT)qA_iv((qAu)(n1%n2),(qAu)n2);
LOOPN(b,n2) LOOPN(a,n1) BEGIN *(re+(a*e1+b*e2)%n)=*(vr+b*n1+a);*(im+(a*e1+b*e2)%n)=*(vi+b*n1+a); END
free(**OOw);
END

/* rader: prime n, generator g, length n-1 cyclic convolution against w^(g^-q);
   kernel spectrum keyed by (n,sg) inside one top-level transform */
static qAu qA_ep=0u,qA_ke=~0u;
static INT qA_kn=0,qA_ks=0;
static double qA_kbr[qA_NMAX],qA_kbi[qA_NMAX],qA_kwr[qA_NMAX],qA_kwi[qA_NMAX];
#define qA_KSPOT 3

static void qA_rd(double*re,double*im,INT n,INT sg)
BEGIN
INT L=n-1,g,gi,q,e,f,hit;double*w,*ar,*ai,*br,*bi,x0r=re[0],x0i=im[0],t;
double**const Ow=&w,**const*const OOw=&Ow;
**OOw=(double*)malloc(sizeof(double)*4*L);
WHEN(NOT *Ow) BEGIN qA_ct(re,im,n,sg);RET; END
g=(INT)qA_pr((qAu)n);gi=(INT)qA_iv((qAu)g,(qAu)n);
ar=*Ow;ai=ar+L;br=ai+L;bi=br+L;
hit=(qA_ke IS qA_ep AND qA_kn IS n AND qA_ks IS sg AND L<=qA_NMAX);
f=1;
LOOPN(q,L)
BEGIN
 WHEN(hit AND q%qA_KSPOT IS 0)
 BEGIN
  qA_cr(QTAU*(double)f/(double)n,&t,bi+q);*(bi+q)*=(double)sg;
  t-=qA_kwr[q];WHEN(t>1e-9 OR t<-1e-9 OR *(bi+q)-qA_kwi[q]>1e-9 OR *(bi+q)-qA_kwi[q]<-1e-9) hit=0;
 END
 f=f*gi%n;
END
e=1;f=1;
LOOPN(q,L)
BEGIN
 *(ar+q)=*(re+e);*(ai+q)=*(im+e);
 WHEN(hit) BEGIN *(br+q)=qA_kbr[q];*(bi+q)=qA_kbi[q]; END
 OTHERWISE BEGIN qA_cr(QTAU*(double)f/(double)n,br+q,bi+q);*(bi+q)*=(double)sg; END
 e=e*g%n;f=f*gi%n;
END
qA_fz(ar,ai,L,-1);
WHEN(NOT hit)
BEGIN
 WHEN(L<=qA_NMAX) LOOPN(q,L) BEGIN qA_kwr[q]=*(br+q);qA_kwi[q]=*(bi+q); END
 qA_fz(br,bi,L,-1);
 WHEN(L<=qA_NMAX) BEGIN LOOPN(q,L) BEGIN qA_kbr[q]=*(br+q);qA_kbi[q]=*(bi+q); END qA_ke=qA_ep;qA_kn=n;qA_ks=sg; END
END
*re=x0r+*ar;*im=x0i+*ai;
LOOPN(q,L) BEGIN t=ar[q]*br[q]-ai[q]*bi[q];ai[q]=ar[q]*bi[q]+ai[q]*br[q];ar[q]=t; END
qA_fz(ar,ai,L,1);
f=1;
LOOPN(q,L) BEGIN *(re+f)=x0r+*(ar+q)/(double)L;*(im+f)=x0i+*(ai+q)/(double)L;f=f*gi%n; END
free(**OOw);
END

static void qA_fz(double*re,double*im,INT n,INT sg)
BEGIN
INT p,pe,st;
WHEN(n<2) RET;
for(p=2;p*p<=n AND n%p;p++);
WHEN(p*p>n) p=n;
for(pe=p;n%(pe*p) IS 0;pe*=p);
st=(n<5)?n:((pe ISNOT n)?7:((p IS n)?11:((p IS 2)?13:17)));
switch(st^5)
BEGIN
 case 2^5: qA_k2(re,im);break;
 case 3^5: qA_k3(re,im,sg);break;
 case 4^5: qA_k4(re,im,sg);break;
 case 7^5: qA_gt(re,im,pe,n/pe,sg);break;
 case 11^5: qA_rd(re,im,n,sg);break;
 case 13^5: qbr(re,im,n,sg);break;
 default: qA_ct(re,im,n,sg);break;
END
END

/* GF(qA_sp) transforms, n | qA_sp-1 */
static qAu qA_nrt(INT n,INT sg)
BEGIN
qAu e=(qA_sp-1u)/(qAu)n;
RET (qAu)qA_pw(qA_sgn,sg<0?e:(qA_sp-1u)-e,qA_sp);
END

static void qA_nk(qAu*x,INT n,INT sg)
BEGIN
qAu w[qA_NMAX],y[qA_NMAX],w1;INT j,k;qAw a;
w1=qA_nrt(n,sg);w[0]=1u;
for(j=1;j<n;j++) w[j]=(qAu)((qAw)w[j-1]*w1%qA_sp);
LOOPN(k,n) BEGIN a=0u; LOOPN(j,n) a+=(qAw)x[j]*w[(j*k)%n]; y[k]=(qAu)(a%qA_sp); END
LOOPN(k,n) x[k]=y[k];
END

static void qA_nt(qAu*,INT,INT);

static void qA_ng(qAu*x,INT n1,INT n2,INT sg)
BEGIN
qAu w[qA_NMAX],v[qA_NMAX];INT n=n1*n2,a,b,e1,e2;
qAu*const Ow=w,*const Ov=v,*const*const OOw=&Ow,*const*const OOv=&Ov;
LOOPN(a,n1) LOOPN(b,n2) *(*OOw+a*n2+b)=*(x+(a*n2+b*n1)%n);
LOOPN(a,n1) qA_nt(Ow+a*n2,n2,sg);
LOOPN(b,n2)
BEGIN
 LOOPN(a,n1) *(Ov+b*n1+a)=*(Ow+a*n2+b);
 qA_nt(*OOv+b*n1,n1,sg);
END
e1=n2*(INT)qA_iv((qAu)(n2%n1),(qAu)n1);e2=n1*(INT)qA_iv((qAu)(n1%n2),(qAu)n2);
LOOPN(b,n2) LOOPN(a,n1) *(x+(a*e1+b*e2)%n)=*(*OOv+b*n1+a);
END

/* rader over GF(qA_sp): kernel through per-call antilog/log tables of the generator,
   the integer cyclic convolution runs through qfz and is rounded back */
static void qA_nr(qAu*x,INT n,INT sg)
BEGIN
INT L=n-1,g,gi,q,e,f,lw;qAu x0=x[0],ex[qA_NMAX*4],lg[qA_NMAX*4];qAw s=0u;double*bf,*ar,*ai,*br,*bi,t;
double**const Obf=&bf,**const*const OObf=&Obf;
qAu*const Oex=ex,*const Olg=lg,*const*const OOex=&Oex;
WHEN(qA_sp>(qAu)(qA_NMAX*4)) BEGIN qA_nk(x,n,sg);RET; END
**OObf=(double*)malloc(sizeof(double)*4*L);
WHEN(NOT *Obf) BEGIN qA_nk(x,n,sg);RET; END
*Oex=1u;
for(q=1;q<(INT)qA_sp-1;q++) BEGIN *(Oex+q)=(qAu)(*(*OOex+q-1)*qA_sgn%qA_sp);*(Olg+*(Oex+q))=(qAu)q; END
*(Olg+1)=0u;
lw=(INT)*(Olg+qA_nrt(n,sg));
g=(INT)qA_pr((qAu)n);gi=(INT)qA_iv((qAu)g,(qAu)n);
ar=*Obf;ai=ar+L;br=ai+L;bi=br+L;
e=1;f=1;
LOOPN(q,L)
BEGIN
 *(ar+q)=(double)x[e];*(ai+q)=0.0;s+=x[e];
 *(br+q)=(double)*(*OOex+(INT)(((qAw)lw*(qAu)f)%(qA_sp-1u)));*(bi+q)=0.0;
 e=e*g%n;f=f*gi%n;
END
qfz(ar,ai,L,-1);qfz(br,bi,L,-1);
LOOPN(q,L) BEGIN t=ar[q]*br[q]-ai[q]*bi[q];ai[q]=ar[q]*bi[q]+ai[q]*br[q];ar[q]=t; END
qfz(ar,ai,L,1);
x[0]=(qAu)(((qAw)x0+s)%qA_sp);
f=1;
LOOPN(q,L) BEGIN x[f]=(qAu)(((qAw)x0+(qAw)qrd(*(**OObf+q)/(double)L))%qA_sp);f=f*gi%n; END
free(*Obf);
END

static void qA_nt(qAu*x,INT n,INT sg)
BEGIN
INT p,pe;
WHEN(n<2) RET;
WHEN(n<=4) BEGIN qA_nk(x,n,sg);RET; END
for(p=2;p*p<=n AND n%p;p++);
WHEN(p*p>n) p=n;
for(pe=p;n%(pe*p) IS 0;pe*=p);
WHEN(pe ISNOT n) qA_ng(x,pe,n/pe,sg);
ELSEIF(p IS n) qA_nr(x,n,sg);
OTHERWISE qA_nk(x,n,sg);
END

/* radix-2 NTT, plain residues against montgomery twiddles W[j]=w^j R */
#define qA_RH(T,NI,P) (((T)+(qAw)((qAu)(T)*(NI))*(P))>>32)
#define qA_RX(T,NI,P) ((qAu)(qA_RH(T,NI,P)>=(P)?qA_RH(T,NI,P)-(P):qA_RH(T,NI,P)))

static void qA_nb(qAu*x,INT N,const qA_mg*c,const qAu*W)
BEGIN
INT a,b,h,k,j,st;qAu u,v,t;const qAu P=c->p,NI=c->ni;qAw T;
qAu*const Ox=x,*const*const OOx=&Ox;
for(a=1,b=0;a<N;a++)
BEGIN
 for(k=N>>1;b&k;k>>=1) b^=k;
 b^=k;
 WHEN(a<b) BEGIN t=*(Ox+a);*(Ox+a)=*(*OOx+b);*(*OOx+b)=t; END
END
for(h=2,st=N>>1;h<=N;h<<=1,st>>=1)
BEGIN
 for(a=0;a<N;a+=h)
 BEGIN
  LOOPN(j,h>>1)
  BEGIN
   u=*(Ox+a+j);T=(qAw)*(*OOx+a+j+(h>>1))*W[j*st];v=qA_RX(T,NI,P);
   *(*OOx+a+j)=u+v>=P?u+v-P:u+v;
   *(Ox+a+j+(h>>1))=u>=v?u-v:u+P-v;
  END
 END
END
END

/* cyclic convolution A*B mod p into A; inverse as reversed forward, R^2/N fold */
static void qA_cv(const qA_mg*c,qAu*A,qAu*B,qAu*W,INT N)
BEGIN
INT z;qAu w,K,t;const qAu P=c->p,NI=c->ni;qAw T;
qAu*const OA=A,*const*const OOA=&OA;
w=qA_mp(c,qA_to(c,c->g),(P-1u)/(qAu)N);
W[0]=c->r1;
for(z=1;z<(N>>1);z++) W[z]=qA_MM(c,W[z-1],w);
qA_nb(A,N,c,W);qA_nb(B,N,c,W);
LOOPN(z,N) BEGIN T=(qAw)*(*OOA+z)*B[z];*(OA+z)=qA_RX(T,NI,P); END
qA_nb(*OOA,N,c,W);
for(z=1;z<N-z;z++) BEGIN t=*(OA+z);*(OA+z)=*(*OOA+N-z);*(*OOA+N-z)=t; END
K=qA_MM(c,qA_mp(c,qA_to(c,(qAu)N),P-2u),c->r2);
LOOPN(z,N) BEGIN T=(qAw)*(OA+z)*K;*(*OOA+z)=qA_RX(T,NI,P); END
END

static qAu qA_rp(const qA_mg*c,INT v)
BEGIN
qAl r;
WHEN(v>=0 AND (qAu)v<c->p) RET (qAu)v;
WHEN(v<0 AND v>-30000) RET c->p-(qAu)(-v);
r=(qAl)v%(qAl)c->p;
WHEN(r<0) r+=(qAl)c->p;
RET (qAu)r;
END

static qAu qA_rq(const qA_mg*c,INT v)
BEGIN
qAu u;
WHEN(v>-29000 AND v<29000) RET (qAu)(v*v);
u=qA_rp(c,v);
RET qA_MM(c,qA_MM(c,u,u),c->r2);
END

static void qA_boot(void)
BEGIN
qAu cc,pf[2];INT nf=0;
WHEN(qA_rdy) RET;
for(cc=qA_GF0+1u;NOT qA_sp;cc+=qA_GF0) WHEN(qA_mr(cc)) qA_sp=cc;
qA_sgn=qA_pr(qA_sp);
for(cc=qA_TOPC;cc>0u AND nf<2;cc--) WHEN(qA_mr((cc<<qA_SH)+1u)) BEGIN pf[nf]=(cc<<qA_SH)+1u;INCR(nf); END
qA_mi(&qA_M1,pf[0]);qA_mi(&qA_M2,pf[1]);
qA_i12=qA_iv(qA_M1.p%qA_M2.p,qA_M2.p);
qA_e13[0]=1;pf[0]=qA_pr(13u);
for(nf=1;nf<12;nf++) BEGIN qA_e13[nf]=(INT)((qAu)qA_e13[nf-1]*pf[0]%13u);qA_l13[qA_e13[nf]]=nf; END
qA_l13[1]=0;qA_l13[0]=0;
qA_cin();
qA_rdy=1u;
END

#endif
