#include <iostream>
#include <string>
#include <cstddef>

using std::string;
using std::cout;
using std::endl;

int RecursiveCompareCString(const char *a, const char *b)
{
    if (*a == '\0' && *b != '\0')
        return -1;
    if (*a != '\0' && *b == '\0')
        return 1;
    if (*a == '\0' && *b == '\0')
        return 0;

    if (*a == *b)
        return RecursiveCompareCString(a+1, b+1);
    else if (*a < *b)
        return -1;
    else
        return 1;
}
int main(void)
{
    /* compare strings */
    string a, b; // empty strings.
    if (a == b) {
        cout << "=" << endl;
    } else if (a < b) {
        cout << "<" << endl;
    } else {
        cout << ">" << endl;
    }

    /* comparing c-type strings */
    char a1[] = "aaaa", b1[] = "aaa";
    cout << RecursiveCompareCString(a1, b1) << endl;

    return 0;
}

