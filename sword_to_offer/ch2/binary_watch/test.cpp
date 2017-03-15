#include <iostream>


using namespace std;



// O(2^n)
void m_len_n_1(bool nums[], int len, int pos, int count)
{
    if (pos == len) {
        if (count == 0) {
            for (int i = 0; i < len; ++i) {
                cout << nums[i];
            }
            cout << endl;
        }
        return;
    }
    nums[pos] = true;
    m_len_n_1(nums, len, pos + 1, count - 1);
    nums[pos] = false;
    m_len_n_1(nums, len, pos + 1, count);
}

int main(void)
{
    bool nums[10] = {0};
    m_len_n_1(nums, 10, 0, 5);
    // cout << true << endl;
}

