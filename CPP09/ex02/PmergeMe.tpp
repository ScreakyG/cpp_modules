#include "PmergeMe.hpp"

template <typename T>
static void printArray(T& container, const std::string &msg)
{
	std::cout << msg;
	for (unsigned int i = 0; i < container.size(); i++)
	{
		if (i >=5)
		{
			std::cout << "[...]";
			break ;
		}
		std::cout << container[i] << " ";
	}
	std::cout << "\n";
}

