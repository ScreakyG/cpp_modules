#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <exception>
#include <cstdlib>
#include <time.h>

Base	*generator(void)
{
	int	random_nb;

	srand(time(NULL));
	random_nb = rand() % 3;
	switch (random_nb)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			return (NULL);
	}
}

void	identify(Base *p)
{
	A *ptrA = dynamic_cast<A*>(p);
	if (ptrA)
	{
		std::cout << "Real type of Base *p = A" << std::endl;
		return ;
	}
	B *ptrB = dynamic_cast<B*>(p);
	if (ptrB)
	{
		std::cout << "Real type of Base *p = B" << std::endl;
		return ;
	}
	C *ptrC = dynamic_cast<C*>(p);
	if (ptrC)
	{
		std::cout << "Real type of Base *p = C" << std::endl;
		return ;
	}
	std::cout << "Couldn't identify real type of Base *p" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A &refA = dynamic_cast<A &>(p);
		std::cout << "Real type of Base &p = A" << std::endl;
		(void)refA;
		return ;
	}
	catch (std::exception &e) {};

	try
	{
		B &refB = dynamic_cast<B &>(p);
		std::cout << "Real type of Base &p = B" << std::endl;
		(void)refB;
		return ;
	}
	catch (std::exception &e) {};

	try
	{
		C &refC = dynamic_cast<C &>(p);
		std::cout << "Real type of Base &p = C" << std::endl;
		(void)refC;
		return ;
	}
	catch (std::exception &e) {};
	std::cout << "Couldn't identify real type of Base &p" << std::endl;
}

int	main(void)
{
	Base *ptr = generator();
	Base &ref = *ptr;

	identify(ptr);
	identify(ref);
	delete (ptr);
}
