#include <iostream>

int main(void)
{
    const double pi = 3.14f;
    /* invalid conversion from const double* to double*
     * else, we could use ptr to modify pi, it is not reasonable.
    double *ptr = &pi;
    */
    const double *cptr = &pi;
    /* error, pointer-to-const cannot modify the object.
    *cptr = 42;
    */

    // however, we can point a pointer-to-const to a non-const
    // which is the same as reference.
    double pp = 1.0L;
    cptr = &pp;
    std::cout << *cptr << std::endl;

    return 0;
}

