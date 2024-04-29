#include "Bureaucrat.hpp"
#include "Form.hpp"



int main(void)
{
	try
	{
		Form test("Contrat", 1, 150);
		Bureaucrat ceo("Logan", 1);
		Bureaucrat dop("Roman", 2);
		test.beSigned(ceo);
		test.beSigned(dop);
		ceo.signForm(test);
		dop.signForm(test);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}


