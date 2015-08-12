#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main(void)
{
    vector<string> words;
    string temp_s;
    while (cin >> temp_s)
        words.push_back(temp_s);

    // process words
    unsigned int cnt = 1;
    for (auto &w : words) {
        for (auto &c : w)
            c = toupper(c);
        cout << w << " ";
        if (cnt++ % 8 == 0)
            cout << endl;
    }

    return 0;
}

