#include <iostream>
#include <vector>

using std::vector;

template<typename T>
void PrintVectorRecursive(const vector<T> &vec, size_t i)
{
    if (vec.empty() || i >= vec.size())
        return;
    std::cout << vec[i] << " ";

    PrintVectorRecursive(vec, i + 1);
}

int main(void)
{
    vector<int> v1(3, 2);

    PrintVectorRecursive<int>(v1, 0);
}
