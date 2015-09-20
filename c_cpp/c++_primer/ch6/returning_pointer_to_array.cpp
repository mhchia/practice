#include <iostream>


/* 1. using type alias */
typedef int arrT[10];
using arrT = int[10];
arrT* func(int i); // because that we cannot copy an array, we can only return pointer to array.
arrT& func2(arrT&); // returning reference to array.

/* 2. without alias */
// format : type (*function(param_list))[dimension]

//int[10] *func3(int i); // error, wrong syntax.
//int (*func3(int i))[10]; // this is the correct one.

// a function that returns pointer to array of 100 chars
char (*function(int))[100];

// write a function declaration that returns array of 36 bool.
bool (*ExamResult(int day))[36];

int c[50] = {1}; // default init to 1, 0, 0, ...
int (&ReturnC(void))[50] // return the reference to c which is an array of 50 int.
{
    return c;
}

/* 3. using the trailing return type in c++11 */
auto func3(int) -> int (*)[10];

auto func4(int a) -> int (*)[50]
{
    return &c;
}

/* 4. using decltype in c++11 */
decltype(c) *func5(void) // 比較沒用，因為c必須在function外，即全域變數
{
    return &c;
}

int main(void)
{
    int (*a)[50] = &ReturnC();
    for (const auto i : *a)
        std::cout << i << " "; // 1, 0, 0, ....
    std::cout << std::endl;

    // the same as above.
    for (const auto i: *(func4(4)))
        std::cout << i << " ";
    std::cout << std::endl;

}

