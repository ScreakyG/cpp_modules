#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <exception>

class valueNotFound : public std::exception
{
	public:
		const char *what() const throw();
};

template<typename T>
typename T::const_iterator	easyfind(const T &intContainer, const int &toFind);

#include "easyfind.tpp"

#endif
