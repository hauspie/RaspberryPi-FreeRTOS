#ifndef __PERF_TIMER_H__
#define __PERF_TIMER_H__

typedef volatile struct
{
   uint32_t cs;
   uint32_t clo;
   uint32_t chi;
   uint32_t c0;
   uint32_t c1;
   uint32_t c2;
   uint32_t c3;
} perf_timer_t;

#define GET_PERF_TIMER_CLO ((volatile perf_timer_t*)0x20003000)->clo


#endif
