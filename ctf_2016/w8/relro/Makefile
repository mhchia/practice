
all: no partial full

no: src.c
	gcc src.c -o no -fno-stack-protector -Wl,-z,norelro -m32 

partial: src.c
	gcc src.c -o partial -fno-stack-protector -m32

full: src.c
	gcc src.c -o full -fno-stack-protector -Wl,-z,relro,-z,now -m32
