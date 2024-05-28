#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <limits.h>

Span::Span(void): _array(),_maxSize(0)
{
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N): _array(), _maxSize(N)
{
	std::cout << "Span size constructor called" << std::endl;
}

Span::Span(const Span &rhs)
{
	std::cout << "Span copy constructor called" << std::endl;
	*this = rhs;
}

Span& Span::operator=(const Span &rhs)
{
	std::cout << "Span assignement operator called" << std::endl;
	if (this != &rhs)
	{
		this->_maxSize = rhs._maxSize;
		this->_array = rhs._array;
	}
	return (*this);
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	unsigned int	distance = std::distance(begin, end);

	if (distance > (this->_maxSize - this->_array.size()))
		throw Span::SpanIsFull();
	if (distance > 0)
		_array.insert(_array.end(), begin, end);
}

void Span::addNumber(int nb)
{
	if (_array.size() >= _maxSize)
		throw Span::SpanIsFull();
	_array.push_back(nb);
	//std::cout << "Added number " << nb << " to span" << std::endl;
}

unsigned int Span::shortestSpan()
{
	long	lowestDif = INT_MAX;
	std::vector<int>	temp(_array);

	if (_array.size() <= 1)
		throw Span::NotEnoughNumbers();
	std::sort(temp.begin(), temp.end());
	for (std::vector<int>::iterator it = temp.begin(); it != temp.end() - 1; it++)
	{
		long	distance = *(it + 1) - *it;
		if (distance < lowestDif)
			lowestDif = *(it + 1) - *it;
	}
	return (lowestDif);
}

unsigned int Span::longestSpan()
{
	std::vector<int>	temp(_array);

	if (_array.size() <= 1)
		throw Span::NotEnoughNumbers();
	std::sort(temp.begin(), temp.end());
	return (*(temp.end() - 1) - *(temp.begin()));
}

void Span::printSpan()
{
	std::cout << "<------SPAN INFOS------>" << std::endl;

	for (std::vector<int>::iterator it = _array.begin(); it != _array.end(); it++)
		std::cout << "[" << *it << "]";
	std::cout << "\n";
	std::cout << "Size = " << _array.size() << ", Capacity = " << _maxSize << std::endl;

	std::cout << "<---------------------->" << std::endl;
}

const char* Span::SpanIsFull::what() const throw()
{
	return ("Span is full");
}

const char* Span::NotEnoughNumbers::what() const throw()
{
	return ("Couldn't calculate distance because there is not enough numbers");
}

