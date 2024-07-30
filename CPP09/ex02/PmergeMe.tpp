#include "PmergeMe.hpp"

int jacobsthal(int n);
std::vector<unsigned long> createJacobIndexedSequence(std::vector<int> &jacobSequence, int size);
int getBatchNumber(std::vector<int> &jacobSequence, int index);

template <typename T>
static void isSorted_Template(T &array)
{
	if (PRINT_DETAILS == false)
		return ;
	typename T::iterator	prevElem;
	typename T::iterator	currElem = array.begin();

	currElem++;
	for (; currElem != array.end(); currElem++)
	{
		prevElem = currElem;
		prevElem--;
		if (*currElem < *prevElem)
		{
			std::cout << RED << "Array is not sorted" << RESET << std::endl;
			return ;
		}
	}
	std::cout << GREEN << "Array is sorted" << RESET << std::endl;
}

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
static void printArray(T& container, const std::string &msg, bool bypass)
{
	if (PRINT_DETAILS == false && bypass == false)
		return ;
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
}

template <typename T>
static void printPairs(T &array, std::string msg)
{
	if (PRINT_DETAILS == false)
		return ;

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

template <typename T>
static void mergeTemplate(T &left, T &right, T &array)
{
	typename T::iterator	it_left = left.begin();
	typename T::iterator	it_right = right.begin();
	typename T::iterator	it_og = array.begin();

	while (it_left != left.end() && it_right != right.end())
	{
		if (it_left->second <= it_right->second)
		{
			it_og->first = it_left->first;
			it_og->second = it_left->second;
			it_left++;
		}
		else
		{
			it_og->first = it_right->first;
			it_og->second = it_right->second;
			it_right++;
		}
		it_og++;
	}
	for (; it_left != left.end(); it_left++)
	{
		it_og->first = it_left->first;
		it_og->second = it_left->second;
		it_og++;
	}
	for (; it_right != right.end(); it_right++)
	{
		it_og->first = it_right->first;
		it_og->second = it_right->second;
		it_og++;
	}
}

template <typename T>
static void mergeSortTemplate(T &array)
{
	if (array.size() < 2)
		return ;

	unsigned int			mid = array.size() / 2;
	T	left;
	T	right;

	typename T::iterator		it;
	typename T::iterator		it_mid = array.begin();

	std::advance(it_mid, mid);

	for (it = array.begin(); it != it_mid; it++)
		left.push_back(*it);
	for (it = it_mid; it != array.end(); it++)
		right.push_back(*it);

	mergeSortTemplate(left);
	mergeSortTemplate(right);
	mergeTemplate(left, right, array);
}

template <typename T>
static std::vector<int> createJacobsthalsSequence_Template(T&pendChain, T &mainChain, std::vector<int> &jacobsthalSequence)
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

template <typename T>
static std::vector<unsigned long> createInsertSequence_Template(T &pendChain, T &mainChain, std::vector<int> &jacobsthalSequence)
{
	std::vector<unsigned long> jacobsthalIndexed;

	createJacobsthalsSequence_Template(pendChain, mainChain, jacobsthalSequence);
	printArray(jacobsthalSequence, RED "Jacob sequence : " RESET, false);

	jacobsthalIndexed = createJacobIndexedSequence(jacobsthalSequence, pendChain.size());
	printArray(jacobsthalIndexed, RED "Jacob sequence indexed : " RESET, false);

	return (jacobsthalIndexed);
}

template <typename T>
static void   insertPendIntoMain_Template(T &mainChain, T &pendChain, std::vector<int> &jacobSequence, std::vector<unsigned long> &indexSequence)
{
	size_t	lastSize = 0;
	for (unsigned int i = 0; i < indexSequence.size(); i++)
	{
		typename T::iterator element = pendChain.begin();
		typename T::iterator range = mainChain.begin();

		// Chercher a quel batch appartiennent les nombres en fonction des index de jacobsthal.
		lastSize = pow(2, getBatchNumber(jacobSequence, indexSequence[i])) - 1;
		if (lastSize > mainChain.size())
			lastSize = mainChain.size();

		unsigned long index = indexSequence[i] - 1;
		std::advance(element, index);
		std::advance(range, lastSize);
		mainChain.insert(std::lower_bound(mainChain.begin(), range, *element), *element);
	}
}
