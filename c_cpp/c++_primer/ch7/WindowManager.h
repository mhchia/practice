#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <string>
#include <vector>

#include "Screen.h"

class WindowManager {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);

private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

void WindowManager::clear(ScreenIndex i)
{
    if (i >= screens.size())
        return;
    Screen &s = screens[i];
    // reset to all blank
    s.contents = std::string(s.height * s.width, ' ');
}

#endif
