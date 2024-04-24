#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat  og("Og", 1);
		Bureaucrat	copy = og;

    }
    catch (const std::exception &e)
    {
		std::cerr << RED << e.what() << RESET << std::endl;
    }
    // try
    // {
    //     Bureaucrat test("Joe", 10000000);
    // }
    // catch (std::exception &e)
    // {
    //     std::cerr << RED << e.what() << RESET << std::endl;
    // }
    // try
    // {
    //     Bureaucrat jack("Jack", 0);
    // }
    // catch (std::exception &e)
    // {
            //std::cerr << RED << e.what() << RESET << std::endl;
    // }
    // try
    // {
    //     Bureaucrat bill("Bill", 1);
    //     bill.increase_grade();
    //     std::cout << bill.getGrade() << std::endl;
    // }
    // catch (std::exception const &e)
    // {
    //     std::cerr << RED << e.what() << RESET << std::endl;
    // }
    // try
    // {
    //     Bureaucrat cahiman("Cahiman", 149);
    //     cahiman.decrease_grade();
    //     std::cout << cahiman;
    // }
    // catch (std::exception const &e)
    // {
    //     std::cerr << RED << e.what() << RESET << std::endl;
    // }
}
