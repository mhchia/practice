#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(void)
{
    vector<int> v1(10);    // [0, ..., 0]
    vector<int> v2{10};    // [10]
    vector<int> v3(10, 1); // [1, 1, ..., 1]
    vector<int> v4{10, 1}; // [10, 1]

    vector<string> v5{"hi"}; // ["hi"]
    cout << v5.size() << endl; // 1
//    vector<string> v6("ha"); // error, vector<string> constructor only eat vector<string> type or unsigned?
    vector<string> v7{10};  // no error! because compiler cannot list-init by using 10, thus it thinks that this is a value-init, just like v7(10)
    cout << v7.size() << endl; // 10,
    vector<string> v8{10, "hi"}; // no error, just like above.
    cout << v8.size() << endl; // 10

    return 0;
}

