#include "Bureaucrat.hpp"

void	gradeTests(const std::string &name, int grade)
{
	try
	{
		Bureaucrat test(name, grade);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
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

		std::cout << jack;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	// Increase / Decrease tests

	try
	{
		Bureaucrat ceo("Logan", 1);
		ceo.decrease_grade();
		std::cout << ceo;

		Bureaucrat kendall("Kendall", 150);
		kendall.increase_grade();
		std::cout << kendall;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}
