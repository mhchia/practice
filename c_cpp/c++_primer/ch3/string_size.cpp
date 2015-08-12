#include <string>
using std::string;

int main(void)
{
    string line("ha");
    /* these three all get string::size_type type. */
    string::size_type line_size1 = line.size();
    auto line_size2 = line.size();
    decltype(line.size()) line_size3 = line.size();
}

