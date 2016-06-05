all: test.asm
	nasm -f elf test.asm
	ld -m elf_i386 -o test test.o
