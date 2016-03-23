#
#	Makefile for FreeRTOS demo on Raspberry Pi
#
BASE=$(shell pwd)/
BUILD_DIR=$(shell pwd)/build/

MODULE_NAME="RaspberryPi BSP"

TARGETS=kernel.img kernel.list kernel.syms kernel.elf
LINKER_SCRIPT=raspberrypi.ld

-include .dbuild/dbuild.mk


all: kernel.list kernel.img kernel.syms
	@$(SIZE) kernel.elf

kernel.img: kernel.elf
	$(Q)$(PRETTY) IMAGE $(MODULE_NAME) $@
	$(Q)$(OBJCOPY) kernel.elf -O binary $@

kernel.list: kernel.elf
	$(Q)$(PRETTY) LIST $(MODULE_NAME) $@
	$(Q)$(OBJDUMP) -D -S  kernel.elf > $@

kernel.syms: kernel.elf
	$(Q)$(PRETTY) SYMS $(MODULE_NAME) $@
	$(Q)$(OBJDUMP) -t kernel.elf > $@

kernel.elf: $(OBJECTS)
	$(Q)$(CC) $(OBJECTS) -o $@ -Wl,-Map,kernel.map,-T,$(LINKER_SCRIPT) $(LDFLAGS)

.PHONY: emu
emu: kernel.elf
	$(QEMU_CMD_LINE) $<

.PHONY: debug-emu
debug-emu: kernel.elf
	$(QEMU_DEBUG_LINE) $<

.PHONY: deploy

deploy: kernel.elf kernel.img
	cp kernel.elf ../../data/guest.elf
	cp kernel.img ../../data/guest.bin
