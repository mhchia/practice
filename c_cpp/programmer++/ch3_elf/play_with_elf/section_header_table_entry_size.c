#include <elf.h>
#include <stdio.h>

int main(void)
{
    Elf64_Ehdr a64;
    Elf32_Shdr a32;
    printf("%d %d\n", (int)sizeof(a64), (int)sizeof(a32));
}
