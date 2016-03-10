
CFLAGS += -march=armv6z -g -Wall -Wextra -ffreestanding
CFLAGS += -I $(BASE)FreeRTOS/Source/portable/GCC/RaspberryPi/
CFLAGS += -I $(BASE)FreeRTOS/Source/include/
CFLAGS += -I $(BASE)Demo/Drivers/

LDFLAGS += -lc -nostdlib

QEMU=qemu-system-arm
QEMU_RASP_OPTIONS=-cpu arm1176 -m 512 -M raspi
QEMU_CMD_LINE=$(QEMU) $(QEMU_RASP_OPTIONS) -nographic -kernel
QEMU_DEBUG_LINE=$(QEMU) -gdb tcp::1234 -S $(QEMU_RASP_OPTIONS) -nographic -kernel
TOOLCHAIN=arm-none-eabi-
