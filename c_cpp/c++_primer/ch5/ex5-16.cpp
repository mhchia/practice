#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> ivec(10); // value init, 10 value=0 elements.
    for (decltype(ivec.size()) i = 0; i < ivec.size(); ++i)
        ivec[i] = 1;

    std::string s;
    while (std::cin >> s)
        std::cout << s << std::endl;

    /* reverse */
    decltype(ivec.size()) i = 0;
    while (i < ivec.size()) {
        ivec[i] = 1;
        ++i;
    }

    for (std::string s; std::cin >> s;)
        std::cout << s << std::endl;
}

