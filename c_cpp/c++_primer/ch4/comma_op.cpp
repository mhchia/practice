#include <iostream>
#include <vector>

using std::vector;
int main(void)
{
    vector<int> a(10); // value init 10 elements.

    unsigned int cnt = 10; // init.
    /* comma operator ensure that the first operand is evaluated before the second one. The expression returns the result of its right-hand expression as lvalue if it is lvalue. */
    for (vector<int>::size_type ix = 0;  ix != a.size(); ix++, cnt--)
        a[ix] = cnt;

    for (auto i = a.begin(); i != a.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;

    int a1 = 1, a2 = 2;
    int &c = (++a1, --a2); // c refs to a2, because comma operator returns the result of right-hand expression as lvalue.
    int &d = (++a1, a1); // its ok, because comma operator ensures the evaluation order. Otherwise, using and modifying variables in a single expression is undefined.

    std::cout << c << std::endl; // 1


    return 0;
}

