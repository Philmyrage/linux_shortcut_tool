#include <iostream>
#include <string>
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
	Shortcut shortcut = Shortcut(parser.get_options());

	return 0;
}
