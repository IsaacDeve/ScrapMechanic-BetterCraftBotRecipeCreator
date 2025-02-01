#ifndef SAVELOAD_HPP
#define SAVELOAD_HPP

#include "imgui.h"
#include "json.hpp"

#include <iostream>
#include <vector>

namespace sl {
    extern std::string loadedPath;

    class Item {
    public:
        std::string name;

        Item() : name("Unspecified") {}

        Item(std::string name) : name(name) {}

        void AddToPanel() const {
            ImGui::Button(name.c_str());
        }
    };

    extern std::vector<Item> items;

    std::string OpenFileDialog();
    void Save();
    void Update();
    void Load();
};

#endif // !SAVELOAD_HPP