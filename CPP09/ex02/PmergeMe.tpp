#include "PmergeMe.hpp"

template <typename T>
static void parseArgs(char **argv, T& container)
{
	char				*endptr;
	long				nb;

	if (argv == NULL || *argv == NULL)
		throw std::runtime_error("Parsing arguments failed");

	for (int i = 1; argv[i]; i++)
	{
		nb = std::strtol(argv[i], &endptr, 10);
		if (*endptr != '\0')
			throw std::runtime_error("Unvalid number detected");
		if (nb < 0 || nb > std::numeric_limits<int>::max())
			throw std::runtime_error("Out of limits/negative number detected");
		container.push_back(static_cast<int>(nb));
	}
}

template <typename T>
static void printArray(T& container, const std::string &msg)
{
	typename T::iterator	it;
	unsigned int			count = 0;
	std::cout << msg;
	for (it = container.begin(); it != container.end(); it++)
	{
		if (count >=5)
		{
			std::cout << "[...]";
			break ;
		}
		std::cout << *it << " ";
		count++;
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

