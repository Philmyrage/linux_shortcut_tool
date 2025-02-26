#include <filesystem>
#include <iostream>
#include <fstream>

#include "Shortcut.hpp"

const std::filesystem::path LOCAL_SHORTCUT_PATH = "$HOME/.local/share/applications";
const std::filesystem::path GLOBAL_SHORTCUT_PATH = "/usr/share/applications";

// Used for development purposes only!
const std::string TEST_PATH = "/mnt/Data/";

const void Shortcut::generate_shortcut()
{
    std::ofstream shortcut_file;

    if (std::filesystem::exists(TEST_PATH + m_options.at("-n")))
    {
        std::cout << "Shortcut already exists" << std::endl;
        // TODO: open existing shortcut and make edits
        shortcut_file.open(TEST_PATH + m_options.at("-n"));
        if (shortcut_file.is_open())
        {
            std::cout << "File opened" << std::endl;
        }
        else
        {
            std::cerr << "Failed to open file" << std::endl;
        }
    }
    else
    {
        // TODO: create shortcut
        shortcut_file.open(TEST_PATH + m_options.at("-n"));
        if (shortcut_file.is_open())
        {
            std::cout << "File opened" << std::endl;
        }
        else
        {
            std::cerr << "Failed to open file" << std::endl;
        }
        std::cout << "Creating shortcut" << std::endl;
    }

    shortcut_file.close();
}