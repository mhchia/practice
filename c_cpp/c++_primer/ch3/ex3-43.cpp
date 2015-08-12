#include <iostream>

using std::cout;
using std::endl;
int main(void)
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };

    // using range for to print ia
    for (const int (&p)[4] : ia) // p is ref to int[4]
        for (const int q : p)
            cout << q << " ";
    cout << endl;

    // using subscript
    for (size_t i = 0; i < 3; ++i)
        for (size_t j = 0; j < 4; ++j)
            cout << ia[i][j] << " ";
    cout << endl;

    // using pointers
    for (const int (*p)[4] = ia; p != ia + 3; ++p)
        for (const int *q = *p; q != *p + 4; ++q)
            cout << *q << " ";
    cout << endl;
}

