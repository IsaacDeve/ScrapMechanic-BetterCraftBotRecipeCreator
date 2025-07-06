#include <vector>

#include "gui.hpp"

class Ingredient {
    public:
    int quantity;
    std::string itemId;
};

class Item {
    public:

    std::string itemId;
    int quantity;
    int craftTime;

    std::vector<Ingredient> ingredientList;
};

inline void LoadJsonPath(const std::string path) {
    gui::pathToRec = path;
    SetWindowTitle((std::string(program::title) + " - " + gui::pathToRec).c_str());
}