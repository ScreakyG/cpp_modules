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

template <typename T>
static void printPairs(T &array)
{
	typename T::iterator it;

	std::cout << PURPLE "Pairing elements : ";
	for (it = array.begin(); it != array.end(); it++)
	{
		std::cout << "<";
		std::cout << it->first;
		std::cout << ",";
		std::cout << it->second;
		std::cout << ">";
		std::cout << " ";
	}
	std::cout << RESET;
	std::cout << std::endl;
}

