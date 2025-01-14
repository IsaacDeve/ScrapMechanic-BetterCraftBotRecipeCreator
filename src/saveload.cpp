#include "saveload.hpp"
#include "json.hpp"

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

#ifdef CloseWindow
#undef CloseWindow
#endif

#ifdef ShowCursor
#undef ShowCursor
#endif

#include <commdlg.h>
#include <iostream>
#include <string>

using json = nlohmann::json;

namespace sl {

    std::string loadedPath = "Select path to craftbot.json!";

    class Item {
        
    }

    std::string OpenFileDialog() {
        char filename[MAX_PATH] = "";
        OPENFILENAME ofn;
        ZeroMemory(&ofn, sizeof(ofn)); 
        ofn.lStructSize = sizeof(ofn);
        ofn.hwndOwner = nullptr;
        ofn.lpstrFilter = "All Files\0*.*\0Json Files\0*.json\0\0";
        ofn.lpstrFile = filename;
        ofn.nMaxFile = MAX_PATH;
        ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

        if (GetOpenFileName(&ofn)) {
            return std::string(filename);
        }
        return loadedPath;
    }

    void Save() {
        
    }

    void Update() {
        
    }

    void Load() {
        loadedPath = OpenFileDialog(); 
    }
}
