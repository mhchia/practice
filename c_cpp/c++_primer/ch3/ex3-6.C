#include <iostream>

using std::string;
using std::cout;
using std::endl;
int main(void)
{
    string s("aaa");
    for (auto &c : s)
        c = 'X';
    cout << s << endl;

    for (decltype(s.size()) subscript = 0; subscript < s.size(); ++subscript)
        s[subscript] = 'x';

    cout << s << endl;
}

