#include <iostream>

using namespace std;

int main(void)
{
    int num;
    cout << "Input no. of layer n (1-30): ";
    cin >> num;

    int max = 1 + 2 * (num - 1);
    int median = (max + 0) / 2;
    for (unsigned int i = 0; i < num; i++) {
        for (int j = 0; j < max; j++) {
            char c;
            if (j >= median - i && j <= median + i)
                c = '.';
            else
                c = ' ';
            cout << c;
        }
        cout << endl;
    }

}
