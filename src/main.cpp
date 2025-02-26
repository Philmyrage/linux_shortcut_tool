#include <iostream>

#include "CommandParser.hpp"
#include "Shortcut.hpp"

int main(int argc, char *argv[])
{
	// if no arguments was provided
	// prompt the user for the information one at a time to get the data for the file.
	// or when add the gui launch the gui app.
	if (argc < 2)
	{
		std::cout << "No arguments provided" << std::endl;
	}
	CommandParser parser = CommandParser(argc, argv);

	const auto &options = parser.get_options();

	for (auto &o : options)
	{
		std::cout << o.second << std::endl;
	}

	return 0;
}
