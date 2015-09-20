#include <iostream>
#include <stdexcept>

int main(void)
{
    std::cout << "Enter two strings, I will compare them for you : ";
    std::string s1, s2;
    /*
    std::cin >> s1 >> s2;

    if (s1 == s2) {
        throw std::runtime_error("Dont enter the same string\?\n");
    }

    std::cout << (s1 < s2) << std::endl;
    */

    while (std::cin >> s1 >> s2) {
        try {
            if (s1 == s2)
                throw std::runtime_error("Same strings :(");
        } catch (std::runtime_error err) {
            std::cout << err.what()
                      << "\nTry Again? Enter y or n" << std::endl;
            char c;
            std::cin >> c;
            if (!std::cin || c == 'n')
                break; // break is associated with for, while, do while, switch. However, continue is with for, while, do while.
        }
    }

    return 0;
}

