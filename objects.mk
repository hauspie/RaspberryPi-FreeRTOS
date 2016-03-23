#
#	FreeRTOS portable layer for RaspberryPi
#
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/portable/GCC/$(PLATFORM)/port.o
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/portable/GCC/$(PLATFORM)/portisr.o

#
#	FreeRTOS Core
#
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/croutine.o
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/list.o
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/queue.o
OBJECTS += $(BUILD_DIR)FreeRTOS/Source/tasks.o

#
#	Selected HEAP implementation for FreeRTOS.
#
OBJECTS += $(BUILD_DIR)/FreeRTOS/Source/portable/MemMang/heap_4.o

#
#	Drivers
#
OBJECTS += $(BUILD_DIR)Platform/$(PLATFORM)/Drivers/interrupts.o
OBJECTS += $(BUILD_DIR)Platform/$(PLATFORM)/Drivers/gpio.o
OBJECTS += $(BUILD_DIR)Platform/$(PLATFORM)/Drivers/uart.o


#
#	Startup and platform initialisation code.
#
OBJECTS += $(BUILD_DIR)Platform/$(PLATFORM)/startup.o


#
#	Main Test Program
#

OBJECTS += $(BUILD_DIR)$(SAMPLE)/main.o
OBJECTS += $(BUILD_DIR)$(SAMPLE)/aes.o
OBJECTS += $(BUILD_DIR)$(SAMPLE)/printf.o
OBJECTS += $(BUILD_DIR)$(SAMPLE)/cpuidc.o
OBJECTS += $(BUILD_DIR)$(SAMPLE)/dhry_1.o
OBJECTS += $(BUILD_DIR)$(SAMPLE)/dhry_2.o
