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

static void	performOperation(std::string &value, std::stack<double> &stack)
{
	double	a;
	double	b;

	if (stack.size() < 2)
		throw std::runtime_error("invalid expression");
	a = stack.top();
	stack.pop();
	b = stack.top();
	stack.pop();

	switch(value[0])
	{
		case '+' :
			stack.push(b + a);
			break ;
		case '-' :
			stack.push(b - a);
			break ;
		case '/' :
			//verifier division par 0.
			stack.push(b / a);
			break ;
		case '*' :
			stack.push(b * a);
			break ;
		default:
			throw std::runtime_error("invalid operator detected");
	}
}

static bool isValidOperand(std::string &value)
{
	double	operand;
	char	*endptr = NULL;

	if (value.empty())
		return (false);
	operand = std::strtod(value.c_str(), &endptr);
	if (*endptr != '\0')
		throw std::runtime_error("invalid expression");
	if (operand < 0 || operand > 9)
		throw std::runtime_error("invalid expression, a operand is > 9 or < 0");
	return (true);
}

static bool isOperator(std::string &value)
{
	if (value == "+" || value == "-" || value == "*" || value == "/")
		return (true);
	return (false);
}

void RPN::Calculate(char *argv)
{

	std::string				expression(argv);
	std::size_t				found = 0;
	std::string				value;
	std::stack<double>			stack;

	try
	{
		found = expression.find(" ");
		while (found != std::string::npos)
		{
			value = expression.substr(0, found);
			expression = expression.substr(found + 1);
			if (isOperator(value) == true)
				performOperation(value, stack);
			else if (isValidOperand(value) == true)
				stack.push(std::strtod(value.c_str(), NULL));
			found = expression.find(" ");

			if (found == std::string::npos)
			{
				value = expression.substr(0, found);
				if (value.empty())
					break ;
				else if (isOperator(value) == true)
					performOperation(value, stack);
				else if (isValidOperand(value))
					stack.push(std::strtod(value.c_str(), NULL));
			}
		}
		if (stack.size() != 1)
			throw std::runtime_error("invalid expression");
		std::cout << stack.top() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}
}
