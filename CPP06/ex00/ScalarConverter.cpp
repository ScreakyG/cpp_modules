#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <limits.h>
#include <cfloat>
#include <iomanip>

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

void	printChar(long character)
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
		std::cout << "int: " << nb << std::endl;
}

void	printFloat(float nb)
{
	if (nb > FLT_MAX || nb < -FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << nb  << "f" << std::endl;
}

void	printDouble(double nb)
{
	if (nb > DBL_MAX || nb < -DBL_MAX)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << nb << std::endl;
}

void	scalarFromChar(std::string &value)
{
	printChar(static_cast<int>(value[0]));
	printInt(static_cast<long>(value[0]));
	printFloat(static_cast<float>(value[0]));
	printDouble(static_cast<double>(value[0]));
}

void	scalarFromInt(std::string &value)
{
	long	intNb;

	intNb = std::atol(value.c_str());

	printChar(intNb);
	printInt(intNb);
	printFloat(static_cast<float>(intNb));
	printDouble(static_cast<double>(intNb));
}

void	scalarFromFloat(std::string &value)
{
	double	doubleValue;

	doubleValue = std::atof(value.c_str());
	printChar(static_cast<int>(doubleValue));
	printInt(static_cast<int>(doubleValue));
	printFloat(static_cast<float>(doubleValue));
	printDouble(doubleValue);
}

void	scalarFromDouble(std::string &value)
{
	double	doubleValue;

	doubleValue = std::atof(value.c_str());
	printChar(static_cast<int>(doubleValue));
	printInt(static_cast<int>(doubleValue));
	printFloat(static_cast<float>(doubleValue));
	printDouble(doubleValue);
}

void	scalarImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
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
			std::cout << "Will convert from a char" << std::endl;
			scalarFromChar(value);
			break ;
		case 1:
			std::cout << "Will convert from a int" << std::endl;
			scalarFromInt(value);
			break ;
		case 2:
			std::cout << "Will convert from a float" << std::endl;
			scalarFromFloat(value);
			break ;
		case 3:
			std::cout << "Will convert from a double" << std::endl;
			scalarFromDouble(value);
			break ;
		default:
			std::cout << "Will not convert / impossible" << std::endl;
			scalarImpossible();
			break ;
	}

}

bool	isInt(std::string &value)
{
	char	*endptr;

	std::strtol(value.c_str(), &endptr, 0);
	if (endptr == value.c_str() || *endptr != '\0')
		return (false);
	return (true);
}

bool	isFloat(std::string &value)
{
	char	*endptr;

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

