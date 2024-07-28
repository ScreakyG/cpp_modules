#include "PmergeMe.hpp"

static std::list<std::pair<int, int> > makePairsList(std::list<int> &array)
{
	std::list<std::pair<int, int> >		listPairs;
	std::pair<int, int>					pairedElements;

	for (std::list<int>::iterator it = array.begin(); it != array.end(); it++)
	{
		std::list<int>::iterator next_it = it;
		++next_it;
		if (next_it != array.end())
		{
			pairedElements = std::make_pair(*it, *next_it);
			listPairs.push_back(pairedElements);
		}
		it = next_it;
	}
	return (listPairs);
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

// static std::vector<int> createJacobstahlSequence(std::vector<int> &pendChain)
// {
// 	std::vector<int>				jacobSequence;
// 	unsigned int					jacobIndex = 3;
// 	unsigned int					j0 = 1;

// 	while (jacobIndex <= pendChain.size())
// 	{
// 		jacobSequence.push_back(jacobIndex);
// 		int	nextIndex = jacobIndex + 2 * j0;
// 		j0 = jacobIndex;
// 		jacobIndex = nextIndex;
// 	}
// 	return (jacobSequence);
// }

static int jacobsthal(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

static std::vector<int> createJacobsthalsSequence_COPY(std::vector<int> &pendChain, std::vector<int> &mainChain, std::vector<int> &jacobsthalSequence)
{
	unsigned long				jacob = 0;

	for (std::size_t i = 2; i < pendChain.size() + mainChain.size(); i++)
	{
		jacob = jacobsthal(i);
		if (jacob > pendChain.size())
		{
			jacobsthalSequence.push_back(jacob);
			break ;
		}
		jacobsthalSequence.push_back(jacob);
	}
	return (jacobsthalSequence);
}

static std::vector<unsigned long> createJacobIndexedSequence(std::vector<int> &jacobSequence, int size)
{
	std::vector<unsigned long>	jacobsthalIndexed;
	int							jacob = 0;
	for (std::size_t i = 0; i < jacobSequence.size(); i++)
	{
		jacob = jacobSequence[i];
		if (jacob <= size)
			jacobsthalIndexed.push_back(jacob);
		while (jacob > 0 && jacobSequence[i] != 1 && std::find(jacobsthalIndexed.begin(), jacobsthalIndexed.end(), --jacob) == jacobsthalIndexed.end())
		{
			if (jacob > size)
				continue ;
			jacobsthalIndexed.push_back(jacob);
		}
	}
	return (jacobsthalIndexed);
}

static std::vector<unsigned long> createInsertSequence(std::vector<int> &pendChain, std::vector<int> &mainChain, std::vector<int> &jacobsthalSequence)
{
	std::vector<unsigned long>	jacobsthalIndexed;

	createJacobsthalsSequence_COPY(pendChain, mainChain, jacobsthalSequence);
	printArray(jacobsthalSequence, RED "Jacob sequence : " RESET);

	jacobsthalIndexed = createJacobIndexedSequence(jacobsthalSequence, pendChain.size());
	printArray(jacobsthalIndexed, RED "Jacob sequence indexed : " RESET);

	return (jacobsthalIndexed);
}

static int getBatchNumber(std::vector<int> &jacobSequence, int index)
{

	for (unsigned int i = 0; i < jacobSequence.size(); i++)
	{
		if (jacobSequence[i] >= index && jacobSequence[i - 1] && jacobSequence[i - 1] < index)
			return (i + 1);
	}
	return (-1);
}

static void insertPendIntoMain(std::vector<int> &mainChain, std::vector<int> &pendChain, std::vector<int> &jacobSequence, std::vector<unsigned long> &indexSequence)
{
	size_t	lastSize = 0;
	for (unsigned int i = 0; i < indexSequence.size(); i++)
	{
		// Chercher a quel batch appartiennent les nombres en fonction des index de jacobsthal.
		lastSize = pow(2, getBatchNumber(jacobSequence, indexSequence[i])) - 1;
		if (lastSize > mainChain.size())
			lastSize = mainChain.size();
		mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.begin() + lastSize, pendChain[indexSequence[i] - 1]), pendChain[indexSequence[i] - 1]);
	}
}

