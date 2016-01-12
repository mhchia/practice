#include <stdio.h>
#include "HelloWorld.h"

JNIEXPORT void JNICALL
Java_HelloWorld_print(JNIEnv *env, jobject obj)
{
    printf("JNI says Hello World!\n");
    return;
}

void test()
{
    printf("Test\n");
}
