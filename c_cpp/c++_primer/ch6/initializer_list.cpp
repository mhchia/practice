#include <iostream>


using std::string;
using std::initializer_list;

void error_msg(initializer_list<string> ils)
{
    // use auto is good.
    for (initializer_list<string>::const_iterator it = ils.begin(); it != ils.end(); ++it)
        std::cerr << *it << " ";
    std::cerr << std::endl;
}

int main(void)
{
    initializer_list<string> ls;
    initializer_list<int> li; // elements in initializer_list are always const.

    string s("no");
    error_msg({"ha", s}); // ok
//    error_msg({"ha", "yo", 1}); // not ok, needed to be the same type.
}

