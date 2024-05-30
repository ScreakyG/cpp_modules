#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <limits.h>
#include <cfloat>
#include <iomanip>
#include <cerrno>
#include <cstring>

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

ScalarConverter::ScalarConverter()
{
	std::cout << YELLOW << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
	std::cout << YELLOW << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << YELLOW << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	std::cout << YELLOW << "ScalarConverter assignement operator called" << std::endl;
	return (*this);
}

void	printChar(int character)
{
	if (character > CHAR_MAX || character < CHAR_MIN)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(character))
		std::cout << "char: " << "'" << static_cast<char>(character) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void	printInt(long nb)
{
	if (nb > INT_MAX || nb < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(nb) << std::endl;
}

void	printFloat(float nb)
{
	std::cout << "float: " << nb << "f" << std::endl;
	//std::cout << "float: " << std::fixed << std::setprecision(1) << nb  << "f" << std::endl;
}

void	printDouble(double nb)
{
	std::cout << "double: " << nb << std::endl;
}

void	scalarFromChar(std::string &value)
{
	std::cout << CYAN << "Converting CHAR : " + value << RESET << std::endl;

	printChar(static_cast<int>(value[0]));
	printInt(static_cast<long>(value[0]));
	printFloat(static_cast<float>(value[0]));
	printDouble(static_cast<double>(value[0]));
}

void	scalarFromInt(std::string &value)
{
	long	intNb;

	intNb = std::atol(value.c_str());

	std::cout << CYAN << "Converting INT : " + value << RESET << std::endl;

	printChar(static_cast<int>(intNb));
	printInt(intNb);
	printFloat(static_cast<float>(intNb));
	printDouble(static_cast<double>(intNb));
}

void	scalarFromFloat(std::string &value)
{
	float	floatValue;

	errno = 0;
	floatValue = std::strtof(value.c_str(), NULL);
	if (errno)
	{
		std::cerr << RED << "Couldn't convert float : " << std::strerror(errno) << RESET << std::endl;
		return ;
	}

	std::cout << CYAN << "Converting FLOAT : " + value << RESET << std::endl;

	printChar(static_cast<int>(floatValue));
	printInt(static_cast<long>(floatValue));
	printFloat(static_cast<float>(floatValue));
	printDouble(static_cast<double>(floatValue));
}

void	scalarFromDouble(std::string &value)
{
	double	doubleValue;

	errno = 0;
	doubleValue = std::strtod(value.c_str(), NULL);
	if (errno)
	{
		std::cerr << RED << "Couldn't convert double : " << std::strerror(errno) << RESET << std::endl;
		return ;
	}

	std::cout << CYAN << "Converting DOUBLE : " + value << RESET << std::endl;

	printChar(static_cast<int>(doubleValue));
	printInt(static_cast<long>(doubleValue));
	printFloat(static_cast<float>(doubleValue));
	printDouble(doubleValue);
}

void	ScalarConverter::convert(std::string value)
{
	std::string	types[] = {"char", "int", "float", "double"};
	std::string	type;
	size_t	idx = -1;
	size_t	i = 0;

	type = identifyType(value);
	while (i < 4)
	{
		if (types[i] == type)
			idx = i;
		i++;
	}

	switch (idx)
	{
		case 0:
			scalarFromChar(value);
			break ;
		case 1:
			scalarFromInt(value);
			break ;
		case 2:
			scalarFromFloat(value);
			break ;
		case 3:
			scalarFromDouble(value);
			break ;
		default:
			std::cout << RED << "Couldn't detect type to convert from" << RESET << std::endl;
			break ;
	}

}

bool	isInt(std::string &value)
{
	char	*endptr;
	long	longValue;

	longValue = std::strtol(value.c_str(), &endptr, 0);
	if (endptr == value.c_str() || *endptr != '\0')
		return (false);
	if (longValue < INT_MIN || longValue > INT_MAX)
		return (false);
	return (true);
}

bool	isFloat(std::string &value)
{
	char	*endptr;

	if (value == "-nanf")
		return (false);

	std::strtof(value.c_str(), &endptr);
	if (endptr == value.c_str() || *endptr != 'f')
		return (false);
	if (*endptr == 'f' && *(endptr + 1) != '\0')
		return (false);
	return (true);
}

bool	isDouble(std::string &value)
{
	char	*endptr;

	if (value == "-nan")
		return (false);

	std::strtod(value.c_str(), &endptr);
	if (endptr == value.c_str() || *endptr != '\0')
		return (false);
	return (true);
}

std::string ScalarConverter::identifyType(std::string value)
{
	if (value.length() == 0)
		return ("empty");
	if (value.length() == 1 && !std::isdigit(value[0]))
		return ("char");
	if (isInt(value))
		return ("int");
	if (isFloat(value))
		return ("float");
	if (isDouble(value))
		return ("double");
	return ("other");
}

