#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(); // Default constructor

};

#include "MutantStack.tpp"
