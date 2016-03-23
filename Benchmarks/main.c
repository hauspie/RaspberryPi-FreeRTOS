#include <FreeRTOS.h>
#include <task.h>

#include "Drivers/interrupts.h"
#include "Drivers/uart.h"

#include "printf.h"

extern void generic_user_task(void *pParam);
extern void bench_task(void *pParam);



/* For printf */
void putchar(int c)
{
   uartPutC(c);
}



/**
 *	This is the systems main entry, some call it a boot thread.
 *
 *	-- Absolutely nothing wrong with this being called main(), just it doesn't have
 *	-- the same prototype as you'd see in a linux program.
 **/
void main(void) {

	DisableInterrupts();
	InitInterruptController();


	xTaskCreate(generic_user_task, (signed char*)"Task1", 128, NULL, 0, NULL);
	xTaskCreate(generic_user_task, (signed char*)"Task2", 128, NULL, 0, NULL);
	xTaskCreate(generic_user_task, (signed char*)"Task3", 128, NULL, 0, NULL);
	xTaskCreate(generic_user_task, (signed char*)"Task4", 128, NULL, 0, NULL);
	xTaskCreate(bench_task, (signed char*)"Bench", 1024, NULL, 0, NULL);

	vTaskStartScheduler();

	/*
	 *	We should never get here, but just in case something goes wrong,
	 *	we'll place the CPU into a safe loop.
	 */
	while(1) {
		;
	}
}
