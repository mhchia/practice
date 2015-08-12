#include <iostream>
#include <vector>
#include <string>

using namespace std;


template<typename T>
void print_vector(const T &vec)
{
    cout << "size : " << vec.size() << "\n" << "content : ";
    for (auto it = vec.cbegin(); it != vec.cend(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main(void)
{
    vector<int> v1; // 0
    vector<int> v2(10); // 10, 0's
    vector<int> v3(10, 42); // 10, 42's
    vector<int> v4{10}; // 1, 10
    vector<int> v5{10, 42}; // 2, [10, 42]
    vector<string> v6{10}; // 10, ["", ... , ""]
    vector<string> v7{10, "hi"}; // 10, ["hi", ..., "hi"]

    print_vector(v1);
    print_vector(v2);
    print_vector(v3);
    print_vector(v4);
    print_vector(v5);
    print_vector(v6);
    print_vector(v7);
    return 0;
}

