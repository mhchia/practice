#include <iostream>
#include <vector>

using std::vector;

void RecurPrintVector(const vector<int> &vec,
                      vector<int>::size_type index)
{
    if (index == vec.size()) {
        return;
    }
    std::cout << vec[index] << std::endl;
#ifndef NDEBUG // if debugging like assert is usable.
    std::cout << "DEBUGGING : vec.size() = " << vec.size() << std::endl;
#endif
    RecurPrintVector(vec, index + 1);
}

int main(void)
{
    vector<int> vec1(1, 2);
    RecurPrintVector(vec1, 0);

    return 0;
}

