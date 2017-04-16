#include <iostream>
#include <string>
#include <vector>

using namespace std;


void count_failure(string& p, vector<int>& failure)
{
    // iterative, bottom-up DP
    for (int i=1, j=failure[0]=-1; i<p.size(); ++i)
    {
        // 先試 p[0...i-1] 的「次長的相同前綴後綴」，
        // 也就是 p[0...failure[i-1]] = p[0...j]。
        // 再試 p[0...j] 的「次長的相同前綴後綴」，
        // 也就是 p[0...failure[j]]。
        // 再試 p[0...failure[j]] 的「次長的相同前綴後綴」……
        // 直到試成功為止。
        while (j >= 0 && p[j+1] != p[i])
            j = failure[j];
 
        // p[i] 終於有用處了，終於可以加長！
        if (p[j+1] == p[i]) j++;
 
        // 得到了 failure[i] 的值！
        failure[i] = j;
    }
}

void count_failure_mine(const string& s, vector<int>& failure)
{
    failure[0] = -1;
    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] == s[failure[i - 1] + 1]) {
            failure[i] = failure[i - 1] + 1;
        } else {
            failure[i] = -1;
        }
    }
}

bool is_same_vector(const vector<int>& a, const vector<int>& b)
{
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main(void)
{
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        string s;
        cin >> s;
        vector<int> failure(s.size());
        count_failure(s, failure);
        vector<int> failure_mine(s.size());
        count_failure(s, failure_mine);
        if (!is_same_vector(failure, failure_mine)) {
            cout << "WRONG!         : " << s << endl;
            cout << "FAILURE        : ";
            for (const auto& i : failure) {
                cout << i << " ";
            }
            cout << endl;
            cout << "FAILURE_MINE   : ";
            for (const auto& i : failure_mine) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

