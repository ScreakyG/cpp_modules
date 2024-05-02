#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	std::string test = "42.42";
	ScalarConverter::scalarFromFloat(test);
	// if (argc == 2)
	// 	ScalarConverter::convert(argv[1]);
	// else
	// 	std::cout << "Please only use 1 value as argument" << std::endl;
}
