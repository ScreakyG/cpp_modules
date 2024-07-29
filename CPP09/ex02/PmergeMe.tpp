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
