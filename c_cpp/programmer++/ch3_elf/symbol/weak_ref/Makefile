all:
	gcc weak_ref.c -c
	gcc foo.c -c

without_foo:
	gcc weak_ref.o -o without_foo

with_foo:
	gcc weak_ref.o foo.o -o with_foo
