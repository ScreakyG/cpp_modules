#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <limits.h>

Span::Span(void): _maxSize(0), _currentSize(0), _array(NULL)
{
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N): _maxSize(N), _currentSize(0)
{
	std::cout << "Span size constructor called" << std::endl;
	_array = new int[_maxSize]();
}

Span::Span(const Span &rhs): _maxSize(rhs._maxSize), _currentSize(rhs._currentSize)
{
	std::cout << "Span copy constructor called" << std::endl;
	*this = rhs;
}

Span& Span::operator=(const Span &rhs)
{
	std::cout << "Span assignement operator called" << std::endl;
	(void)rhs;
	return (*this);
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
	delete[] _array;
}

void Span::addNumber(int nb)
{
	if (_currentSize >= _maxSize)
		throw Span::SpanIsFull();
	_array[_currentSize] = nb;
	_currentSize++;
	std::cout << "Added number " << nb << " to span" << std::endl;
}

unsigned int Span::shortestSpan()
{
	long	lowestDif = INT_MAX;

	if (_currentSize <= 1)
		throw Span::NotEnoughNumbers();
	std::sort(_array, _array+_currentSize);
	for (unsigned int idx = 0; idx < _currentSize - 1; idx++)
	{
		long	distance = static_cast<long>(_array[idx + 1]) - static_cast<long>(_array[idx]);
		if (distance < lowestDif)
			lowestDif = static_cast<long>(_array[idx + 1]) - static_cast<long>(_array[idx]);
	}
	return (lowestDif);
}

unsigned int Span::longestSpan()
{
	if (_currentSize <= 1)
		throw Span::NotEnoughNumbers();
	std::sort(_array, _array + _currentSize);
	return (static_cast<long>(_array[_currentSize - 1] - static_cast<long>(_array[0])));
}

void Span::printSpan()
{
	for (unsigned int idx = 0; idx < _maxSize; idx++)
		std::cout << "[" << _array[idx] << "]";
	std::cout << "\n";
}

const char* Span::SpanIsFull::what() const throw()
{
	return ("Span is full");
}

const char* Span::NotEnoughNumbers::what() const throw()
{
	return ("Couldn't calculate distance because there is not enough numbers");
}

