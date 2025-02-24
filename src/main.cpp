#include<iostream>
#include<filesystem>
#include<fstream>
#include<string>

bool is_executable(const std::filesystem::path& path)
{
	if(std::filesystem::exists(path)){
		std::cout << "exists" << std::endl;
		const auto& permissions = std::filesystem::status(path).permissions();
		return ((permissions & std::filesystem::perms::owner_exec) != std::filesystem::perms::none ||
			(permissions & std::filesystem::perms::group_exec) != std::filesystem::perms::none ||
			(permissions & std::filesystem::perms::others_exec) != std::filesystem::perms::none);
	}
	return false;
}

int main(int argc, char* argv[]){

	if(argc >= 2 && is_executable(argv[1])){
		std::cout << "VALID EXECUTABLE" << std::endl;
	}
	else{
		std::cout << argv[1] << std::endl;
		std::cout << "INVALID EXECUTABLE" << std::endl;
	}


	return 0;
}
