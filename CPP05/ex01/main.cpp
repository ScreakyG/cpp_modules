#include "Bureaucrat.hpp"
#include "Form.hpp"



int main(void)
{
	try
	{
		Form test("Contrat", 1, 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}
