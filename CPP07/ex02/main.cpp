#include "Array.hpp"

void	testsArrayChar(void)
{
	std::cout << "<-----ARRAY CHAR----->" << std::endl;

	Array<char> array_empty;

	Array<char> array(5);
	std::cout << "Array size = " << array.size() << std::endl;

	Array<char> array2 = array;
	std::cout << "Array2 size = " << array2.size() << std::endl;

	for (unsigned int idx = 0; idx < array.size(); idx++)
		array[idx] = 48 + idx;

	std::cout << "Array empty = " << array_empty << std::endl;
	std::cout << "Array = " << array << std::endl;
	std::cout << "Array2 = " << array2 << std::endl;

	try
	{
		array[-1] = 'S';
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "<-------------------->" << std::endl;
}

void	testsArrayInt(void)
{
	std::cout << "<-----ARRAY INT----->" << std::endl;

	Array<int> array_empty;

	Array<int> array(5);
	std::cout << "Array size = " << array.size() << std::endl;

	Array<int> array2 = array;
	std::cout << "Array2 size = " << array2.size() << std::endl;

	for (unsigned int idx = 0; idx < array.size(); idx++)
		array[idx] = idx;

	std::cout << "Array empty = " << array_empty << std::endl;
	std::cout << "Array = " << array << std::endl;
	std::cout << "Array2 = " << array2 << std::endl;

	try
	{
		array[-1] = 50;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "<-------------------->" << std::endl;
}

void	testsArrayDouble(void)
{
	std::cout << "<-----ARRAY DOUBLE----->" << std::endl;

	Array<double> array_empty;

	Array<double> array(5);
	std::cout << "Array size = " << array.size() << std::endl;

	Array<double> array2 = array;
	std::cout << "Array2 size = " << array2.size() << std::endl;

	for (unsigned int idx = 0; idx < array.size(); idx++)
		array[idx] = idx + 0.42;

	std::cout << "Array empty = " << array_empty << std::endl;
	std::cout << "Array = " << array << std::endl;
	std::cout << "Array2 = " << array2 << std::endl;

	try
	{
		array[-1] = 42.42;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "<-------------------->" << std::endl;
}

void	testsArrayStrings(void)
{
	std::cout << "<-----ARRAY STRINGS----->" << std::endl;

	Array<std::string> array_empty;

	Array<std::string> array(5);
	std::cout << "Array size = " << array.size() << std::endl;

	Array<std::string> array2 = array;
	std::cout << "Array2 size = " << array2.size() << std::endl;

	for (unsigned int idx = 0; idx < array.size(); idx++)
		array[idx] = "Bonjour";

	std::cout << "Array empty = " << array_empty << std::endl;
	std::cout << "Array = " << array << std::endl;
	std::cout << "Array2 = " << array2 << std::endl;

	try
	{
		array[-1] = "Error";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "<-------------------->" << std::endl;
}


int main(void)
{
	testsArrayChar();
	testsArrayInt();
	testsArrayDouble();
	testsArrayStrings();
}
