#include "Span.hpp"
#include <iostream>

void addRandomRange(Span &obj, unsigned int size)
{
	std::vector<int>	temp(size);

	for (unsigned int idx = 0; idx < size; idx++)
		temp[idx] = idx;
	obj.addRange(temp.begin(), temp.end());
}

int	main(void)
{
	Span sp = Span(6);
	try
	{
		sp.addNumber(100);
		sp.addNumber(200);
		addRandomRange(sp, 5);
		sp.printSpan();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
