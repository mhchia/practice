#include <stdio.h>

#define memory_barrier() __asm__ volatile ("" ::: "memory")
#define cpu_barrier() __asm__ volatile ("mfence")
#define both_barrier() __asm__ volatile ("mfence" ::: "memory")


int main(void)
{
    memory_barrier();
    cpu_barrier();
    both_barrier();
}

