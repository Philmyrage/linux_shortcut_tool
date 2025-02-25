#pragma once

#include <map>
#include <string>
#include <filesystem>

class CommandParser
{
public:
    CommandParser(const int &argc, char *argv[])
    {
        parse_command(argv, argc);
    }

    // GETTERS
    const std::map<const std::string, std::string> &get_options() { return options; }

protected:
private:
    std::map<const std::string, std::string> options = {
        {"-c", ""},   // Comment
        {"-img", ""}, // Path to Icon
        {"-te", ""},  // Terminal
        {"-typ", ""}, // Type
        {"-cat", ""}, // Categories
        {"-e", ""},   // Exec
        {"-k", ""},   // Keywords
        {"-n", ""}    // name
    };

    const bool is_executable(const std::filesystem::path &path);

    void parse_command(char *argv[], const int &argc);
};