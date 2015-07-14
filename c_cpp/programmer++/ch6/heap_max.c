#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int maximum = 0;
    unsigned int blocksize[] = { 1024 * 1024, 1024, 1};
    int i;
    for (i = 0; i < 3; i++) {
        int count;
        for (count = 1; ; ++count) {
            void *block = malloc(maximum + blocksize[i] * count);
            if (block)
                free(block);
            else
                break;
        }
        maximum = maximum + blocksize[i] * (count - 1);
    }
    printf("maximum malloc size = %u bytes\n", maximum);
    return EXIT_SUCCESS;
}

