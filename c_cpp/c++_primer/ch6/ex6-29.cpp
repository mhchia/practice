#include <iostream>

/*
    This practice indicates that elements in initializer_list<T> are const type
*/

int main(void)
{
    std::initializer_list<int> il{1, 2, 5, 5};

    std::initializer_list<int> il2; // default init to empty il.
    std::cout << il2.size() << std::endl; // 0

    il2 = il; // il2 and il shares the same elements in il.

    std::cout << il2.size() << std::endl; // 4

    std::cout << &(*(il.begin())) << " " << &(*(il2.begin())) << std::endl; // the same address, means that the same object.

    for (auto &i : il) {
        i = i * 2; // error, assignment of read-only reference ‘i’
    }

}

