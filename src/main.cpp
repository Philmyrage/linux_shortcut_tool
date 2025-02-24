#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <map>

#include "parseCommand.hpp"

const std::filesystem::path LOCAL_SHORTCUT_PATH = "$HOME/.local/share/applications";
const std::filesystem::path GLOBAL_SHORTCUT_PATH = "/usr/share/applications";

// Used for development purposes only!
const std::filesystem::path TEST_PATH = "/mnt/Data/";

// creates the .desktop file with the parsed data...
const void generate_desktop_file()
{
	// check if their is already a .desktop file with the same name
	// name generated from the name argument + .desktop
	std::ofstream out_file;
}

int main(int argc, char *argv[])
{
	// if no arguments was provided
	// prompt the user for the information one at a time to get the data for the file.
	// or when add the gui launch the gui app.

	parseCommand parser = parseCommand(argc, argv);

	const auto &options = parser.get_options();

	for (auto &o : options)
	{
		std::cout << o.second << std::endl;
	}

	return 0;
}
