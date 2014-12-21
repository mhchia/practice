#include <stdio.h>
int a = 1;

int main(void) {
    int a = 2;
    printf("%d\n", ::a);
}
