#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void)
{
    unordered_map<int, string> ums;
    for (size_t i = 0; i < 5; ++i) {
        ums.insert({i, "haha"});
    }
    for (unordered_map<int, string>::iterator it = ums.begin(); it != ums.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    std::string a("123");
    char b[] = "123";
    cout << (a == b) << endl;
    return 0;
}

