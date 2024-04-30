#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy", 72, 45), _target("Default")
{
	std::cout << YELLOW << "RobotomyRequestForm default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("Robotomy", 72, 45), _target(target)
{
	std::cout << YELLOW << "RobotomyRequestForm target constructor called" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << YELLOW << "RobotomyRequestForm deconstructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src): AForm(src), _target(src._target)
{
	std::cout << YELLOW "RobotomyRequestForm copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	std::cout << YELLOW "RobotomyRequestForm assignment operator called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return (*this);
}

void RobotomyRequestForm::exec_form() const
{
	static bool seeded = false;
	if (!seeded)
	{
		srand(time(NULL));
		seeded = true;
	}

	std::cout << "Starting robotomy procedure..." << std::endl;
	std::cout << "   ____" << std::endl;
	std::cout << "  |    |" << std::endl;
	std::cout << "  |    |" << std::endl;
	std::cout << "  |____|" << std::endl;
	std::cout << "    ||" << std::endl;
	std::cout << "    ||" << std::endl;
	std::cout << "    ||" << std::endl;
	std::cout << "   \\  /" << std::endl;
	std::cout << "    \\/" << std::endl;
	if (std::rand() % 2 == 1)
	{
		std::cout << "*****DRILL PAPPAPAPAPPAP BIP*****" << std::endl;
		std::cout << _target + " has been robotomized" << std::endl;
	}
	else
		std::cout << "Robotomy failed on " + _target << std::endl;
}
