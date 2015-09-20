#include <iostream>

using std::string;

char &get_val(string &s, string::size_type index) // returns lvalue (reference).
{
    return s[index];
}

int main(void)
{
    string s = "haha";
    get_val(s, 0) = 'y'; // because get_val() returns lvalue, we can use it at the left hand side of assignment.
    std::cout << s << std::endl; // yaha,  so coooooooool!

    return 0;
}

