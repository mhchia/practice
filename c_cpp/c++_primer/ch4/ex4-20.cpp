#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int main(void)
{
    vector<string> svec;
    vector<string>::iterator iter = svec.begin();

    *iter++; // ok
//    (*iter)++; // error
//    *iter.empty(); // error, vector<string>::iterator has no member named empty
    iter->empty(); // ok, equivalent to (*iter).empty()
//    ++*iter; // error, string type has no operator ++
    iter++->empty(); // ok, equivalent to (*(iter++)).empty(). iter++ returns the copy of unchanged value of iter, called temp_iter for convinience. Then we dereference the temp_iter and get the string. Finally call its member function empty().
}

