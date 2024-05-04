#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

Intern::Intern()
{
	std::cout << YELLOW << "Intern default constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern &src)
{
	(void)src;
	std::cout << YELLOW << "Intern copy constructor called" << RESET << std::endl;
}

Intern& Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	std::cout << YELLOW << "Intern assignement operator called" << RESET << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << YELLOW << "Intern destructor called" << RESET << std::endl;
}

AForm* Intern::makeForm(const std::string &form_name, const std::string &target)
{
	const std::string	forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	std::size_t	idx = -1;
	std::size_t	i = 0;

	while (i < 3)
	{
		if (forms[i] == form_name)
			idx = i;
		i++;
	}
	switch(idx)
	{
		case 0:
			std::cout << GREEN << "Intern creates " + form_name << RESET << std::endl;
			return (new ShrubberyCreationForm(target));
		case 1:
			std::cout << GREEN << "Intern creates " + form_name << RESET << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << GREEN << "Intern creates " + form_name << RESET << std::endl;
			return (new PresidentialPardonForm(target));
		default:
			std::cout << "Couldn't find any matching form for " + form_name << std::endl;
			break ;
	}
	return (NULL);
}

