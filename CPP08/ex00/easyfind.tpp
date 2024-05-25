#include "easyfind.hpp"


const char* valueNotFound::what() const throw()
{
	return (RED "Value not found in container" RESET);
}

template<typename T>
typename T::const_iterator	easyfind(const T &intContainer, const int &toFind)
{
		typename T::const_iterator it;

		it = std::find(intContainer.begin(), intContainer.end(), toFind);
		if (it == intContainer.end())
			throw valueNotFound();
		std::cout << GREEN "Found value " << toFind << RESET << std::endl;
		return (it);
}
