#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	formTest(std::string formName, std::string target)
{
	Intern	random;
	AForm *form = NULL;
	Bureaucrat ceo("Logan", 25);

	form = random.makeForm(formName, target);
	if (form)
	{
		std::cout << *form;
		ceo.signForm(*form);
		ceo.executeForm(*form);
		delete form;
	}
}

int main(void)
{
	formTest("presidential pardon", "Bender");
	formTest("robotomy request", "Bender");
	formTest("shrubbery creation", "Home");

	formTest("not good", "nono");
}


