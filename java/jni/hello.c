#include <stdio.h>
#include "HelloWorld.h"

JNIEXPORT void JNICALL
Java_HelloWorld_print(JNIEnv* env, jobject obj)
{
    printf("Hello world\n");
    return;
}

void test()
{
    printf("Test\n");
}
