#include <iostream>

using std::string;
using std::cout;
using std::endl;
int main(void)
{
    string s = "aaa";
    for (char c : s)
        c = 'X';
    cout << s << endl;
}

