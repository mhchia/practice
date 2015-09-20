#include <iostream>

const std::string &manip()
{
    std::string s("s");
    if (!s.empty())
        return s;
    else
        return "EMPTY";

}

int main(void)
{
    const std::string &ha = manip();
    std::cout << ha << std::endl; // "", because of undefined bahavior.

    return 0;
}

