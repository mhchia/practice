#include <iostream>

int main(void)
{

    std::string s, last; // default init to ""
    while (std::cin >> s) {
        if (s == last) {
            std::cout << s << std::endl;
            break;
        }

        last = s; // at the end of the while body, assign s to last.
    }

    if (s != last)
        std::cout << "No successive words" << std::endl;

    return 0;
}

