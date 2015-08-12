#include <iostream>

int main(void)
{
    int ia[3][4] = { // ia is array of 3 elements, each element is an array of four elements of ints.
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    // equivalent to above
    int ia1[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    int ia2[3][4] = {{0}, {4}, {8} }; // 000040008000
    for (size_t i = 0; i < 3; ++i)
        for (size_t j = 0; j < 4; ++j)
            std::cout << ia2[i][j];
    std::cout << std::endl;
    int ia3[3][4] = {0, 3, 6, 9}; // 036900000000

    int (&row)[4] = ia[0]; // row = ref to {0, 1, 2, 3}
    int (*row1)[4] = &ia[0]; // row1 = pointer to {0, 1, 2, 3}, the subscript must equal because that the dimension is the type of an array.

    constexpr size_t rows = 3, columns = 4;

    /* use auto to process elements in array */
    int aaa[rows][columns];
    size_t cnt = 0;
    for (auto &r : aaa)
        for (auto &c : r) {
            c = cnt;
            ++cnt;
        }

    for (auto r : aaa)  // error!!!! because that when r is not the ref to aaa's 0th array, it is automatically converted r as a pointer to 0th array's 1st element. Then, the inner for loop will be considered as iterating a int*, which is illegal.
        for (auto c : r)
            ++cnt;
}

