#include <iostream>
#include <vector>

int main(void)
{
    int array[10] = {}; // list init to 0.
    for (int i = 0; i < 10; ++i)
        array[i] = i;
    for (const auto &i : array)
        std::cout << i << " ";
    std::cout << std::endl;

    /* copy array to another */
    // because that array has no copy or assignment op thus we need to cop elements 1 by 1.
    int a[10] = {};
    for (int i = 0; i < 10; ++i)
        a[i] = array[i];

    /* rewrite above using vector */
    std::vector<int> ivec; // epmty vector by default init.
    for (const auto &i : array)
        ivec.push_back(i);

    for (const auto &i : ivec)
        std::cout << i << " ";
    std::cout << std::endl;
}

