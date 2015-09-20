#include <stdio.h>
#include <elf.h>

int main(int argc, char *argv[])
{
    int *p = (int*)argv;
    int i;
    Elf32_auxv_t* aux;

    printf("Argument count: %d\n", *(p-2));
    int argument_count = *(p-2);

    for (i = 0; i < argument_count; ++i) {
        printf("Argument %d : %s\n", i, *(p + i - 1));
    }
}

