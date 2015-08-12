#include <iostream>
#include <cctype>

int main(void)
{
    std::string s; // empty string due to default init.
    std::cin >> s;
    for (auto &c : s)
        if (ispunct(c))
            c = ' ';
    std::cout << s << std::endl;

    return 0;
}

