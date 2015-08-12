#include <iostream>
#include <cctype>

int main(void)
{
    char ch, ch_prev = 0;

    unsigned int vowel_cnt = 0, ff_cnt = 0, fl_cnt = 0, fi_cnt = 0;
    while (std::cin >> ch) {
        ch = tolower(ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            ++vowel_cnt;
        }
        if (ch_prev == 'f' && ch == 'f') {
            ++ff_cnt;
        }
        if (ch_prev == 'f' && ch == 'l') {
            ++fl_cnt;
        }
        if (ch_prev == 'f' && ch == 'i') {
            ++fi_cnt;
        }

        ch_prev = ch;
    }

    std::cout << "vowel count = " << vowel_cnt << std::endl;
    std::cout << "ff count = " << ff_cnt << std::endl;
    std::cout << "fl count = " << fl_cnt << std::endl;
    std::cout << "fi count = " << fi_cnt << std::endl;

    return 0;
}

