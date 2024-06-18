#include "MutantStack.hpp"

#include <iostream>

template<typename T>
MutantStack<T>::MutantStack(void): std::stack<T>
{
	std::cout << "MutantStack default constructor called" << std::endl;
}
