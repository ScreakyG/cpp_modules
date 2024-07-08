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
			std::cout << "Error : " << e.what() << std::endl;
		}
	}
	else
		std::cout << "Usage : './PmergeMe 3 8 9 1 [...]" << std::endl;
}
