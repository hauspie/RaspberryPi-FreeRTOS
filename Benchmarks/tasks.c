#include "printf.h"

#include "aes.h"
#include "perf_timer.h"

#define DECLARE_BENCH static uint32_t __start, __end, __runs,__count
#define START_BENCH(c)   __count = __runs = (c); __start = GET_PERF_TIMER_CLO; for ( ; __count ; --__count ) {
#define END_BENCH(x)  } do { __end = GET_PERF_TIMER_CLO; printf("BENCH %s_%s,%d,%d\n", (x), "multi_task", (__end-__start), __runs); } while(0)



extern void dhrystone(void);
void dhrystone_task(void)
{
   DECLARE_BENCH;
   START_BENCH(200);
   dhrystone();
   END_BENCH("Dhrystone");
}

void AES_task(void)
{
   DECLARE_BENCH;
   START_BENCH(5);
   mbedtls_aes_self_test(0);
   END_BENCH("AES");
}

void generic_user_task(void *pParam)
{
   printf("Task %p: Starting\n", pParam);
   while (1)
   {
   }
   printf("Task %p: ending\n", pParam);
}


int fibo(int n){
  if(n==0 || n==1)
    return n;
  else
    return fibo(n-1) + fibo(n-2);
}

void fibo_task(void)
{
   DECLARE_BENCH;
   START_BENCH(1);
   for (int i = 0 ; i < 30 ; ++i)
   {
      fibo(i);
   }
   END_BENCH("Fibo");
}


void bench_task(void *pParam)
{
   printf("Running bench in task %p\n", pParam);
   fibo_task();
   dhrystone_task();
   AES_task();
   printf("Benches terminated\n");
   asm volatile("udf");
   for (;;);
}

