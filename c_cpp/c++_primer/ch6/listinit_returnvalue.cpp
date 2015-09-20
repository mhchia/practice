#include <iostream>
#include <vector>

using std::vector;
using std::string;

vector<string> process()
{
    if (true)
        return {"ha", "no", "ya"};
    else
        return {};
}

int p1()
{
    return {}; // ok, 0 caused by value init.
//    return {1}; // ok
//    return {1, 2}; // error: cannot convert ‘<brace-enclosed initializer list>’ to ‘int’ in return
}


int main(void)
{

}

