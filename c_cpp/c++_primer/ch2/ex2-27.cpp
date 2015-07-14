#include <iostream>

int main(void)
{
    const int a = 2, b = 3;
    /* const int is base-type, so b is a const int, too.
    b = 4;
    */

    /* ref-to-nonconst can only bind to an existing object
        not a literal or an expression.
    int j = -1, &r1 = 0;
    */
    // ref-to-const can bind to a literal or a expression
    // because compiler first init an object = 0 and
    // bin the ref-to-const to that new object.
    const int i = -1, &r = 0;


    int i2 = 0;
    // const int i2 = 0;
    // it is dangerous because we dont know i2 is const or nonconst.
    // const pointer to int can only point to a nonconst object.
    int *const p2 = &i2;

    // ptr-to-const can always point to a nonconst/const
    const int *const p3 = &i2;

    // ptr-to-const can always point to a nonconst/const
    const int *p4 = &i2;

    // const qualifier cannot apply to const int &
    // and neither & nor const object can be declared without init.
    /*
    const int &const r2;
    */
    // ref-to-const can bind to nonconst or literal or expression.
    double z = 2.2;
    const int &y1 = z; // compiler create a new object int temp = (int)z, and bind y1 to temp.
    const int &y2 = z * 2; // compiler create a new object int temp = (int)z*2, and bind y2 to temp.
    const int &y3 = 0; // compiler create a new object int temp = 0, and bind y3 to temp
    int z2 = 1;
    const int &y4 = z2; // compiler bind y4 to z2 !!!XXX!!!!, but cannot modify z2 by y4.
}

