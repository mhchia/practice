#include <iostream>
#include <vector>

using std::vector;
using std::string;
double calc(double);
int count(const string &, char); // 因為是ref-to-const-string, 可給string literal(const char * type)
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);

int main(void)
{
    // a.
//    calc(23.4, 55.1); // error, too many arguments.
    count("abcda", 'a'); // ok, "abcda" turned into const string ref type
    calc(66); // ok, 66 turned into double
    sum(vec.begin(), vec.end(), 3.8); // ok, 3.8 turned into int.

}

