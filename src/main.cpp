#include "config.hpp"
#include <iostream>

// © 2025 IsaacDeve. All rights reserved.
// This software is licensed under the MIT license.

namespace program {
    const int width = 1920/2;
    const int height = 1080/2;

    const char title[] = "Recipe creator 2.0";
}

int main(void) {

    InitWindow(program::width, program::height, program::title);

    SetTargetFPS(60); 
    rlImGuiSetup(true);
    while (!WindowShouldClose()) {
        ClearBackground({15, 19, 77, 255});
        BeginDrawing();
        gui::Begin();

        EndDrawing();
    }
    
    rlImGuiShutdown();

    CloseWindow();
    return 0;
}