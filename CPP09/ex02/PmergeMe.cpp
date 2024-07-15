#include "PmergeMe.hpp"

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

static void sortPairsBigValue(std::vector<std::pair<int, int> > &array)
{
	std::vector<std::pair<int, int> >::iterator	it = array.begin();

	for (unsigned int step = 1; step < array.size(); step++)
	{
		std::pair<int, int>	key(*(it + step));
		int		j = step - 1;

		while (key.second < (it + j)->second && j >= 0)
		{
			(it + (j + 1))->second = (it + j)->second;
			j--;
		}
		(it + (j + 1))->second = key.second;
	}
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

	// Check if vector is already sorted.

	vectorPairs = makePairs(array); // Create pairs form original array's elements.
	printPairs(vectorPairs, "Pairing elements : ");

	sortPairsElements(vectorPairs); // Sort elements in the pairs P(a1, b1), where b1 > a1.
	printPairs(vectorPairs, "Sorting inside Pairs : ");

	// Sort pairs by compare their b values;

	sortPairsBigValue(vectorPairs);
	printPairs(vectorPairs, "After sorting Pairs : ");
}

void PmergeMe::mergeInsert(char **argv)
{
	std::vector<int>	vectorNumbers;

	// for (int i = 0; argv[i]; i++)
	// 	std::cout << "Argvs Array = " << argv[i] << std::endl;

	parseArgs(argv, vectorNumbers);
	printArray<std::vector<int> >(vectorNumbers, "Before : ");

	sortVector(vectorNumbers);
	// printArray<std::vector<int> >(vectorNumbers, "After : ");
}
