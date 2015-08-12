#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(void)
{

    string s; // empyt string because of default initialization.
    std::cin >> s;
    std::cout << s << std::endl;

    string s1, s2; // empty string cuz default init.
    cin >> s1 >> s2;
    cout << s1 << s2 << endl;
    string word; // empty string
    while (cin >> word) // condition will be false when cin reads EOF or invalid character for string type.
        cout << word << endl;
    string line; // empty string cuz default init.
    while (getline(cin, line)) // cin is a istream type object, getline reads stream until encounters a \n and returns the istream object.
        cout << line << endl;

    string line; // empty string
    while (getline(cin, line)) // getline return istream object
        if (!line.empty())
            cout << line << endl;
    string line;
    while (getline(cin, line)) // getline(istream, string_object), return when encounter a \n or EOF or invalid character
        if (line.size() < 10) // output strings whose size < 10 only.
            cout << line << endl;

    return 0;
}

