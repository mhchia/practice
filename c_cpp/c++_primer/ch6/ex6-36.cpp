#include <iostream>

using std::string;

string c[10]; // default init to "".

string (&return_c(void))[10]
{
    return c;
}

int main(void)
{

}

