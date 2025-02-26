#include <filesystem>
#include <iostream>

#include "Shortcut.hpp"

const std::filesystem::path LOCAL_SHORTCUT_PATH = "$HOME/.local/share/applications";
const std::filesystem::path GLOBAL_SHORTCUT_PATH = "/usr/share/applications";

// Used for development purposes only!
const std::filesystem::path TEST_PATH = "/mnt/Data/";

const void Shortcut::generate_shortcut()
{
    for (auto &o : m_options)
    {
        std::cout << o.second << std::endl;
    }
    // check if a shortcut exits
    // update existing shortcut
    // create shortcut otherwise
}