#ifndef ABSTRACT_H
#define ABSTRACT_H
#include "c.h"
#include "o.h"

typedef struct itables itables_t;
struct itables {
    const char *provider_name;
    const char* (*stage_map )(itables_t *self,int idx);
    const char* (*t2aux)(itables_t *self,int idx);
    const char* (*t3map    )(itables_t *self,int idx);
    const char* (*stage_id   )(itables_t *self,int idx);
    void       *backing;
    int         lookups;
};
static itables_t *TABLES=0;

#define TBL_MAP(i)  (TABLES->stage_map (TABLES,(i)))
#define TBL_T2(i)   (TABLES->t2aux(TABLES,(i)))
#define TBL_T3(i)    (TABLES->t3map    (TABLES,(i)))
#define TBL_ID(i)    (TABLES->stage_id   (TABLES,(i)))

typedef struct iengine iengine_t;
struct iengine {
    const char *impl_name;
    int  (*configure    )(iengine_t *self,void *settings);
    int  (*set_prelude)(iengine_t *self,void *spec);
    int  (*process_letter)(iengine_t *self,int letter);
    int  (*process_text  )(iengine_t *self,const void *text);
    void *state;
    int   generation;
};
static iengine_t *THE_ENGINE=0;

typedef struct {
    const char *id;
    iengine_t* (*create)(void);
    int         priority;
} iengine_factory_t;

#define MAX_FACTORIES 4
static iengine_factory_t FACTORY_REGISTRY[MAX_FACTORIES];
static int FACTORY_COUNT=0;
static unsigned char qD_fsl[TWICE(MAX_FACTORIES)];

static int register_factory(const char *id,iengine_t*(*ctor)(void),int prio)
BEGIN
uint32_t h;unsigned char*const Ofs=qD_fsl,*const*const OOfs=&Ofs;
WHEN(FACTORY_COUNT>=MAX_FACTORIES) RET -1;
FACTORY_REGISTRY[FACTORY_COUNT].id=id;
FACTORY_REGISTRY[FACTORY_COUNT].create=ctor;
FACTORY_REGISTRY[FACTORY_COUNT].priority=prio;
h=qD_fnv(id)&(uint32_t)(TWICE(MAX_FACTORIES)-1);
while(*(*OOfs+h)) h=(h+1u)&(uint32_t)(TWICE(MAX_FACTORIES)-1);
*(Ofs+h)=(unsigned char)(FACTORY_COUNT+1);
INCR(FACTORY_COUNT);
RET 0;
END

static iengine_t* create_engine(const char *id)
BEGIN
int z,w;uint32_t h=qD_fnv(id)&(uint32_t)(TWICE(MAX_FACTORIES)-1),*const Oh=&h,*const*const OOh=&Oh;
LOOPN(w,TWICE(MAX_FACTORIES))
BEGIN
 WHEN(NOT *(qD_fsl+**OOh)) break;
 z=*(qD_fsl+*Oh)-1;
 WHEN(EQ(FACTORY_REGISTRY[z].id,id)) RET FACTORY_REGISTRY[z].create();
 **OOh=(*Oh+1u)&(uint32_t)(TWICE(MAX_FACTORIES)-1);
END
RET 0;
END

typedef struct {
    const char *cfg0;
    const char *cfg1;
    const char *cfg2;
    const char *cfg3;
    int         built;
    int         version;
} settings_t;

static settings_t SETTINGS_SINGLETON;
static uint32_t qD_sck=0u;

static settings_t* settings_begin(void)
BEGIN
memset(&SETTINGS_SINGLETON,0,sizeof SETTINGS_SINGLETON);
SETTINGS_SINGLETON.version=1;
RET &SETTINGS_SINGLETON;
END
static settings_t* settings_a0(settings_t*b,const char*v)   BEGIN b->cfg0=v;    RET b; END
static settings_t* settings_a1(settings_t*b,const char*v)BEGIN b->cfg1=v; RET b; END
static settings_t* settings_a2(settings_t*b,const char*v)   BEGIN b->cfg2=v;    RET b; END
static settings_t* settings_a3(settings_t*b,const char*v)    BEGIN b->cfg3=v;     RET b; END
static settings_t* settings_end(settings_t*b)
BEGIN
const char*qv[4],**const Oqv=qv,**const*const OOqv=&Oqv;settings_t*const*const Ob=&b;
*Oqv=(**Ob).cfg0;*(Oqv+1)=(*Ob)->cfg1;*(*OOqv+2)=b->cfg2;*(*OOqv+3)=(**Ob).cfg3;
b->built=1;
qD_sck=qD_c4T(*OOqv);
RET b;
END

