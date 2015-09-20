#include <iostream>

using std::string;

inline bool IsShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
