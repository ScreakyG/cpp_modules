#include "Bureaucrat.hpp"
#include "Form.hpp"



int main(void)
{
	try
	{
		Form test("Contrat", 1, 150);
		Bureaucrat ceo("Logan", 2);
		ceo.signForm(test);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}
