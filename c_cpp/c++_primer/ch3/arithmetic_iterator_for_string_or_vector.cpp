#include <iostream>
#include <vector>

using std::vector;
using std::string;
int main(void)
{
    /* these ops are available only for vector and string */
    vector<int> vi; // empty
    auto mid = vi.begin() + vi.size() / 2;

    string s;
    auto mid1 = s.begin() + s.size() / 2;
    auto it = s.begin();
    if (it <= mid1) // compare the iterator's position
        std::cout << "haha" << std::endl;

    auto difference = mid1 - it; // this is the string::difference_type, indicating that the distance between mid1 and it
}

