
CFLAGS += -march=armv6z -g -Wall -Wextra -ffreestanding
CFLAGS += -I $(BASE)FreeRTOS/Source/portable/GCC/RaspberryPi/
CFLAGS += -I $(BASE)FreeRTOS/Source/include/
CFLAGS += -I $(BASE)Demo/Drivers/

LDFLAGS += -lc -nostdlib

TOOLCHAIN=arm-none-eabi-
