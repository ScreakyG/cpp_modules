#pragma once

#include <stack>
#include <iostream>
#include <deque>

// template <typename T, typename C = std::deque<T> >
// class MutantStack : public std::stack<T, C>

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
	public:
		MutantStack(); // Default constructor
		MutantStack(const MutantStack<T, C> &src); // Copy constructor
		~MutantStack(); // Destructor
		MutantStack<T, C>& operator=(const MutantStack<T, C> &rhs); // Assignement Operator

		typedef typename std::stack<T, C>::container_type::iterator iterator;
		typedef typename std::stack<T, C>::container_type::const_iterator const_iterator;

        typedef typename std::stack<T, C>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T, C>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator	begin() {return this->c.begin();};
		iterator	end() {return this->c.end();};
        reverse_iterator rbegin() {return this->c.rbegin();};
        reverse_iterator rend() {return this->c.rend();};

        // Ces methodes n'existaient pas pour 98 mais les types iterators constant existaient
		const_iterator cbegin() const {return this->c.begin();};
		const_iterator cend() const {return this->c.end();};
        const_reverse_iterator crbegin() const {return this->c.rbegin();};
        const_reverse_iterator crend() const {return this->c.rend();};

};

#include "MutantStack.tpp"
