#include "pch.h"

int main() {

	char buffer[]{ "Hello World!" };
	std::cout.write(buffer, 10);
	std::cout << std::endl;
	std::cout.write("Hello world!", 10);
	std::cout << std::endl;

	int number{ 13432 };
	std::cout << number << "In hex is: " << std::oct << number << std::endl;


	return 0;

}