typedef struct isink isink_t;
struct isink {
    const char *sink_name;
    void (*emit)(isink_t *self,const char *line);
    void *dest;
    int   emitted;
};
static isink_t *SINK=0;

typedef struct {
    const char *tag;
    void (*on_event)(int code,void *userdata);
    void *userdata;
    int   deliveries;
} subscriber_t;

#define MAX_SUBS 4
static subscriber_t SUBS[MAX_SUBS];
static int SUBCOUNT=0;
static uint32_t qD_sky[MAX_SUBS];
static uint32_t qD_bq[qD_W];
static unsigned qD_bh=0u,qD_bt=0u;

static int subscribe(const char*tag,void(*fn)(int,void*),void*ud)
BEGIN
WHEN(SUBCOUNT>=MAX_SUBS) RET -1;
SUBS[SUBCOUNT].tag=tag;SUBS[SUBCOUNT].on_event=fn;SUBS[SUBCOUNT].userdata=ud;
SUBS[SUBCOUNT].deliveries=0;
*(qD_sky+SUBCOUNT)=qD_fnv(tag)^((uint32_t)SUBCOUNT*0x9E3779B9u);
INCR(SUBCOUNT);
RET 0;
END

static void publish(int code)
BEGIN
int z;uint32_t e,*const Oe=&e,*const*const OOe=&Oe;
LOOPN(z,SUBCOUNT)
BEGIN
 WHEN(SUBS[z].on_event)
 BEGIN
  **OOe=qD_fe(qD_i2u(code),*(qD_sky+z))*qD_BM;
  *(qD_bq+(qD_bt&(qD_W-1)))=*Oe;INCR(qD_bt);
  *Oe=*(qD_bq+(qD_bh&(qD_W-1)));INCR(qD_bh);
  SUBS[z].on_event(qD_u2i(qD_fd(**OOe*qD_hns(qD_BM),*(qD_sky+z))),SUBS[z].userdata);
  INCR(SUBS[z].deliveries);
 END
END
END

#define ENGINE_ID "set0"

PRIVATE void bootstrap(void);
#define ENSURE_WIRED() do{ WHEN(NOT THE_ENGINE) bootstrap(); }while(0)

static int engine_configure(const char*c0,const char*c1,const char*c2,const char*c3)
BEGIN
settings_t *s=settings_end(settings_a3(settings_a2(settings_a1(
              settings_a0(settings_begin(),c0),c1),c2),c3));
qD_ch_t qx,*const Oqx=&qx,*const*const OOqx=&Oqx;settings_t*const*const Os=&s;
ENSURE_WIRED();
WHEN(NOT THE_ENGINE) RET -1;
qD_chi(Oqx,4,0,qD_sck);
*((**OOqx).qDit+0)=(**Os).cfg0;*((*OOqx)->qDit+1)=s->cfg1;*(qx.qDit+2)=(*Os)->cfg2;*(Oqx->qDit+3)=s->cfg3;
(*Os)->cfg0=(**Os).cfg1=s->cfg2=s->cfg3=*(qD_dcy+qD_W-1);
qD_pump(*OOqx);
(**Os).cfg0=*(qx.qDit+0);s->cfg1=*((**OOqx).qDit+1);(*Os)->cfg2=*(Oqx->qDit+2);s->cfg3=*((*OOqx)->qDit+3);
RET THE_ENGINE->configure(THE_ENGINE,(void*)s);
END

static int engine_prelude(const char*spec)
BEGIN
qD_ch_t qx,*const Oqx=&qx,*const*const OOqx=&Oqx;
ENSURE_WIRED();
WHEN(NOT THE_ENGINE) RET -1;
qD_chi(*OOqx,1,1,qD_phH(spec));
*(Oqx->qDit)=spec;
qD_pump(Oqx);
RET THE_ENGINE->set_prelude(THE_ENGINE,(void*)*((**OOqx).qDit));
END

static int engine_run(const char*text)
BEGIN
qD_ch_t qx,*const Oqx=&qx,*const*const OOqx=&Oqx;
ENSURE_WIRED();
WHEN(NOT THE_ENGINE) RET -1;
qD_chi(Oqx,1,1,qD_phH(text));
*((*OOqx)->qDit)=text;
qD_pump(*OOqx);
RET THE_ENGINE->process_text(THE_ENGINE,(const void*)*(qx.qDit));
END

#endif