static std::vector<int> createFinalArray(std::vector<std::pair<int, int> > &array, int &straggler)
{
	std::vector<std::pair<int, int> >::iterator it;
	std::vector<int> mainChain;
	std::vector<int> pendChain;

	for (it = array.begin(); it != array.end(); it++) // Push bigger value of each pairs to mainChain resulting in a sorted array, and smallers to pend.
	{
		mainChain.push_back(it->second);
		pendChain.push_back(it->first);
	}
	(void)straggler;
	printArray(mainChain, GREEN "Main chain : " RESET);
	printArray(pendChain, YELLOW "Pend chain : " RESET);

	if (pendChain.size() > 1)
	{
		std::vector<int>		   jacobsthalSequence;
		std::vector<unsigned long> indexSequence = createInsertSequence(pendChain, mainChain, jacobsthalSequence); // Get the index sorting sequence.

		mainChain.insert(mainChain.begin(), pendChain[0]); // Insert the first element in MainChain since a1 is smaller than b1.
		indexSequence.erase(indexSequence.begin()); // Remove the first index since we pushed it.
		insertPendIntoMain(mainChain, pendChain, jacobsthalSequence, indexSequence);
	}
	else if (pendChain.size() == 1) // Will also protect if the OG array is only 1 number.
		mainChain.insert(mainChain.begin(), pendChain[0]); // No need to get inserting sequence if only one element to insert.
	if (straggler != -1)
		mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), straggler), straggler);
	return (mainChain);
}

static void mergeVector(std::vector<std::pair<int, int> > &left, std::vector<std::pair<int, int> > &right, std::vector<std::pair<int, int> > &array)
{
	unsigned int	i = 0;
	unsigned int	j = 0;
	unsigned int	k = 0;

	while (i < left.size() && j < right.size())
	{
		if (left[i].second <= right[j].second)
		{
			array[k].first = left[i].first;
			array[k].second = left[i].second;
			i++;
		}
		else
		{
			array[k].first = right[j].first;
			array[k].second = right[j].second;
			j++;
		}
		k++;
	}
	for (; i < left.size(); i++)
	{
		array[k].first = left[i].first;
		array[k].second = left[i].second;
		k++;
	}
	for (; j < right.size(); j++)
	{
		array[k].first = right[j].first;
		array[k].second = right[j].second;
		k++;
	}
}

static void mergeSortVector(std::vector<std::pair<int, int> > &array)
{
	if (array.size() < 2)
		return ;

	unsigned int						mid = array.size() / 2;
	std::vector<std::pair<int, int> >	left;
	std::vector<std::pair<int, int> >	right;

	for (unsigned int i = 0; i < mid; i++)
		left.push_back(array[i]);
	for (unsigned int i = mid; i < array.size(); i++)
		right.push_back(array[i]);

	mergeSortVector(left);
	mergeSortVector(right);
	mergeVector(left, right, array);
}

static std::vector<int> sortVector(std::vector<int> &array)
{
	int									straggler = -1;
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

	// Sort pairs by compare their b values in ascending order.
	mergeSortVector(vectorPairs);
	printPairs(vectorPairs, "After sorting Pairs : ");

	return (createFinalArray(vectorPairs, straggler));
}

std::list<int> sortList(std::list<int> &array)
{
	int									straggler = -1;
	std::list<std::pair<int, int> >		listPairs;

	if (array.size() % 2 != 0)
	{
		straggler = array.back();
		array.pop_back();
	}
	(void)straggler;
	// Check if list is already sorted.

	listPairs = makePairsList(array); // Create pairs form original array's elements.
	printPairs(listPairs, "Pairing elements : ");

	//sortPairsElements(vectorPairs); // Sort elements in the pairs P(a1, b1), where b1 > a1.
	//printPairs(vectorPairs, "Sorting inside Pairs : ");

	// Sort pairs by compare their b values in ascending order.
	//mergeSortVector(vectorPairs);
	//printPairs(vectorPairs, "After sorting Pairs : ");

	//return (createFinalArray(vectorPairs, straggler));
	return (array);
}

static void isSorted(std::vector<int> &array)
{
	for (size_t i = 1; i < array.size(); i++)
	{
		if (array[i] < array[i - 1])
		{
			std::cout << RED << "Array is not sorted" << RESET << std::endl;
			return ;
		}
	}
	std::cout << GREEN << "Array is sorted" << RESET << std::endl;
}

void PmergeMe::mergeInsert(char **argv)
{
	timeval	start;
	timeval	end;
	double	executionTime;

	std::vector<int>	vectorNumbers;
	std::vector<int>	sortedVector;

	gettimeofday(&start, NULL);
	parseArgs<std::vector<int> >(argv, vectorNumbers);

	printArray<std::vector<int> >(vectorNumbers, "Before : ");

	sortedVector = sortVector(vectorNumbers);
	gettimeofday(&end, NULL);
	printArray<std::vector<int> >(sortedVector, "After : ");

	isSorted (sortedVector);

	executionTime = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
	std::cout << "Time to process a range of " << vectorNumbers.size() << " elements with std::vector : " << std::fixed << std::setprecision(6) << executionTime << " us" << std::endl;


	std::cout << BLUE << "TESTING WITH STD::LIST" << RESET << std::endl;

	std::list<int>		listNumbers;
	std::list<int>		sortedList;

	parseArgs(argv, listNumbers);
	printArray<std::list<int> >(listNumbers, "Before : ");

	sortedList = sortList(listNumbers);
}
