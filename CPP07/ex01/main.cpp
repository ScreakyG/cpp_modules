#include <iostream>
#include "iter.hpp"
#include <cstdlib>
#include <string>

void	printStringLen(const std::string &str)
{
	std::cout << str + " = " << str.length() << std::endl;
}

void	capitalizeChar(char &c)
{
	c = std::toupper(c);
}

void	arraysIntsTests()
{
	std::cout << "<----TESTING INT ARRAYS---->" << std::endl;

	int	array[] = {1, 4, 2, 100 ,0};
	size_t array_len = sizeof(array) / sizeof(*array);
	iter(array, array_len, printValue<int>);
	iter(array, array_len, multiply2<int>);
	std::cout << "\n";
	iter(array, array_len, printValue<int>);

	std::cout << "\n" << "<-------------------------->" << std::endl;
}

void	arraysDoubleTests()
{
	std::cout << "<----TESTING DOUBLE ARRAYS---->" << std::endl;

	double array[] = {2.34, 3.56, 4.0009, 5.222222, 100.132};
	size_t array_len = sizeof(array) / sizeof(*array);
	iter(array, array_len, printValue<double>);
	iter(array, array_len, multiply2<double>);
	std::cout << "\n";
	iter(array, array_len, printValue<double>);

	std::cout << "\n" << "<----------------------------->" << std::endl;
}

void	arraysCharsTests()
{
	std::cout << "<----TESTING CHAR ARRAYS---->" << std::endl;

	char	array[] = {'S', 'a', 'l', 'u', 't'};
	size_t	array_len = sizeof(array) / sizeof(*array);
	iter(array, array_len, printValue<char>);
	iter(array, array_len, capitalizeChar);
	std::cout << "\n";
	iter(array, array_len, printValue<char>);

	std::cout << "\n" << "<----------------------------->" << std::endl;
}

void	arraysStringTests()
{
	std::cout << "<----TESTING STRING ARRAYS---->" << std::endl;

	std::string array[] = {"J'ai", "pas", "d'idee", "pour", "le", "moment"};
	size_t	array_len = sizeof(array) / sizeof(*array);
	iter(array, array_len, printValue<std::string>);
	std::cout << "\n";
	iter(array, array_len, printStringLen);

	std::cout << "<----------------------------->" << std::endl;
}

int main(void)
{
	arraysIntsTests();
	arraysDoubleTests();
	arraysCharsTests();
	arraysStringTests();
}
