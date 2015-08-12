#include <vector>
#include <string>

using std::vector;
int main(void)
{
    // init vector with count and value
    vector<int> ivec(10, -1); // init ivec with 10 elements with value=-1
    vector<std::string> svec(10, "ha");


    // value init
    vector<int> ivec1(10); // init ivec1 with 10 elements with value=0 (built-in type must be init)
    vector<std::string> svec1(10); // init svec1 with 10 elements with value=empty string cuz default init.
}

