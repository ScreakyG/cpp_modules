#include "PmergeMe.hpp"

static void parseArgs(char **argv, std::vector<int> &vector)
{
	char				*endptr;
	long				nb;

	for (int i = 1; argv[i]; i++)
	{
		nb = std::strtol(argv[i], &endptr, 10);
		if (*endptr != '\0')
			throw std::runtime_error("Unvalid number detected");
		if (nb < 0 || nb > std::numeric_limits<int>::max())
			throw std::runtime_error("A number is out of INTS limits");
		vector.push_back(static_cast<int>(nb));
		// Ajouter le deuxieme container.
	}
}

void PmergeMe::mergeInsert(char **argv)
{
	std::vector<int>	vectorNumbers;

	// for (int i = 0; argv[i]; i++)
	// 	std::cout << "Argvs Array = " << argv[i] << std::endl;

	parseArgs(argv, vectorNumbers);

	for (unsigned int i = 0; i < vectorNumbers.size(); i++)
		std::cout << vectorNumbers[i] << std::endl;
}
