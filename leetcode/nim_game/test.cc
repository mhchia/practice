#include <iostream>
#include <vector>

class Solution{
public:
    // n = a + 2*b + 3*c, and a+b+c must be odd.
    static bool recur(int a, int b, int c, int n) {
        bool me = (a + b + c + 1) % 2;
        if ((a+1) + 2*b + 3*c == n or a + 2*(b+1) + 3*c == n or a + 2*b + 3*(c+1) == n) {
            return me;
        }
        if (a + 2*b + 3*c > n) {
            return false;
        }
        bool answer = !me;
        if ((a+2) + 2*b + 3*c != n) {
            answer |= recur(a+2, b, c, n);
        } else if ((a+1) + 2*(b+1) + 3*c != n) {
            answer |= recur(a+1, b+1, c, n);
        } else if ((a+1) + 2*b + 3*(c+1) != n) {
            answer |= recur(a+1, b, c+1, n);
        } else if (a + 2*(b+2) + 3*c != n) {
            answer |= recur(a, b+2, c, n);
        } else if (a + 2*(b+1) + 3*(c+1) != n) {
            answer |= recur(a, b+1, c+1, n);
        } else if (a + 2*b + 3*(c+2) != n) {
            answer |= recur(a, b, c+2, n);
        }
        return answer;
    }
    static bool canWinNim(int n) {
        return recur(0, 0, 0, n);
    }
};
int main(void)
{
    std::vector<int> s{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 101, 201, 301};
    for (auto num : s) {
        std::cout << "num: " << num << ", result: " << Solution::canWinNim(num) << std::endl;
    }

    return 0;
}

