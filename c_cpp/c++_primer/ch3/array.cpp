#include <string>
#include <iostream>
#include <cstddef> // define size_t

using std::string;
int main(void)
{
    unsigned cnt = 42;
    constexpr unsigned sz = 42;

    int array[10];
    int *p[sz];
    string bad[cnt]; // why ok?
    string strs[sz]; // ok if the sz is constexpr

    // init
    const unsigned s = 3;
    int ia1[s] = {0, 1, 2};
    int a2[] = {0, 1, 2}; // if the dimension is not specified, compiler will infer it from the number of initializers.
    int a3[5] = {3, 1, 2}; // a3 = {3, 1, 2, 0, 0}, library do value-initialize for you, which initialize a3[3], a3[4] to 0.

    string a4[3] = {"hi", "bye"}; // same as a4[] = {"hi", "bye", ""}, library do value initialize to a4[2] as "".
//    int a5[2] = {0, 1, 2}; // error, the dimension is too small.

    char i1[] = {'c', '+', '+'}; // list-init, no \0
    char i2[] = {'c', '+', '+', '\0'}; // list-init,  explicit \0
    char i3[] = "c++"; // with \0
//    const char i4[6] = "Daniel"; // error, if initialize with string literal, your must reserve a char for \0

    // no copy or assignment
    int a[] = {0, 1, 2};
//    int aa2[] = a; // error
//    int aa3[3];
//    aa3 = a; //  error: array must be initialized with a brace-enclosed initializer, invalid array assignment

    // complicated array declaration
    int test_a[10]; // array of ints
    int (*p1)[10] = &test_a; // pointer to array of int
    int (&r1)[10] = test_a; // reference to array of int
    int (*(&r2))[10] = p1; // reference to pointer to array of int

    int b;
    int *ptr[10]; // array of pointers to int
    ptr[0] = &b; // the first pointer points to b
    int *(&r3)[10] = ptr; // reference to array of pointer to int

    size_t subscript = 0; // the subscript of array is of size_t type, which is big enough to contain all size of object in memory.
    std::cout << ptr[subscript] << std::endl;
}

