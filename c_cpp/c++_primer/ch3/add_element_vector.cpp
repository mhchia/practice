#include <iostream>
#include <vector>

using std::vector;
using std::string;
int main(void)
{
    vector<string> s; // empty vector
    string temp; // empty string
    while (std::cin >> temp) // operator >> of string keep reading stream from the istream std::cin, and returns istream when read ' ', '\n', '\t'. If it reads EOF, invalid characters for string, it returns something and will be false when converted to the condition.
        s.push_back(temp);

}

