#include <stdio.h>
#include <stdlib.h>

// bool
int CalculatePageNumber(unsigned addr, unsigned *page_number, unsigned *offset)
{
    unsigned page_size = 1024U * 4U;
    *page_number = addr / page_size;
    *offset = addr % page_size;

    return 1;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Please provide an address\n");
        exit(EXIT_FAILURE);
    }

    unsigned addr = atoi(argv[1]);
    unsigned page_number, offset;

    if (!CalculatePageNumber(addr, &page_number, &offset)) {
        fprintf(stderr, "Something wrong in CalculatePageNumber\n");
        exit(EXIT_FAILURE);
    }

    printf("page_number : %d\noffset : %d\n", page_number, offset);

    return EXIT_SUCCESS;
}

