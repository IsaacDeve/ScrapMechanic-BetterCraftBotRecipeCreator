#include <vector>

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

void LoadJsonPath(const std::string path);