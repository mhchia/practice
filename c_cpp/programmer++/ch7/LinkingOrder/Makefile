main: b1.so b2.so main.c
	gcc main.c b1.so b2.so -o main -Xlinker -rpath ./
b1.so: b1.c a1.so
	gcc -fPIC -shared b1.c a1.so -o b1.so
b2.so: b2.c a2.so
	gcc -fPIC -shared b2.c a2.so -o b2.so
a1.so: a1.c
	gcc -fPIC -shared a1.c -o a1.so
a2.so: a2.c
	gcc -fPIC -shared a2.c -o a2.so
