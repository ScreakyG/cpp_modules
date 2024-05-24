#include <iostream>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> array(10);
	std::vector<int>::const_iterator it;

	try
	{
		array.push_back(42);
		array.push_back(32);
		array.push_back(100);
		it = easyfind(array, 100);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
