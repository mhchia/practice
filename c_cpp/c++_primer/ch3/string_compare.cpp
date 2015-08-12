#include <iostream>

using std::string;
int main(void)
{
    // lexical order.
    string s1 = "hello";
    string s2 = "helloworld";
    string s3 = "hiya";
    std::cout << (s1 < s2) << (s2 < s3) << std::endl; // result : 11
}

