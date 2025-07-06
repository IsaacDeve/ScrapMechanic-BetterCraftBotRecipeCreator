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

    int xPanelBlock = program::width/3;
    int xIngredientMargin = 50;

    char searchResults[64];

    char craftablesSearch[64];

    int craftableIds = 0;


    void Update()
    {
        rlImGuiBegin();

        SetNextWindowPos(ImVec2(0,0));
        SetNextWindowSize(ImVec2(xPanelBlock, program::height/5));
        if (Begin("Panel", nullptr, ImGuiWindowFlags_NoCollapse)) {

            if (Button("Save")) {

                if (pathToRec=="") return;

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

            Separator();



            InputText("Search", searchResults, IM_ARRAYSIZE(searchResults));

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


        SetNextWindowPos(ImVec2(0, program::height/5));
        SetNextWindowSize(ImVec2(xPanelBlock, program::height-program::height/5));
        if (Begin("Craftables")) {
            craftableIds = 0;
            if (Button("Update")) {
                UpdateCraftablesList();
            } 

            for (auto& c : craftableList) {
                ImGui::PushItemWidth(-1);
                InputText(("##CraftableName - "+std::to_string(craftableIds)).c_str(), c.name, IM_ARRAYSIZE(c.name));
                InputText(("##CraftableId - "+std::to_string(craftableIds)).c_str(), c.id, IM_ARRAYSIZE(c.id));
                ImGui::PopItemWidth();

                Separator();
                craftableIds++;
            }

            End();
        }

        SetNextWindowPos(ImVec2(xPanelBlock, 0));
        SetNextWindowSize(ImVec2(program::width-xPanelBlock, program::height));
        if (Begin("Item list", nullptr, ImGuiWindowFlags_NoCollapse)) {
            itemIds = 0;
            for (auto itItem = items.begin(); itItem != items.end(); ) {
                std::string sresults = searchResults;
                std::string itid = itItem->itemId;

                if (itid.find(sresults) == std::string::npos) { ++itItem; continue; }

                ImGui::PushID(itemIds);

                if (Button("Remove item")) {
                    itItem = items.erase(itItem);
                    ImGui::PopID();
                    continue;
                }

                ImGui::PopID();

                InputText(("itemId##"+std::to_string(itemIds)).c_str(), itItem->itemId, IM_ARRAYSIZE(itItem->itemId));
                InputInt(("Quantity##"+std::to_string(itemIds)).c_str(), &itItem->quantity);
                InputInt(("Craft time##"+std::to_string(itemIds)).c_str(), &itItem->craftTime);

                SeparatorText("Ingredients");

                int ingIndex = 0;
                for (auto it = itItem->ingredientList.begin(); it != itItem->ingredientList.end(); ) {
                    std::string base = std::to_string(itemIds) + "_" + std::to_string(ingIndex);
                    ImGui::PushID(base.c_str());

                    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + xIngredientMargin);
                    InputText("Ingredient Id", it->itemId, IM_ARRAYSIZE(it->itemId));

                    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + xIngredientMargin);
                    InputInt("Ingredient quantity", &it->quantity);

                    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + xIngredientMargin);
                    if (Button("Remove ingredient")) {
                        it = itItem->ingredientList.erase(it);
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

                    itItem->ingredientList.push_back(ing);
                }

                Separator();
                Separator();
                Separator();

                ++itItem;
                itemIds++;
            }
            End();
        }


        rlImGuiEnd();
    }
};