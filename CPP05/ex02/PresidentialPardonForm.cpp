#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon", 25, 5), _target("Default")
{
	std::cout << YELLOW << "PresidentialPardonForm default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("Presidential Pardon", 25, 5), _target(target)
{
	std::cout << YELLOW << "PresidentialPardonForm target constructor called" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << YELLOW << "PresidentialPardonForm destructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src): AForm(src), _target(src._target)
{
	std::cout << YELLOW "PresidentialPardonForm copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	std::cout << YELLOW "PresidentialPardonForm assignment operator called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return (*this);
}

void PresidentialPardonForm::exec_form() const
{
	std::cout << _target + " has been pardoned by Zaphod Beeblebrox."<< std::endl;
}
