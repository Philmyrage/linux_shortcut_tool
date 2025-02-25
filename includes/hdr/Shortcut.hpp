#pragma once

#include <map>
#include <string>

class Shortcut
{
public:
    Shortcut(const std::map<const std::string, std::string> &options);

protected:
private:
    const void generate_shortcut();
};