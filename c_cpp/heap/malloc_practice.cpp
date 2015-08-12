#include <iostream>
#include <cstdlib>


typedef int MyInt;

int main(void)
{
//    int *a = malloc(sizeof(int)); // compile error : invalid conversion from ‘void*’ to ‘int*’, c++
//    int *a = (int*)malloc(sizeof(int)); // ok, the old syntax, but
    int *a = static_cast<int*>(std::malloc(sizeof(MyInt)));
    if (a != nullptr) {
        *a = 0;
    }
//    a[1] = 1; // Will not incur segfault, because the malloc often allocate more memory than we specified.
//    a[100] = 1; // ok
//    a[1000] = 1; // ok
//    a[10000] = 1; // ok
//    a[100000] = 1; // However, if we use too much then segfault occurs.

//    void *p = malloc(0); // undefined behavior, dont do this!
    std::free(a);
    a = nullptr; // we should always set a pointer to nullptr after it is freed. Free a pointer that is freed is undefined behavior.
    std::free(a); // It is safe to free a nullptr.
}

