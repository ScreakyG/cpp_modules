#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(void): std::stack<T>()
{
	std::cout << "MutantStack default constructor called" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &src)
{
	std::cout << "MutantStack copy constructor called" << std::endl;
	*this = src;
}

template<typename T>
MutantStack<T>::~MutantStack(void)
{
	std::cout << "MutantStack destructor called" << std::endl;
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &rhs)
{
	if (this != &rhs)
	{
		this->c = rhs.c;
		std::cout << "Successfully assignement operator called" << std::endl;
	}
	return (*this);
}
