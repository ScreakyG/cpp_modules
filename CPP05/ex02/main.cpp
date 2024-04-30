#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat ceo("Logan", 145);
	Bureaucrat boss("Kendall", 137);
	ShrubberyCreationForm test2("Start");
	std::cout << test2;
	//ceo.signForm(test2);
	boss.executeForm(test2);

}


