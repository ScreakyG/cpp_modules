#include "Span.hpp"
#include <iostream>

int	main(void)
{
	Span	sp = Span(3);
	try
	{
		sp.addNumber(2147483647);
		sp.addNumber(-1);
		sp.addNumber(-100);
		std::cout << sp.shortestSpan() << std::endl;
		sp.printSpan();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
