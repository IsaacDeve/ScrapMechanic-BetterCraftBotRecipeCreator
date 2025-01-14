#include <iostream>
#include "config.hpp"

namespace gui {
    void Begin()
    {
        rlImGuiBegin();

        if (ImGui::Begin("hfgh"), NULL, ImGuiWindowFlags_NoCollapse)
        {
            if (ImGui::Button("Save and quit"))
            {
                std::cout << "skibidi";
            }
            ImGui::End();
        }
        rlImGuiEnd();
    }
};