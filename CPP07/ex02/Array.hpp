#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	public:
		Array(void); // Default constructor.
		Array(unsigned int size); // Size constructor.
		Array(const Array<T> &src); // Copy constructor.
		~Array(void); // Destructor.

		Array& operator=(const Array<T> &rhs); // Assignement operator.
		T& operator[](unsigned int idx);

		unsigned int	size(void) const;

		class InvalidIndex : public std::exception
		{
			public:
				const char *what() const throw() {return "Invalid index, out of bounds";};
		};

	private:
		T*				_content;
		unsigned int	_size;
};

template <typename T>
std::ostream& operator<<(std::ostream &os, Array<T> &ref);

#include "Array.tpp"

#endif
