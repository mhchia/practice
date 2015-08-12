#include <iostream>
#include <string>

using std::string;
int main(void)
{
    string s1, s2; // empty strings, cuz that default init.
    (std::cin >> s1) >> s2;

    /* test the equality for s1 and s2, if not equaled, return who is smaller.
    if (s1 == s2)
        std::cout << "s1 is equaled to s2" << std::endl;
    else if (s1 < s2) {
        std::cout << "s1 < s2" << std::endl;
    } else {
        std::cout << "s1 > s2" << std::endl;
    }
    */

    /* test for length */
    auto s1_len = s1.size();
    string::size_type s2_len = s2.size();
    if (s1_len == s2_len) { // size() return string::size_type
        std::cout << "s1 has the same length as s2" << std::endl;
    } else if (s1_len < s2_len) {
        std::cout << "s1 is shorter than s2" << std::endl;
    } else {
        std::cout << "s2 is shorter than s1" << std::endl;
    }

    return 0;
}

