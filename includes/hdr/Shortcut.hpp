#pragma once

#include <map>
#include <string>

class Shortcut
{
public:
    Shortcut(const std::map<const std::string, std::string> &options) : m_options(options)
    {
        generate_shortcut();
    };

protected:
private:
    const void generate_shortcut();
    const std::map<const std::string, std::string> m_options;
};