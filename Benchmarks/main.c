#include <FreeRTOS.h>
#include <task.h>

#include "Drivers/interrupts.h"
#include "Drivers/uart.h"

#include "printf.h"

void putchar(int c)
{
   uartPutC(c);
}

void task1(void *pParam) {

	int i = 0;
	while(1) {
		i++;
                printf("Task 1\n");
		vTaskDelay(200);
	}
}

void task2(void *pParam) {

	int i = 0;
	while(1) {
		i++;
		vTaskDelay(100);
                printf("Task 2\n");
		vTaskDelay(100);
	}
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


	xTaskCreate(task1, (signed char*)"Task1", 128, NULL, 0, NULL);
	xTaskCreate(task2, (signed char*)"Task2", 128, NULL, 0, NULL);

	vTaskStartScheduler();

	/*
	 *	We should never get here, but just in case something goes wrong,
	 *	we'll place the CPU into a safe loop.
	 */
	while(1) {
		;
	}
}
