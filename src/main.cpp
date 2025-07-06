#include "gui.hpp"
#include <iostream>
#include <string>

#include "itemclass.hpp"

#include <raylib.h>

// © 2025 IsaacDeve. All rights reserved.
// This software is licensed under the MIT license.

int main(int argc, char* argv[]) {
    //SetConfigFlags();
    InitWindow(program::width, program::height, program::title);


    if (argc>1) {
        LoadJsonPath(argv[1]);
    }

    SetTargetFPS(60); 
    rlImGuiSetup(true);
    while (!WindowShouldClose()) {

        if (IsFileDropped()) {
            FilePathList droppedFiles = LoadDroppedFiles();
            if (droppedFiles.count > 0) {
                LoadJsonPath(droppedFiles.paths[0]);
            }
        }


        BeginDrawing();
        ClearBackground({15, 19, 77, 255});
        gui::Update();

        EndDrawing();
    }
    
    rlImGuiShutdown();

    CloseWindow();
    return 0;
}