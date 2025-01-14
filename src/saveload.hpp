#ifndef SAVELOAD_HPP
#define SAVELOAD_HPP

#include <iostream>

namespace sl {
    extern std::string loadedPath;

    std::string OpenFileDialog();
    void Save();
    void Update();
    void Load();
};

#endif // !SAVELOAD_HPP