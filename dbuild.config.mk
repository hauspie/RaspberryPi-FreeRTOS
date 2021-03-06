# What to build
PLATFORM:=RaspberryPi
SAMPLE:=Benchmarks

CFLAGS += -march=armv6z -Wall -Wextra -ffreestanding -Wno-unused-parameter
CFLAGS += -I $(BASE)$(SAMPLE)
CFLAGS += -I $(BASE)Platform/$(PLATFORM)/
CFLAGS += -I $(BASE)FreeRTOS/Source/portable/GCC/RaspberryPi/
CFLAGS += -I $(BASE)FreeRTOS/Source/include/
CFLAGS += -O0 -g

LDFLAGS += -nostdlib -lc -lgcc

QEMU=qemu-system-arm
QEMU_RASP_OPTIONS=-cpu arm1176 -m 512 -M raspi
QEMU_CMD_LINE=$(QEMU) $(QEMU_RASP_OPTIONS) -nographic -kernel
QEMU_DEBUG_LINE=$(QEMU) -gdb tcp::1234 -S $(QEMU_RASP_OPTIONS) -nographic -kernel
TOOLCHAIN=arm-none-eabi-

