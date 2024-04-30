#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat ceo("Logan", 1);
	AForm* test = new ShrubberyCreationForm("Home");
	std::cout << *test;
	
	ceo.signForm(*test);
	test->execute(ceo);

	delete test;
}


