#include "Bureaucrat.hpp"
#include "Form.hpp"



int main(void)
{
	try
	{
		Form test("Contrat", 1, 150);
		Form test2("Contrat2", 150, 1);
		test = test2;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}
