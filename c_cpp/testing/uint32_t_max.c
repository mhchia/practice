#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t a = 2147483648 * 2 - 1;
    printf("%u", a);
}
