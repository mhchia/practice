#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> ivec(10, 8); // value init to 1 value=0 element.
    for (auto i : ivec) {
        std::cout << i << " ";
        ivec.push_back(1);
    }
    std::cout << std::endl; // 8 0 8 8 8 8 8 8 8 8, so weird!
    std::cout << ivec.size() << std::endl; // 20

    std::vector<int> ivec2(5, 5); // value init to 1 value=0 element.
    for (auto i : ivec2) { // 感覺ivec2被cached了
        std::cout << i << " ";
        ivec2.erase(ivec2.end() - 1);
    }
    std::cout << std::endl; //
    std::cout << ivec2.size() << std::endl; // 0

    return 0;
}

