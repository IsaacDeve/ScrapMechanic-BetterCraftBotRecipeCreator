#include <iostream>
#include "imgui.h"
#include "gui.hpp"

#include "itemclass.hpp"

using namespace ImGui;

namespace gui {

    std::string pathToRec;

    int xPanelBlock = program::width/4;



    char searchResults[64];
    void Update()
    {
        rlImGuiBegin();

        SetNextWindowPos(ImVec2(0,0));
        SetNextWindowSize(ImVec2(xPanelBlock, program::height));
        if (Begin("Panel", nullptr, ImGuiWindowFlags_NoCollapse)) {
            InputText("##input", searchResults, IM_ARRAYSIZE(searchResults), ImGuiInputTextFlags_EnterReturnsTrue);
            End();
        }

        SetNextWindowPos(ImVec2(xPanelBlock, 0));
        SetNextWindowSize(ImVec2(program::width-xPanelBlock, program::height));
        if (Begin("Item list", nullptr, ImGuiWindowFlags_NoCollapse)) {
            for (auto& i : items) {
                InputText("itemId", i.itemId, IM_ARRAYSIZE(i.itemId));
                InputInt("Quantity", &i.quantity);
                InputInt("Craft time", &i.craftTime);

                Separator();
            }
            End();
        }


        rlImGuiEnd();
    }
};