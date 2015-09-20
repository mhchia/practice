#include <iostream>
#include <cctype>


bool HasCapitalLetters(const std::string &s)
{
    for (auto i : s)
        if (i >= 'A' && i <= 'Z')
            return true;

    return false;
}

void StringTolower(std::string &s)
{
    for (std::string::size_type i = 0; i < s.size(); ++i)
        s[i] = tolower(s[i]);
    return;
}

int main(void)
{
    std::string s("Literal");
    std::cout << HasCapitalLetters(s) << std::endl;
    StringTolower(s);
    std::cout << s << std::endl;
}

