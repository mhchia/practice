#include <iostream>
#include <vector>

int main(void)
{
    /* traditional for */
    unsigned int i = 0;
    // omit initialization.
    for (; i < 10; ++i); // null statement.

    // omit condition
    for (unsigned int i = 0;; ++i); // infinite loop, empty condition is equivalent to putting 'true' in condition.

    // omit expression
    for (unsigned int i = 0; i++ < 10;);

    std::vector<int> ivec(10); // value init, 10 value=0 elements.
    for (int i; std::cin >> i;)
        ivec.push_back(i);

    /* range for */
    std::vector<float> fvec(10); // value init.
    for (int i : fvec); // ok, float type elements will be converted to int type.
}

