# What to build
PLATFORM:=RaspberryPi
SAMPLE:=Demo

CFLAGS += -march=armv6z -Wall -Wextra -ffreestanding -Wno-unused-parameter
CFLAGS += -I $(BASE)FreeRTOS/Source/portable/GCC/RaspberryPi/
CFLAGS += -I $(BASE)FreeRTOS/Source/include/
CFLAGS += -I $(BASE)Platform/$(PLATFORM)/
CFLAGS += -O0 -g

LDFLAGS += -lc -nostdlib

QEMU=qemu-system-arm
QEMU_RASP_OPTIONS=-cpu arm1176 -m 512 -M raspi
QEMU_CMD_LINE=$(QEMU) $(QEMU_RASP_OPTIONS) -nographic -kernel
QEMU_DEBUG_LINE=$(QEMU) -gdb tcp::1234 -S $(QEMU_RASP_OPTIONS) -nographic -kernel
TOOLCHAIN=arm-none-eabi-

