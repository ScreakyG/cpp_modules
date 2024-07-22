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
static void printPairs(T &array, std::string msg)
{
	typename T::iterator it;
	int					 i = 0;

	std::cout << PURPLE << msg;
	for (it = array.begin(); it != array.end(); it++)
	{

		if (i <= 5)
		{
			std::cout << "<";
			std::cout << it->first;
			std::cout << ",";
			std::cout << it->second;
			std::cout << ">";
			std::cout << " ";
		}
		else
		{
			std::cout << " [...]";
			break ;
		}
		i++;
	}
	std::cout << RESET;
	std::cout << std::endl;
}

template <typename T>
static void sortPairsElements(T &array)
{
	typename T::iterator 						it;
	int											temp;

	for (it = array.begin(); it != array.end(); it++)
	{
		if (it->first > it->second)
		{
			temp = it->second;
			it->second = it->first;
			it->first = temp;
		}
	}
}

