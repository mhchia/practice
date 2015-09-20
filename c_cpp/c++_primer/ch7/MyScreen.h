#ifndef MY_SCREEN_H
#define MY_SCREEN_H

#include <string>

class MyScreen {
public:
    using pos = std::string::size_type;
    MyScreen() = default;
    MyScreen(pos hei, pos wid) : height(hei), width(wid),
                                 contents(hei * wid, ' ') {}
    MyScreen(pos hei, pos wid, char c) : height(hei), width(wid),
                                         contents(hei * wid, c) {}

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};


#endif
