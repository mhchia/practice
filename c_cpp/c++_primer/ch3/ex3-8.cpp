#include <iostream>

int main(void)
{
    std::string s = "aaa";
    std::string::size_type subscript = 0;
    while (subscript < s.size())
        s[subscript++] = 'X';
    std::cout << s << std::endl;

    return 0;
}

