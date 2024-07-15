#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		try
		{
			PmergeMe::mergeInsert(argv);
		}
		catch(const std::exception &e)
		{
			std::cout << RED "Error : " << e.what() << RESET << std::endl;
		}
	}
	else
		std::cout << RED "Usage : './PmergeMe 3 8 9 1 [...]" RESET << std::endl;
}
