linking: TinyHelloWorld.o
	ld -static -e nomain -o TinyHelloWorld TinyHelloWorld.o
TinyHelloWorld: TinyHelloWorld.c
	gcc -c -fno-builtin TinyHelloWorld.c
clean:
	rm -f *.o
