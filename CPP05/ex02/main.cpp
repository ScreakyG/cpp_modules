#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	signAndExec(Bureaucrat &executor, AForm* form)
{
	std::cout << "<-------------------------------------------->" << std::endl;
	if (form)
	{
		executor.signForm(*form);
		executor.executeForm(*form);
		delete	form;
	}
}

void	goodTests()
{
	Bureaucrat ceo("Logan", 1);

	AForm* shrub = new ShrubberyCreationForm("Home");
	AForm* robotomy = new RobotomyRequestForm("Dummy");
	AForm* pardon = new PresidentialPardonForm("Roman");

	signAndExec(ceo, shrub);
	signAndExec(ceo, robotomy);
	signAndExec(ceo, pardon);
}

void	wrongTests()
{
	Bureaucrat clown("Kendall", 145);

	AForm* shrub = new ShrubberyCreationForm("Home");
	AForm* robotomy = new RobotomyRequestForm("Dummy");
	AForm* pardon = new PresidentialPardonForm("Roman");

	signAndExec(clown, shrub);
	signAndExec(clown, robotomy);
	signAndExec(clown, pardon);
}

int main(void)
{
	goodTests();
	wrongTests();
}


