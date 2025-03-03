#pragma once

#include <stack>
#include <iostream>

// template <typename T, typename C = std::deque<T> >
// class MutantStack : public std::stack<T, C>

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

        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator	begin() {return this->c.begin();};
		iterator	end() {return this->c.end();};
        reverse_iterator rbegin() {return this->c.rbegin();};
        reverse_iterator rend() {return this->c.rend();};

		const_iterator begin() const {return this->c.cbegin();};
		const_iterator end() const {return this->c.cend();};
        const_reverse_iterator cbegin() const {return this->c.crbegin();};
        const_reverse_iterator crend() const {return this->c.crend();};

};

#include "MutantStack.tpp"
