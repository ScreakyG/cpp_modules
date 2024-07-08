#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>

class PmergeMe
{
	public:
		~PmergeMe() {};
		static void mergeInsert(char **argv);

	private:
		PmergeMe() {};
		PmergeMe(const PmergeMe &src) {(void)src;};
		PmergeMe& operator=(const PmergeMe &rhs){(void)rhs; return(*this);};
};
