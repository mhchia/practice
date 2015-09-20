#include <iostream>

using std::string;

bool substr(const string &s1, const string &s2)
{
    if (s1.size() == s2.size())
        return s1 == s2;

    string::size_type size = (s1.size() > s2.size()) ? s2.size() : s1.size();
    for (decltype(size) i = 0; i < size; ++i)
        if (s1[i] != s2[i])
            return false;
    // here should be a return, Failing to provide a return after a loop that contains a return is an error, incurring undefined behavior.
}

int main(void)
{
    std::cout << substr("ha", "haa") << std::endl; // 2, what the fuck.

    return 0;
}

