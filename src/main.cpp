#include "gui.hpp"
#include <iostream>
#include <string>

#include "itemclass.hpp"

#include <raylib.h>

// © 2025 IsaacDeve. All rights reserved.
// This software is licensed under the MIT license.

int main(int argc, char* argv[]) {

    static bool fileJustDropped = false;

    //SetConfigFlags();

    InitWindow(program::width, program::height, program::title);

    SetExitKey(KEY_NULL);

    if (argc>1) {
        LoadJsonPath(argv[1]);
    }

    SetTargetFPS(60); 
    rlImGuiSetup(true);

    UpdateCraftablesList();

    while (!WindowShouldClose()) {

    if (IsFileDropped() && !fileJustDropped) {
        FilePathList droppedFiles = LoadDroppedFiles();
        if (droppedFiles.count > 0) {
            LoadJsonPath(droppedFiles.paths[0]);
            fileJustDropped = true;
        }
        UnloadDroppedFiles(droppedFiles);
    }

    if (!IsFileDropped()) {
        fileJustDropped = false;
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