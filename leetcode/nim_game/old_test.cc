#include <iostream>
#include <vector>

class Solution
{
public:
    // n = a + 2*b + 3*c, and a+b+c must be odd.
    static bool recur(int a, int b, int c, int n) {
        if (n == 3 or n == 2 or n == 1) {
            return true;
        }
        if (!recur(a, b, c+1, n-3)) {
            return (recur(a+1, b, c+1, n-4) or recur(a, b+1, c+1, n-5) or recur(a, b, c+2, n-6));
        }
        if (!recur(a, b+1, c, n-2)) {
            return (recur(a+1, b+1, c, n-3) or recur(a, b+2, c, n-4) or recur(a, b+1, c+1, n-5));
        }
        if (!recur(a+1, b, c, n-1)) {
            return (recur(a+2, b, c, n-2) or recur(a+1, b+1, c, n-3) or recur(a+1, b, c+1, n-4));
        }
        return false;
    }
    static bool canWinNim(int n) {
        return recur(0, 0, 0, n);
    }
};

int main(void)
{
    std::vector<int> s{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 101, 201, 301};
    for (auto num : s) {
        std::cout << "num: " << num << ", result: " << Solution::canWinNim(num) << std::endl;
    }
    return 0;
}

