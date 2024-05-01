#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat ceo("Logan", 1);
	Bureaucrat boss("Kendall", 100);
	PresidentialPardonForm test2("Roman");
	std::cout << test2;
	ceo.signForm(test2);
	//test2.beSigned(ceo);
	ceo.executeForm(test2);

}


