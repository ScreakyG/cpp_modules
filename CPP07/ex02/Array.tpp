#include "Array.hpp"

template <typename T>
Array<T>::Array(void): _content(NULL), _size(0)
{
	std::cout << "Array default constructor called" << std::endl;
};

template <typename T>
Array<T>::Array(unsigned int size): _content(new T[size]()), _size(size) // Unsigned int constructor
{
	std::cout << "Array with size constructor called" << std::endl;
};

template <typename T>
Array<T>::Array(const Array<T> &src): _content(new T[src._size]()), _size(src._size) // Copy constructor
{
	std::cout << "Array copy constructor called" << std::endl;
	*this = src;
};

template <typename T>
Array<T>::~Array<T>(void) // Destructor
{
	std::cout << "Array destructor called" << std::endl;
	if (_content)
		delete[] _content;
};

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &rhs)
{
	std::cout << "Array assignement operator called" << std::endl;
	if (this != &rhs)
	{
		if (this->_size != rhs._size)
		{
			delete[] this->_content;
			this->_size = rhs._size;
			this->_content = new T[this->_size]();
		}
		for (unsigned int idx = 0; idx < this->_size; idx++)
			this->_content[idx] = rhs._content[idx];
	}
	return (*this);
};

template <typename T>
T& Array<T>::operator[](unsigned int idx)
{
	if (idx >= this->_size)
		throw Array::InvalidIndex();
	return (this->_content[idx]);
};

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (this->_size);
}

template <typename T>
std::ostream& operator<<(std::ostream &os, Array<T> &ref)
{
	for(unsigned int idx = 0; idx < ref.size(); idx++)
		os << "[" << ref[idx] << "]";
	return (os);
};