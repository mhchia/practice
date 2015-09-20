#include <iostream>

using std::string;

inline const string &
ShorterString(const string &s1, const string &s2)
{
    return (s1.size() >= s2.size()) ? s2 : s1;
}

int main(void)
{
    string s1("ha"), s2("yyyyy");
    std::cout << ShorterString(s1, s2) << std::endl;

    return 0;
}

