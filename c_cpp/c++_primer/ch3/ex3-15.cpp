#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
int main(void)
{
    string temp; // empty str, by default init.
    vector<string> s; // empty vector<string> by default init.
    while (std::cin >> temp) {
        s.push_back(temp);
    }
    return 0;
}

