# -*- mode: gdb-script; -*-

add-symbol-file kernel.elf 0x8000

target remote localhost:1234



