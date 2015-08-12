#include <vector>
#include <iostream>

using namespace std;
int main(void)
{
    vector<int> ivec;
    int temp;
    while (cin >> temp)
        ivec.push_back(temp);

    /* adjacent sum
    for (auto it = ivec.cbegin(); it != ivec.cend() - 1; ++it)
        cout << *it + *(it + 1) << " ";
    cout << endl;
    */

    for (auto it = ivec.cbegin(); it != ivec.cbegin() + static_cast<vector<int>::difference_type>((ivec.size()+1) / 2); ++it)
        cout << *it + *((ivec.cend()-1) - (it-ivec.cbegin())) << " ";
    cout << endl;
}

