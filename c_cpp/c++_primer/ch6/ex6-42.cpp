#include <iostream>

using std::string;

string make_plural(size_t ctr, const string &word,
                               const string &ending = "s") // we can also add default values in definition.
{
    return (ctr > 1) ? word + ending : word;
}


int main(void)
{
    size_t counter;
    std::cin >> counter;
    std::cout << make_plural(counter, "success", "es") << std::endl;
    std::cout << make_plural(counter, "failure", "s") << std::endl;

    return 0;
}

