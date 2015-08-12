#include <vector>

using std::vector;

int main(void)
{
    // list init
    vector<int> ints = {1, 3, 2}; // ok
    vector<int> ints1{1, 2, 3}; // ok
    vector<int> ints2(1, 2, 3); // error : 
}

