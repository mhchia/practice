#include <map>
#include <iostream>

using namespace std;

map<int, string> students;

int main(void)
{
    students[2] = "2";
    map<int, string>::const_iterator a = students.insert(pair<int, string>(2, "3"));
//    cout << a << endl;
}
