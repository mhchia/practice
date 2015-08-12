#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
int main(void)
{
    vector<string> svec;

    vector<int> ivec;
    ivec.push_back(1);
    vector<int> ivec2(ivec); // copy elements of ivec into ivec2
    vector<int> ivec3 = ivec; // the same as above
    vector<string> svec1(ivec2); // error vector<string> holds only string objects.
}

