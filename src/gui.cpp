#include <iostream>
#include "imgui.h"
#include "gui.hpp"

#include <fstream>

#include <json.hpp>

using json = nlohmann::json;

#include <string>

#include "itemclass.hpp"

using namespace ImGui;

namespace gui {

    std::string pathToRec = "";

    int xPanelBlock = program::width/4;



    char searchResults[64];
    void Update()
    {
        rlImGuiBegin();

        SetNextWindowPos(ImVec2(0,0));
        SetNextWindowSize(ImVec2(xPanelBlock, program::height));
        if (Begin("Panel", nullptr, ImGuiWindowFlags_NoCollapse)) {
            if (Button("Save")) {
                json j;

                for (const auto& i : items) {
                    json item;
                    item["itemId"] = i.itemId;
                    item["quantity"] = i.quantity;
                    item["craftTime"] = i.craftTime;

                    json ingredients = json::array();
                    for (const auto& ing : i.ingredientList) {
                        ingredients.push_back({
                            {"itemId", ing.itemId},
                            {"quantity", ing.quantity}
                        });
                    }

                    item["ingredientList"] = ingredients;
                    j.push_back(item);
                }

                std::ofstream f(pathToRec);
                if (f.is_open()) {
                    f << j.dump(4);
                    f.close();
                }
            }

            InputText("Search", searchResults, IM_ARRAYSIZE(searchResults), ImGuiInputTextFlags_EnterReturnsTrue);

            Separator();

            if (Button("Add Item")) {
                Item item;

                strncpy(item.itemId, "", 64);

                item.quantity = 1;
                item.craftTime = 5;

                items.push_back(item);
            }

            End();
        }

        SetNextWindowPos(ImVec2(xPanelBlock, 0));
        SetNextWindowSize(ImVec2(program::width-xPanelBlock, program::height));
        if (Begin("Item list", nullptr, ImGuiWindowFlags_NoCollapse)) {
            itemIds = 0;
            for (auto& i : items) {
                std::string sresults = searchResults;
                std::string itid = i.itemId;

                if (itid.find(sresults) == std::string::npos) continue;
                
                InputText(("itemId##"+std::to_string(itemIds)).c_str(), i.itemId, IM_ARRAYSIZE(i.itemId));
                InputInt(("Quantity##"+std::to_string(itemIds)).c_str(), &i.quantity);
                InputInt(("Craft time##"+std::to_string(itemIds)).c_str(), &i.craftTime);

                int ingIndex = 0;
                for (auto it = i.ingredientList.begin(); it != i.ingredientList.end(); ) {
                    std::string base = std::to_string(itemIds) + "_" + std::to_string(ingIndex);
                    ImGui::PushID(base.c_str());

                    InputText("Ingredient Id", it->itemId, IM_ARRAYSIZE(it->itemId));
                    InputInt("Ingredient quantity", &it->quantity);

                    if (Button("Remove Ingredient")) {
                        it = i.ingredientList.erase(it);
                        ImGui::PopID();
                        continue;
                    }

                    ImGui::PopID();
                    ++it;
                    ++ingIndex;
                }


                if (Button(("Add ingredient##"+std::to_string(itemIds)).c_str())) {
                    Ingredient ing;

                    strncpy(ing.itemId, "", 64);
                    ing.quantity = 1;

                    i.ingredientList.push_back(ing);
                }

                Separator();

                itemIds++;
            }
            End();
        }


        rlImGuiEnd();
    }
};