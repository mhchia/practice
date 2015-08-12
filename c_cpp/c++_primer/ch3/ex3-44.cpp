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

    // using range for
    for (auto &i : ia)
        for (auto &j : i)
            cout << j << " ";
    cout << endl;

    // using subscript
    for (size_t i = 0; i < 3; ++i)
        for (size_t j = 0; j < 4; ++j)
            cout << ia[i][j] << " ";
    cout << endl;

    // using pointers

    using int_array = int[4];
    typedef int int_array[4]; // equivalent to above
    for (int_array *ptr = std::begin(ia); ptr != std::begin(ia)+3; ++ptr)
        for (int * col = std::begin(*ptr); col != std::begin(*ptr)+4; ++col)
            cout << *col << " ";
    cout << endl;
}

