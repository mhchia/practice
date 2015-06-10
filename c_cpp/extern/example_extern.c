#include <stdio.h>
#include "a.h"
extern b;
void foo() {
    printf("b = %d\n", b);
}
int main(void) {
    foo();
//    bar();
}
int b = 2;
