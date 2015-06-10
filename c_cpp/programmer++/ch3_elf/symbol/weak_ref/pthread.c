#include <stdio.h>
#include <pthread.h>

int pthread_create(pthread_t*, const pthread_attr_t*, void* (*)(void*), void*) __attribute__ ((weak)) ;

int main(void)
{
    if (pthread_create) {
        printf("multi-thread\n");
    } else {
        printf("single-thread\n");
    }
}
