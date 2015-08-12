#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(void)
{
    string large_s, temp_s; // empty strings, due to default init.
    while (cin >> temp_s) { // >> operator of string read from istream object until encounter an space or \n or tab, and return the istream object. if encounter EOF or Invalid chars, it returns something will be convert to the condition false.
        large_s += (temp_s + " "); // equivalent to large_s = large_s + temps
    }

    cout << large_s << endl;

    return 0;
}

