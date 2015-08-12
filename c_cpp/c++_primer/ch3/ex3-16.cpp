#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_vector(const T &vec)
{
    static unsigned int count = 0;
    cout << "=========\nv" << (count++) <<"\nsize: " << vec.size() << " elements : ";
    for (const auto &r : vec)
        cout << r << " ";
    cout << endl;
}

int main(void)
{
    vector<int> v1; // empty vector
    print_vector<vector<int>>(v1);

    vector<int> v2(10); // 10 elements with value 0
    print_vector<vector<int>>(v2);

    vector<int> v3(10, 42); // 10 elements with value 42
    print_vector<vector<int>>(v3);

    vector<int> v4{10}; // 1 element with value 10
    print_vector<vector<int>>(v4);

    vector<int> v5{10, 42}; // 2 elements, [10, 42]
    print_vector<vector<int>>(v5);

    vector<string> v6{10}; // 10 elements, ["", "", "", ..., ""]
    print_vector<vector<string>>(v6);

    vector<string> v7{10, "hi"}; // 10 elements, ["hi", ..., "hi"]
    print_vector<vector<string>>(v7);
}

