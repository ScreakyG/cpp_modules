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
			(it + (j + 1))->first = (it + j)->first;
			j--;
		}
		(it + (j + 1))->second = key.second;
		(it + (j + 1))->first = key.first;
	}
}

static std::vector<int> createJacobstahlSequence(std::vector<int> &pendChain)
{
	std::vector<int>				jacobSequence;
	unsigned int					jacobIndex = 3;
	unsigned int					j0 = 1;

	while (jacobIndex <= pendChain.size())
	{
		jacobSequence.push_back(jacobIndex);
		int	nextIndex = jacobIndex + 2 * j0;
		j0 = jacobIndex;
		jacobIndex = nextIndex;
	}
	printArray(jacobSequence, CYAN "Jacob index sequence : " RESET);
	return (jacobSequence);
}

static std::vector<int> createInsertSequence(std::vector<int> &pendChain)
{
	int	pendSize = pendChain.size();
	std::vector<int> indexSequence;

	indexSequence.push_back(1);
	if (pendSize == 1)
		return (indexSequence);

	std::vector<int> jacobstahlSequence = createJacobstahlSequence(pendChain);

	bool	 wasJacobNumber = false;
	int		i = 1;

	while (i <= pendSize)
	{
		if (jacobstahlSequence.size() != 0 && wasJacobNumber == false)
		{
			indexSequence.push_back(jacobstahlSequence[0]);
			jacobstahlSequence.erase(jacobstahlSequence.begin());
			wasJacobNumber = true;
			continue ;
		}
		std::vector<int>::iterator it = indexSequence.begin();
		for ( ;it < indexSequence.end(); it++)
		{
			if (i == *it)
				i++;
		}
		indexSequence.push_back(i);
		wasJacobNumber = false;
		i++;
	}
	return (indexSequence);
}

static void createFinalArray(std::vector<std::pair<int, int> > &array, int &straggler)
{
	std::vector<std::pair<int, int> >::iterator it;
	std::vector<int> mainChain;
	std::vector<int> pendChain;

	for (it = array.begin(); it != array.end(); it++)
	{
		mainChain.push_back(it->second);
		pendChain.push_back(it->first);
	}

	(void)straggler;
	printArray(mainChain, GREEN "Main chain : " RESET);
	printArray(pendChain, YELLOW "Pend chain : " RESET);

	//mainChain.insert(mainChain.begin(), pendChain[0]); // Insert the first element in MainChain since a1 is smaller than b1.

	std::vector<int> indexSequence = createInsertSequence(pendChain);

	printArray(indexSequence, CYAN "Index sequence : " RESET);
	for (unsigned int i = 0; i < indexSequence.size(); i++)
	{
		unsigned int indexToInsert = indexSequence[i];
		unsigned int valueToInsert = pendChain[indexToInsert - 1]; // Because index 1 means case[0].
		std::cout << "Index to insert = " << indexToInsert << " Value to insert = " << valueToInsert << std::endl;
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

	// Check if vector is already sorted.

	vectorPairs = makePairs(array); // Create pairs form original array's elements.
	printPairs(vectorPairs, "Pairing elements : ");

	sortPairsElements(vectorPairs); // Sort elements in the pairs P(a1, b1), where b1 > a1.
	printPairs(vectorPairs, "Sorting inside Pairs : ");

	sortPairsBigValue(vectorPairs); // Sort pairs by compare their b values in ascending order.
	printPairs(vectorPairs, "After sorting Pairs : ");

	createFinalArray(vectorPairs, straggler);
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
