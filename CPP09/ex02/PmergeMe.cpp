#include "PmergeMe.hpp"

static void printPairsVector(std::vector<std::pair<int, int> > &array)
{
	std::vector<std::pair<int, int> >::iterator it;

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

static void parseArgs(char **argv, std::vector<int> &vector)
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
		vector.push_back(static_cast<int>(nb));
		// Ajouter le deuxieme container.
	}
}

static std::vector<std::pair<int, int> > makePairs(std::vector<int> &array)
{
	std::vector<std::pair<int, int> >	vectorPairs;
	std::pair<int, int>					pairedElements;

	for (unsigned int i = 0; i < array.size(); i += 2)
	{
		pairedElements = std::make_pair(array[i], array[i + 1]);
		vectorPairs.push_back(pairedElements);
	}
	return (vectorPairs);
}

static void sortVector(std::vector<int> &array)
{
	int									straggler;
	std::vector<std::pair<int, int> >	vectorPairs;

	if (array.size() % 2 != 0)
	{
		straggler = array.back();
		array.pop_back();
	}
	(void)straggler;

	vectorPairs = makePairs(array);
	printPairsVector(vectorPairs);
}

void PmergeMe::mergeInsert(char **argv)
{
	std::vector<int>	vectorNumbers;

	// for (int i = 0; argv[i]; i++)
	// 	std::cout << "Argvs Array = " << argv[i] << std::endl;

	parseArgs(argv, vectorNumbers);
	printArray<std::vector<int> >(vectorNumbers, "Before : ");

	sortVector(vectorNumbers);
	printArray<std::vector<int> >(vectorNumbers, "Before : ");
}
