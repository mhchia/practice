#include <iostream>

int main(void)
{
    std::string s1, s2, ans;

    do {
        std::cout << "Enter 2 strings, I will compare them for you! : ";
        std::cin >> s1 >> s2;
        if (s1 < s2)
            std::cout << s1 << " < " << s2 << std::endl;
        else if (s1 > s2)
            std::cout << s1 << " > " << s2 << std::endl;
        else
            std::cout << s1 << " == " << s2 << std::endl;
        std::cout << "Enter yes to do it again, no to terminate this process : ";
        std::cin >> ans;
    } while (!ans.empty() && ans[0] != 'n');

    return 0;
}

