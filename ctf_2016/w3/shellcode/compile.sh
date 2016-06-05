sm -felf32 shell.asm -o shell.o
ld -melf_i386 shell.o -o shell
objcopy -O binary shell.o shell.bin
objdump -b binary -m i386 -D shell.bin
