#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    vector<int> integers; // empty vector due to default init.
    int temp;
    while (cin >> temp)
        integers.push_back(temp);

    /* print adjacent elements sums
    for (decltype(integers.size()) subscript = 0; subscript < integers.size() - 1; ++subscript)
        cout << integers[subscript] + integers[subscript + 1] << endl;
    */
    /* print first-last sums, second-secondtolast sums, ... */
    for (decltype(integers.size()) subscript = 0; subscript < (integers.size() + 1) / 2; ++subscript)
        cout << integers[subscript] + integers[integers.size() - subscript - 1] << endl;
}

