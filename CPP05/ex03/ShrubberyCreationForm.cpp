#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shruberry", 145, 137), _target("Default")
{
	std::cout << YELLOW << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("Shrubbery", 145, 137), _target(target)
{
	std::cout << YELLOW << "ShrubberyCreationForm target constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << YELLOW << "ShrubberyCreationForm deconstructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src): AForm(src), _target(src._target)
{
	std::cout << YELLOW "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	std::cout << YELLOW "ShrubberyCreationForm assignement operator called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return (*this);
}

void ShrubberyCreationForm::exec_form() const
{
	std::ofstream newFile(this->_target.c_str(), std::ofstream::out | std::ofstream::app);
	if (newFile.is_open())
	{
		newFile << "       _-_" << std::endl;
		newFile << "    /~~   ~~\\" << std::endl;
		newFile << " /~~         ~~\\" << std::endl;
		newFile << "{                   }" << std::endl;
		newFile << " \\  _-     -_  /" << std::endl;
		newFile << "   ~  \\\\ //  ~" << std::endl;
		newFile << "_- -   | | _- _" << std::endl;
		newFile << "  _ -  | |   -_" << std::endl;
		newFile << "      // \\\\" << std::endl;
		newFile.close();
	}
	else
	{
		std::cerr << RED << "Couldn't open file" << RESET << std::endl;
	}
}
