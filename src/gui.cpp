#include <iostream>
#include "config.hpp"
#include "saveload.hpp"

namespace gui {
    void Begin()
    {
        sl::items.emplace_back();
        rlImGuiBegin();
        sl::Update();

        if (ImGui::Begin("Items"), NULL, ImGuiWindowFlags_NoCollapse)
        {
            ImGui::Text(sl::loadedPath.c_str());
            ImGui::Separator();
        
            ImGui::End();
        }

        if (ImGui::Begin("Panel with buttons"), NULL, ImGuiWindowFlags_NoCollapse)
        {
            if (ImGui::Button("Add"))
            {

            }

            ImGui::Separator();

            if (ImGui::Button("Save"))
            {
                sl::Save();
            }

            ImGui::SameLine();

            if (ImGui::Button("Load"))
            {
                sl::Load();
            }

            ImGui::End();
        }
        rlImGuiEnd();
    }
};