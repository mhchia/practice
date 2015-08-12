#include <iostream>

using std::string;

int main(void)
{
    string s;
    /** read line at a time.
    while (getline(std::cin, s))
        std::cout << s << std::endl;
    */
    /* read word at a time */
    while (std::cin >> s) // string >> op reads stream from cin. when encounters ' ' '\n', it returns the istream object. when encounters EOF or invalid characters in a condition, it's return will be considered as 'false'
        std::cout << s << std::endl;
    return 0;
}

