#include <cctype>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
int main(void)
{
    vector<int> ivec; // empty vector
    auto b = ivec.begin(), e = ivec.end(); // because that the two iter must have the same type, it ok to use the same base type.
    /* a valid iterator must be either an element or an end */

    std::string s("hello world.");
    if (s.begin() != s.end()) { // ensure that s is not an empty string, because we want to deference the s.begin() to get the first character of s. Otherwise, deference an off-the-end iterator incurs undefined behavior.
        auto it = s.begin(); // char iterator
        *it = toupper(*it);
    }
    std::cout << s << std::endl;

    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
        *it = toupper(*it);
    std::cout << s << std::endl;

    vector<int> v;
    const vector<int> cv;
    vector<int>::iterator it1 = v.begin(); // iterator
    auto it2 = cv.begin(); // const_iterator

    auto it3 = s.cbegin();
//    if (it3 != s.cend())
//        *it3 = '3'; // error, cbegin() returns const_iterator.

    vector<std::string> svec(1, "");
    auto it4 = svec.begin();
    (*it4).empty(); // ok
    *it4.empty(); // error, it4.empty() will be executed first, but it4 is an iterator having no member name empty so errors occur.
}

