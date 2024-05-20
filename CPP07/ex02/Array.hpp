#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	public:
		Array<T>(void): _content(NULL), _size(0) // Default constructor
		{
			std::cout << "Array default constructor called" << std::endl;
		};

		Array<T>(unsigned int size): _content(new T[size]), _size(size) // Unsigned int constructor
		{
			std::cout << "Array with size constructor called" << std::endl;
		};

		Array<T>(const Array<T> &src): _content(new T[src._size]), _size(src._size) // Copy constructor
		{
			std::cout << "Array copy constructor called" << std::endl;
			*this = src;
		}

		~Array<T>(void) // Destructor
		{
			std::cout << "Array destructor called" << std::endl;
			if (_content)
				delete[] _content;
		};

		Array<T>& operator =(const Array<T> &rhs)
		{
			std::cout << "Array assignement operator called" << std::endl;
			if (this != &rhs)
			{
				if (this->_size != rhs._size)
				{
					delete[] this->_content;
					this->_size = rhs._size;
					this->_content = new T[this->_size];
				}
				for (unsigned int idx = 0; idx < this->_size; idx++)
					this->_content[idx] = rhs._content[idx];
			}
			return (*this);
		};

		T& operator[](unsigned int idx)
		{
			if (idx >= this->_size)
				throw Array::InvalidIndex();
			return (this->_content[idx]);
		};
		unsigned int	size(void) const {return (this->_size);};

		class InvalidIndex : public std::exception
		{
			public:
				const char *what() const throw() {return "Invalid index, out of bounds";};
		};

	private:
		T*				_content;
		unsigned int	_size;
};

#endif
