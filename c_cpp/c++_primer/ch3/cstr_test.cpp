#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using std::vector;
using std::string;

int main(void)
{
    string s("hello world");
//    char *str = s; // error, cannot use string type to init a char*
    const char *str = s.c_str(); // ok, but c_str() returns const char*
    /*
    std::cout << "addr of s : " << &s << std::endl;
    std::cout << "addr of s.c_str() : " << &str << std::endl;
    */
    s[5] = 's';
    std::cout << str << std::endl; // "hellosworld", so if we change s, the previos c_str() will be changed, too.

    /* init vector by array */
    int int_arr[] = {1, 2, 3};
    vector<int> ivec(std::begin(int_arr), std::end(int_arr)); // only c++11
    std::cout << ivec.size() << std::endl; // 3
    vector<int> ivec1(int_arr, int_arr+3); // ok
    std::cout << (ivec == ivec1) << std::endl; // ivec == ivec1
}

