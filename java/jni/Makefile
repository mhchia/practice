all: libhello.so

libhello.so: hello.o
	gcc -fPIC -shared -o libhello.so hello.o
hello.o: hello.c HelloWorld.h
	gcc -fPIC -c hello.c -I/usr/lib/jvm/java-7-openjdk-amd64/include/ -o hello.o
HelloWorld.h: HelloWorld.class
	javah -jni HelloWorld
HelloWorld.class: HelloWorld.java
	javac HelloWorld.java

run:
	java -Djava.library.path=. HelloWorld
clean:
	rm -f *.o *.so *.h *.class
