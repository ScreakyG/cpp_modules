#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

void	createForms(std::string name, int signGrade, int execGrade)
{
	try
	{
		std::cout << CYAN << "Creating form named " << name << RESET << std::endl;
		Form	form(name, signGrade, execGrade);
	}
	catch(std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

int main(void)
{
	// Creating Forms Tests

	createForms("Stage", 1, 1);
	createForms("Wrong", 1, 151);
	createForms("Wrong2", 0, 150);

	std::cout << "<---------------------->" << std::endl;
	try
	{
	// Copy Tests

	Form original("Contrat", 5, 25);
	std::cout << original;
	Form copy(original);
	std::cout << copy;

	std::cout << "<---------------------->" << std::endl;

	Form test = Form("Test1", 100, 100);
	std::cout << test;

	std::cout << "<---------------------->" << std::endl;

	// Sign form tests

	Bureaucrat	ceo("Logan", 100);
	original.beSigned(ceo);
	ceo.signForm(original);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat	boss("Boss", 1);
		Form		base("Base", 100, 100);

		base.beSigned(boss);
		boss.signForm(base);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}


