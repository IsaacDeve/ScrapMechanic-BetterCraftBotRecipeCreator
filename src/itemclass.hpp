#include <vector>


class Ingredient {
    public:
    int quantity;
    char itemId[64];
};

class Item {
    public:

    char itemId[64];
    int quantity;
    int craftTime;

    std::vector<Ingredient> ingredientList;
};

extern std::vector<Item> items;

void LoadJsonPath(const std::string path);