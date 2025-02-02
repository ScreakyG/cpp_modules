#pragma once

#include <exception>
#include <vector>

#define RESET	"\e[0m"
#define RED	"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"

class Span
{
	public:
		Span(void); //Default constructor.
		Span(unsigned int N);
		Span(const Span &src); // Copy constructor.
		~Span(); // Destructor.

		Span& operator=(const Span &rhs); // Assignement operator.

		void 			addNumber(int nb);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

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
		std::vector<int>	_array;
		unsigned int		_maxSize;
};
