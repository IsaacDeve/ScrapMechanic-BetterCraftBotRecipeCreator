#include "rlImGui.h"

// © 2025 IsaacDeve. All rights reserved.
// This software is licensed under the MIT license.

int main(void) {

    InitWindow(640, 480, "Recipe creator 2.0");

    SetTargetFPS(60); 
    rlImGuiSetup(true);
    while (!WindowShouldClose()) {
        BeginDrawing();

        EndDrawing();
    }
    
    rlImGuiShutdown();

    CloseWindow();
    return 0;
}