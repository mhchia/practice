#include <iostream>
#include <iterator> // provide begin(), end() function for obtaining an pointers to array's first and one past the last element.

int main(void)
{

    /* pointers and array */
    int ia[] = {0, 1};
    auto ia2(ia); // ia2 is int* rather than int[]
//    ia2 = 42; // error, ia2 is int* not int.

    auto ia3(&ia[0]); // int*
    auto ia4 = ia; // int*

//    decltype(ia) ia5 = {0, 1, 2, 3, 4}; // error, ia is int[2] type but this initializer will cause int[5] type.
    decltype(ia) ia5 = {0}; // ok, {0, 0}
    decltype(ia) ia6 = {0, 1}; // ok
//    ia5 = ia3; // error, ia5 is int[2] but ia3 is int*
    ia5[1] = 42; // ok

    /* pointers are iterators */
    int arr[] = {1, 2, 3};
    int *p = arr; // p points to the first element in arr
    ++p; // p move to the second element
    // using pointer to implement iterator
    int *pbegin = arr, *pend = &arr[3]; // one past the last element
    for (auto it = pbegin; it != pend; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // equivalent to the above
    int *pb = std::begin(arr), *pe = std::end(arr);
    while (pb != pe) {
        std::cout << *pb << " ";
        ++pb;
    }
    std::cout << std::endl;

    constexpr size_t sz = 5; // the subscript eat size_t, ok
    int arr1[sz] = {1, 2, 3, 4, 5}; // ok, constexpr subscript
    int *ip = arr1;
    int *ip2 = ip + 4; // the last element

    int *pp = arr1 + sz; // one past the last element
    int *pp2 = arr1 + 10; // error but not detected by compiler! pp2 has undefined value

    auto n = std::end(arr1) - std::begin(arr1); // the number of elements in arr1

    int ii = 0, jj = 42;
    int *pi = &ii, *pj = &jj;
    std::cout << (pi < pj) << std::endl; // relational operations between unrelated objects are undefined!

    int *ppp = nullptr;
    ppp = ppp + 0; // ok
    ppp = ppp - 0; // ok
    ppp = ppp + 10; // undefined
    ppp = (int *)0x400000; // undefined point something in 0x400000
    std::ptrdiff_t offset = NULL - NULL; // 0
    std::cout << *ppp << std::endl;

    /* difference between array and library type such as vector, string */
    int iia = {0, 2, 4, 6, 8};
    int *pppp = &ia[2]; // equivalent to &iia[0] + 2
    int jjjj = p[1]; // p[1] == *(p+1)
    int k = p[-2]; // p[-2] == *(p-2)
    // subscripts in vector and string are size_type which is unsigned, but built-in subscript for array is signed!
}

