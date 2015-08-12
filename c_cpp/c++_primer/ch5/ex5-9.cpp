#include <iostream>

int main(void)
{
    char ch;

    unsigned int vowel_cnt = 0;
    while (std::cin >> ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            ++vowel_cnt;
        }
    }

    std::cout << "vowel count = " << vowel_cnt << std::endl;

    return 0;
}

