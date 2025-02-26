#include "Span.hpp"
#include <iostream>
#include <cstdlib>

void addRandomRange(Span &obj, unsigned int size)
{
	std::vector<int>	temp(size);

	for (unsigned int idx = 0; idx < size; idx++)
		temp[idx] = idx;
	obj.addRange(temp.begin(), temp.end());
}


// void addRandomRange2(Span &obj, unsigned int size)
// {
// 	std::vector<int>	temp(size);
//     int                 randomNbr;

//     srand(time(0));

// 	for (unsigned int idx = 0; idx < size; idx++)
//     {
//         randomNbr = rand() % 1001;
// 		temp[idx] = randomNbr;
//     }
// 	obj.addRange(temp.begin(), temp.end());
// }

void subjectTest()
{
    std::cout << "----------------------------SUBJECT TEST---------------------------------\n";

    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span = " << sp.longestSpan() << std::endl;

    std::cout << "-------------------------------------------------------------------------\n";
}

int	main(void)
{
    subjectTest();
	Span sp = Span(100001);
	try
	{
		addRandomRange(sp, 100001);
        // addRandomRange2(sp, 10);
        std::cout << "Shortest Span =  " <<  sp.shortestSpan() << std::endl;
        std::cout << "Longest Span = " << sp.longestSpan() << std::endl;
		// sp.printSpan();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
