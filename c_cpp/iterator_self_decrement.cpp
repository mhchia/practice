#include <iostream>
#include <vector>

using std::vector;
int main(void)
{
    vector<int> ivec{1, 2, 3};
    std::cout << "ivec.size() = " << ivec.size() << std::endl;
    std::cout << "--ivec.end() returns " << *(--(ivec.end())) << std::endl;
    std::cout << "ivec.size() = " << ivec.size() << std::endl;
    std::cout << "--ivec.end() returns " << *(ivec.end() - 1) << std::endl;
    std::cout << "ivec.size() = " << ivec.size() << std::endl;

    return 0;
}

