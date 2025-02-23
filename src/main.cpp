#include<iostream>
#include<filesystem>
#include<fstream>
#include<string>

int main(int argc, char* argv[]){
	std::cout << std::filesystem::current_path() << std::endl;
	std::cout << "Hello World" << std::endl;
	return 0;
}
