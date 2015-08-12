#include <iostream>

using std::string;
int main(void)
{
    int i = 2, j = 3;
    double slope = static_cast<double>(j) / i;

//    double *dp = &i; // error, double* cannot point to int
    void *p = &i; // automatically convert int* to void*
    double *dp = static_cast<double*>(p); // ok, but nonconsistent type of pointer and pointed element incurs undefined behavior.
    std::cout << *dp << std::endl; // not equaled to 2, because of undefined behavior.

    const char *cp = "da"; // if cp is not initialized, the static_cast<string>(cp) will incur undefined behavior
//    char *q = static_cast<char*>(cp); // cannot cast away the constness.

    static_cast<string>(cp); // runtime error because of undefined behavior.
//    const_cast<string>(cp); // error, const_cast can only change constness rather than type.

    /* reinterpret */
    int *ip;
    char *pc = reinterpret_cast<char*>(ip);
    string str(pc);

    /* old style */
    int a = int(0.5);
    int b = (int)0.5; // equivalent to above
    std::cout << a << std::endl; // 0
    std::cout << b << std::endl; // 0

}

