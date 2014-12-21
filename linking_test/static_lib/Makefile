all:
	gcc haha1.c haha2.c -c
	ar rcs libtest.a haha1.o haha2.o
	# or gcc main.c -L. -ltest \
	#  -L means search the current dir \
	#  -l means the linking with the libtest.a, which must have the prefix 'lib'
	gcc main.c libtest.a
clean:
	rm *.o
