#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
    int ia[3][4] = {}; // list init
    for (auto &i : ia)
        for (auto j : i)
            cout << j << " ";
    cout << endl;

    for (auto row = ia; row != ia + 3; ++row)
        for (auto col = *row; col != *row + 4; ++col)
            cout << *col << " ";
    cout << endl;
}

