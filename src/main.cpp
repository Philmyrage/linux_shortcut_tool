#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <map>

const std::filesystem::path LOCAL_SHORTCUT_PATH = "$HOME/.local/share/applications";
const std::filesystem::path GLOBAL_SHORTCUT_PATH = "/usr/share/applications";

// Used for development purposes only!
const std::filesystem::path TEST_PATH = "/mnt/Data/";

std::map<const std::string, std::string> options = {
	{"-c", ""},	  // Comment
	{"-img", ""}, // Path to Icon
	{"-te", ""},  // Terminal
	{"-typ", ""}, // Type
	{"-cat", ""}, // Categories
	{"-e", ""},	  // Exec
	{"-k", ""},	  // Keywords
	{"-n", ""}	  // name
};

const bool is_executable(const std::filesystem::path &path)
{
	if (std::filesystem::exists(path) && std::filesystem::is_regular_file(path))
	{
		const auto &permissions = std::filesystem::status(path).permissions();
		return (permissions & std::filesystem::perms::owner_exec) != std::filesystem::perms::none ||
			   (permissions & std::filesystem::perms::group_exec) != std::filesystem::perms::none ||
			   (permissions & std::filesystem::perms::others_exec) != std::filesystem::perms::none;
	}
	return false;
}

// parses the command and caches the data in the appropriate locations
void parse_command(char *argv[], const int &argc)
{
	// Need to parse the command and options validate it and cache it to be written to .desktop file.
	for (int i = 0; i < argc - 1; i++)
	{
		std::string token = std::string(argv[i]);
		if (options.contains(argv[i]))
		{
			if (token == "-n")
			{
				options.at("-n") = std::string(argv[i + 1]) + ".desktop";
			}
			else if (token == "-img")
			{
				// Only Support PNG, XPM, SVG
				// TODO: I'll need a lib for this I'll come back to after i implement the other stuff...
				//  check if i + 1 is a valid path...
				if (std::filesystem::exists(argv[i + 1]) && std::filesystem::is_regular_file(argv[i + 1]))
				{
					options.at("-img") = std::string(argv[i + 1]);
				}
			}
			else if (token == "-c")
			{
				// cache i + 1 as a string for the comment
				options.at("-c") = std::string(argv[i + 1]);
			}
			else if (token == "-te")
			{
				std::string t = std::string(argv[i + 1]);
				if (t == "true" || t == "false")
				{
					options.at("-c") = t;
				}
				else
				{
					std::cerr << "-te option only accepts true or false" << std::endl;
				}
			}
			else if (token == "-typ")
			{
				// TODO: Only allow correct types... Need to look at docs for .desktop files.
				options.at("-typ") = std::string(argv[i + 1]);
			}
			else if (token == "-cat")
			{
				// TODO: Only allow correct Categories... Need to look at docs for .desktop files.
				options.at("-cat") = std::string(argv[i + 1]);
			}
			else if (token == "-e")
			{
				if (is_executable(std::string(argv[i + 1])))
				{
					options.at("-e") = std::string(argv[i + 1]);
				}
			}
			else if (token == "-k")
			{
				options.at("-k") = std::string(argv[i + 1]);
			}
		}
		else if (token.starts_with('-'))
		{
			std::cerr << argv[i] << ": Invalid Option" << std::endl;
		}
	}
}

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

	parse_command(argv, argc);

	for (auto &o : options)
	{
		if (o.second != "")
		{
			std::cout << o.second << std::endl;
		}
	}

	return 0;
}
