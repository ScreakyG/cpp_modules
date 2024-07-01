#include "RPN.hpp"

RPN::RPN() {};
RPN::RPN(const RPN &src) {(void)src;};
RPN::~RPN() {};

RPN& RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
		std::cout << "Useless assignement operator called" << std::endl;
	return (*this);
}

void RPN::Calculate(char *argv)
{
	(void)argv;
	std::cout << "Calling Calculte function" << std::endl;
}
