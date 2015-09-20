#include <iostream>
#include <cctype>
#include <string>
#include <cstring>
#include <stdexcept>
#include <boost/lexical_cast.hpp>

bool CheckFloatStringFormat(const std::string &s)
{
    unsigned pointCount = 0;
    for (std::string::const_iterator it = s.cbegin(); it != s.cend(); ++it) {
        if (*it == '.') {
            ++pointCount;
            continue;
        }
        if (!std::isdigit(*it)) {
            return false;
        }
    }
    if (pointCount > 1 || s.size() - pointCount <= 0) {
        return false;
    }
    return true;
}

int64_t FloatStringToInt64(const std::string &s)
{
    if (!CheckFloatStringFormat(s)) {
        throw std::runtime_error("CheckFloatStringFormat failed\n");
    }

    if (s.find('.') == std::string::npos) { // there is no point
        return boost::lexical_cast<int64_t>(s + "00000000");
    }
    return 1;
}

int main(void)
{
    const std::string s = "797928016.99999163";
    const std::string s1 = "10000000000";
    std::cout << FloatStringToInt64(s1) << std::endl;
}

