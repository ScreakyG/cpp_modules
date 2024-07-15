#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <algorithm>

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

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

#include "PmergeMe.tpp"
