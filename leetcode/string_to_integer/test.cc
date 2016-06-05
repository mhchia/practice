#include <string>
#include <vector>
#include <iostream>

#include <cmath>
#include <cctype>

using namespace std;

class Solution {
public:
    static int myAtoi(string str) {
        bool flag = false;
        string a;
        for (auto i : str) {
            if (flag && i == ' ')
                break;
            if (i != ' ')
                a += i;
            if (isdigit(i) || i == '-' || i == '+')
                flag = true;
        }
        str = a;

        a = "";
        for (int n = 0; n < str.size(); ++n) {
            if (!isdigit(str[n]) && str[n] != '-' && str[n] != '+')
                break;
            a += str[n];
        }
        str = a;

        long long sum = 0;
        long long sign = 1;
        int i = -1;
        for (i = str.size() - 1; i >= 0; --i) {
            auto power = str.size() - 1 - i;
            if (!isdigit(str[i]))
                break;
            sum += (str[i] - '0') * pow(10, power);
        }
        for (int j = 0; j <= i; ++j) {
            if (str[j] == '-') {
                sign *= -1;
            }
        }
        if (str.size() - 1 - i > 10) {
            if (sign > 0)
                sum = 2147483647;
            else
                sum = -2147483648;
        }
        if (i >= 1)
            sign = 0;
        long long answer = sign * sum;
        if (answer > 2147483647)
            answer = 2147483647;
        else if (answer < -2147483648)
            answer = -2147483648;
        return answer;
    }

};

int main(void)
{
    vector<string> s{"  -0012a42", "1", "   +0 123", "2147483648", "-2147483649", "   - 321"};
    for (vector<string>::iterator it = s.begin(); it != s.end(); ++it) {
        std::cout << Solution::myAtoi(*it) << std::endl;
    }

    return 0;
}

