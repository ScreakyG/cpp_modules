#include "MutantStack.hpp"

template<typename T, typename C>
MutantStack<T, C>::MutantStack(void): std::stack<T, C>()
{
	std::cout << "MutantStack default constructor called" << std::endl;
}

template<typename T, typename C>
MutantStack<T, C>::MutantStack(const MutantStack<T, C> &src): std::stack<T, C>(src)
{
	std::cout << "MutantStack copy constructor called" << std::endl;
	// *this = src;
}

template<typename T, typename C>
MutantStack<T, C>::~MutantStack(void)
{
	std::cout << "MutantStack destructor called" << std::endl;
}

template<typename T, typename C>
MutantStack<T, C>& MutantStack<T, C>::operator=(const MutantStack<T, C> &rhs)
{
	if (this != &rhs)
	{
		this->c = rhs.c;
		std::cout << "Successfully assignement operator called" << std::endl;
	}
	return (*this);
}
