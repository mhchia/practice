#include <iostream>

void Print(const int *begin, const int *end)
{
    while (begin != end)
        std::cout << *begin++ << std::endl;
}

void Print(const char *cp)
{
    if (cp) { // check if cp is null. dereference invalid pointers incurs undefined behavior.
        while (*cp) {
            std::cout << *cp++;
        }
        std::cout << std::endl;
    }
}

void Print(const int ia[], size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        std::cout << ia[i] << " ";
    }
    std::cout << std::endl;
}
void Print(int (&rai)[10]) // ref to array of 10 ints type
{
    std::cout << "Using non-const type" << std::endl;
    for (size_t i = 0; i < 10; ++i) {
        std::cout << rai[i] << " ";
    }
    std::cout << std::endl;
}

void Print(const int (&rai)[10]) // ref to array of 10 ints type
{
    std::cout << "Using const type" << std::endl;
    for (size_t i = 0; i < 10; ++i) {
        std::cout << rai[i] << " ";
    }
    std::cout << std::endl;
}

/* error, call of overloaded ‘Print(int [10])’ is ambiguous 
void Print(int rai[10]) // ref to array of 10 ints type
{
    std::cout << "Using none ref type" << std::endl;
    for (size_t i = 0; i < 10; ++i) {
        std::cout << rai[i] << " ";
    }
    std::cout << std::endl;
}
*/

int main(void)
{
    int a1[] = {0, 1, 2};
    int a2[9] = {0};
    int a3[10] = {0};
    const int a4[10] = {0};
    Print(std::begin(a1), std::end(a1)); // need c++11
//    Print(a2); // error, only 9 elements
    Print(a3); // ok, using non-const
    Print(a4); // ok, using const

    int a[2][3] = {0};

    int (*ptr)[3] = &a[0];
//    int **ptr1 = &a[0]; // error, cannot convert ‘int (*)[3]’ to ‘int**’ in initialization

    int i = 0, j[2] = {0, 1};
    Print(&i, 1); Print(j, 2);
}
