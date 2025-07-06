#include "rlImGui.h"

#include <iostream>

#ifndef GUI_HPP
#define GUI_HPP

namespace program {
    const int width = 1920/2;
    const int height = 1080/2;

    const char title[] = "Recipe creator 2.0";
}


namespace gui {

    extern std::string pathToRec;

    void Update();
}

#endif // !GUI_HPP