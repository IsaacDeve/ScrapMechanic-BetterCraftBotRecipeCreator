#include "gui.hpp"
#include "itemclass.hpp"

#include <iostream>
#include <fstream>

#include <json.hpp>

using json = nlohmann::json;

std::vector<Item> items;

int itemIds = 0;

std::string FindNameById(std::string id) {
    std::ifstream f("craftables.json");
    json j;

    f >> j;
    f.close();

    for (const auto& entry : j) {
        if (entry["Id"] == id) {
            return entry["Name"];
        }
    }

    return "Unknown";

}

void LoadJsonPath(const std::string path) {
    try {

        itemIds = 0;

        items.clear();

        gui::pathToRec = path;
        SetWindowTitle((std::string(program::title) + " - " + gui::pathToRec).c_str());

        json j;
        std::ifstream f(path);

        if (!f.is_open()) return;

        f >> j;

        for (const auto& entry : j) {
            Item item;

            std::strncpy(item.itemId, entry["itemId"].get<std::string>().c_str(), 64);
            item.itemId[63] = '\0';

            item.quantity = entry["quantity"];
            item.craftTime = entry["craftTime"];

            
            for (const auto& ing : entry["ingredientList"]) {
                Ingredient ingredient;
                std::strncpy(ingredient.itemId, ing["itemId"].get<std::string>().c_str(), 63);

                ingredient.quantity = ing["quantity"];
                item.ingredientList.push_back(ingredient);
            }

            items.push_back(item);
        }
    }
    catch(const std::exception& ex) {
        std::cerr<<ex.what()<<"\n";
    }
}