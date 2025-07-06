#include <vector>

#include <json.hpp>

using json = nlohmann::json;

extern int itemIds;

typedef struct Craftable {
    char name[256];
    char id[64];
} Craftable;


extern std::vector<Craftable> craftableList;

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

std::string FindNameById(std::string id);

void LoadJsonPath(const std::string path);

void UpdateCraftablesList();

inline void to_json(json& j, const Ingredient& i) {
    j = json{{"itemId", i.itemId}, {"quantity", i.quantity}};
}

inline void to_json(json& j, const Item& i) {
    j = json{
        {"itemId", i.itemId},
        {"quantity", i.quantity},
        {"craftTime", i.craftTime},
        {"ingredientList", i.ingredientList}
    };
}