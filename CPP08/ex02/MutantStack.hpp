#pragma once

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(); // Default constructor
		MutantStack(const MutantStack<T> &src); // Copy constructor
		~MutantStack(); // Destructor
		MutantStack<T>& operator=(const MutantStack<T> &rhs); // Assignement Operator

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator	begin() {return this->c.begin();};
		iterator	end() {return this->c.end();};

		const_iterator begin() const {return this->c.cbegin();};
		const_iterator end() const {return this->c.cend();};

};

#include "MutantStack.tpp"
