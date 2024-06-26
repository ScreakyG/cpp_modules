#include "Bureaucrat.hpp"

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

void	gradeTests(const std::string &name, int grade)
{
	std::cout << CYAN << "Creating " << name << " with grade " << grade << RESET << std::endl;
	try
	{
		Bureaucrat test(name, grade);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

int main(void)
{
	// Bureaucrat creation tests , can't initiate if grade has wrong value

	gradeTests("Joe", 1);
	gradeTests("Jack", 0);
	gradeTests("Levi", 100);
	gradeTests("Dummy", 151);

	// Copy & Assignement tests

	try
	{
		Bureaucrat og("Og", 10);
		std::cout << og << std::endl;

		Bureaucrat	copy(og);
		std::cout << copy << std::endl;

		Bureaucrat	bill("Bill", 100);
		Bureaucrat	jack("Jack", 50);
		jack = bill;
		std::cout << jack << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	// Increase / Decrease tests

	try
	{
		Bureaucrat ceo("Logan", 1);
		ceo.decrease_grade();
		std::cout << ceo << std::endl;

		Bureaucrat kendall("Kendall", 150);
		kendall.increase_grade();
		std::cout << kendall << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}
