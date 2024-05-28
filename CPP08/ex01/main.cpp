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
	Span sp = Span(10000);
	try
	{
		addRandomRange(sp, 10000);
		sp.printSpan();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
