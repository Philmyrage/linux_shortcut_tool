#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

const bool is_executable(const std::filesystem::path &path)
{
	if (std::filesystem::exists(path) && std::filesystem::is_regular_file(path))
	{
		std::cout << "exists" << std::endl;
		const auto &permissions = std::filesystem::status(path).permissions();
		return (permissions & std::filesystem::perms::owner_exec) != std::filesystem::perms::none ||
			   (permissions & std::filesystem::perms::group_exec) != std::filesystem::perms::none ||
			   (permissions & std::filesystem::perms::others_exec) != std::filesystem::perms::none;
	}
	return false;
}

const void generate_desktop_file(const std::filesystem::path &exec_path)
{
	
}

int main(int argc, char *argv[])
{

	if (argc >= 2 && is_executable(argv[1]))
	{
		std::cout << "VALID EXECUTABLE" << std::endl;
	}
	else
	{
		std::cout << argv[1] << std::endl;
		std::cout << "INVALID EXECUTABLE" << std::endl;
	}

	return 0;
}
