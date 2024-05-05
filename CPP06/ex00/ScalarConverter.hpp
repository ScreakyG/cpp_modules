#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP


#include <string>


class ScalarConverter
{
	public:
		~ScalarConverter(); // Destructor
		static void	convert(std::string value);
	private:
		ScalarConverter(); // Default constructor
		ScalarConverter(const ScalarConverter &src); // Copy constructor
		ScalarConverter& operator=(const ScalarConverter &rhs); // Assigment operator

		static std::string identifyType(std::string value);
};

#endif
