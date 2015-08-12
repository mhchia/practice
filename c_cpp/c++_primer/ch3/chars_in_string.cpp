#include <iostream>
#include <cctype>

using namespace std;

int main(void)
{
    string str("some string"); // direct init from the str literal "hey", equivalent to string s1 = "hey";
    for (auto c : str)
        cout << c << endl;

    string s("Hello World!!!");
    decltype(s.size()) punc_count = 0;
    for (auto c : s)
        if (ispunct(c))
            ++punc_count;
    cout << punc_count << " punctuations in " << s << endl;

    /* using reference to change the characters in a string.
    for (auto &c : s)
        c = toupper(c);
    cout << s << endl;
    */

    if (!s.empty()) // check if the s is empty string, in case of s being empty string which would induce undefined behavior when someone using [] operator.
        cout << s[0] << endl;

    if (!s.empty()) // In addition to using reference, we can use [] operator to change the content of a string.
        s[0] = toupper(s[0]);
    cout << s << endl;

    /* write a for to TO-UPPER the first word in s1! */
    string s1("hey man");
    for (decltype(s1.size()) index = 0; index != s1.size() && !isspace(s1[index]); ++index)
        s1[index] = toupper(s1[index]);
    cout << s1 << endl;

    /* random access to a string using a subscript */

    const string hex_digits = "0123456789abcdef";
    string result_s;
    decltype(hex_digits.size()) subscript;
    while (cin >> subscript) { // using space or tab or \n as the seperator
        if (subscript >= hex_digits.size())
            continue;
        result_s += hex_digits[subscript]; // subscript is of the type string::size_type, always use the subscript with type string::size_type !!!!
    }
    cout << "result : " << result_s << endl;
}

