#include <iostream>
#include <cctype>

int main(void)
{
    char ch;

    unsigned int vowel_cnt = 0, space_cnt = 0, tab_cnt = 0, newlines_cnt = 0;
    while (std::cin.get(ch)) {
        ch = tolower(ch);
        switch (ch) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                ++vowel_cnt;
                break;
            case ' ':
                ++space_cnt;
                break;
            case '\t':
                ++tab_cnt;
                break;
            case '\n':
                ++newlines_cnt;
                break;
            default: // add default indicate that all cases are considered.
                break; // add break to the last case label for good habit.
        }
    }

    std::cout << std::endl;

    std::cout << "vowel count = " << vowel_cnt << std::endl;
    std::cout << "space count = " << space_cnt << std::endl;
    std::cout << "tab count = " << tab_cnt << std::endl;
    std::cout << "newlines count = " << newlines_cnt << std::endl;

    return 0;
}

