#include <iostream>

#include "CommandParser.hpp"

int main(int argc, char *argv[])
{
	// if no arguments was provided
	// prompt the user for the information one at a time to get the data for the file.
	// or when add the gui launch the gui app.

	CommandParser parser = CommandParser(argc, argv);

	const auto &options = parser.get_options();

	for (auto &o : options)
	{
		std::cout << o.second << std::endl;
	}

	return 0;
}
