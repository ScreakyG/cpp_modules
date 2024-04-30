#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Bureaucrat ceo("Logan", 1);
	Bureaucrat boss("Kendall", 100);
	RobotomyRequestForm test2("Start");
	std::cout << test2;
	ceo.signForm(test2);
	//test2.beSigned(ceo);
	boss.executeForm(test2);

}


