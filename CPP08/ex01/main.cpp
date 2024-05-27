#include "Span.hpp"
#include <iostream>

int	main(void)
{
	Span	sp = Span(3);
	try
	{
		sp.addNumber(100);
		sp.addNumber(1);
		sp.addNumber(1000);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp.printSpan();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
