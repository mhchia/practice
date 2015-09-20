#include <iostream>

int main(void)
{
    int a[3];
//    int (*p1)[3] = a; // a是int* 而p1是int (*)[3], type不同不能亂指
    int (*p1)[3] = &a; // &a就是int (*)[3]了，所以可以指
//    int (*p2)[4] = &a; // error, 指到array-of-4-int的指標不能指到array-of-3-int
    int *p = a;
}
