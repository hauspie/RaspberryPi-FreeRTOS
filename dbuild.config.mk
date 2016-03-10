
CFLAGS += -march=armv6z -g -Wall -Wextra -ffreestanding
CFLAGS += -I $(BASE)FreeRTOS/Source/portable/GCC/RaspberryPi/
CFLAGS += -I $(BASE)FreeRTOS/Source/include/
CFLAGS += -I $(BASE)Demo/Drivers/

LDFLAGS += -lc -nostdlib

QEMU=qemu-system-arm
QEMU_CMD_LINE=$(QEMU) -cpu arm1176 -m 512 -M raspi -nographic -kernel

TOOLCHAIN=arm-none-eabi-
