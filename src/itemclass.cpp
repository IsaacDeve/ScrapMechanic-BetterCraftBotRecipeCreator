#include "gui.hpp"
#include "itemclass.hpp"

#include <json.hpp>

void LoadJsonPath(const std::string path) {
    gui::pathToRec = path;
    SetWindowTitle((std::string(program::title) + " - " + gui::pathToRec).c_str());
}