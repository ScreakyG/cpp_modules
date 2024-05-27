#pragma once

#include <exception>

class Span
{
	public:
		Span(void); //Default constructor.
		Span(unsigned int N);
		Span(const Span &src); // Copy constructor.
		~Span(); // Destructor.

		Span& operator=(const Span &rhs); // Assignement operator.

		void addNumber(int nb);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		void printSpan();

		class SpanIsFull : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class NotEnoughNumbers : public std::exception
		{
			public:
				const char* what() const throw();
		};
	private:
		unsigned int	_maxSize;
		unsigned int	_currentSize;
		int*			_array;
};
