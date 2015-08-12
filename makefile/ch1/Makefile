###### format
# target: required files
# 	command
#
# explanation: target can be object files, executables, label
# make will execute this script step by step
exe: a.o b.o main.o
	cc -o exe a.o b.o main.o
a.o: a.c
	cc -c a.c
b.o: b.c
	cc -c b.c
main.o: main.c a.h b.h
	cc -c main.c
# here to be mentioned, clean is a label rather than a filename
clean:
	rm -f *.o
