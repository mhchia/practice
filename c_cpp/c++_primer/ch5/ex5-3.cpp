#include <iostream>
#include <vector>

int get_num()
{
    static int i = 0;
    return i;
}

int main(void)
{
    int sum = 0, val = 1;

    while (val <= 10) {
        sum += val;
        ++val;
    }

    sum = 0, val = 1;
    while (val <= 10)
        sum += val, ++val; // using comma operator to replace a block. It promise that the first operand(sum += val) is evaluate first before the second operand(++val). Thus, there is no undefined behavior due to the order of evaluation.

    while (int i = get_num()) // condition is the return value from (i = get_num())
        std::cout << i << std::endl;
//    i = 0; // error, 'i' is not declared in this scope

    std::vector<int> ivec(10);
    auto beg = ivec.cbegin();
    while (beg != ivec.cend() && *beg >= 0)
        ++beg;
    if (beg == ivec.cend()) { // indicate that all elements in ivec is >=0
        ; // do something

    }

}

