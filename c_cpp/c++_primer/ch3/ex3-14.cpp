#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    int temp; // undefined value
    vector<int> obj; // empty vector
    while (cin >> temp) {
        obj.push_back(temp);
    }
    for (const auto &i : obj)
        cout << i << endl;
}

