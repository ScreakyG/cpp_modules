#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <exception>

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

class valueNotFound : public std::exception
{
	public:
		const char *what() const throw();
};

template<typename T>
typename T::const_iterator	easyfind(const T &intContainer, const int &toFind);

#include "easyfind.tpp"

#endif
