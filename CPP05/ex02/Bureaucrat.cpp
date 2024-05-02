#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void): _name("Default"), _grade(150)
{
    std::cout << YELLOW "Successfully created Bureaucrat " << _name << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(150)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade = grade;
    std::cout << YELLOW "Successfully created Bureaucrat " << _name << RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << YELLOW "Deconstructor Bureaucrat called " << this->_name << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
    std::cout << YELLOW "Successfully created Bureaucrat from copy constructor" << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
        this->_grade = src._grade;
    std::cout << YELLOW "Successfully copied Bureaucrat from assignement operator" RESET << std::endl;
	return (*this);
}

const std::string& Bureaucrat::getName() const
{
    return (this->_name);
}

int   Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void    Bureaucrat::increase_grade()
{
    int current_grade = this->_grade;
    current_grade--;
    if (current_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade = current_grade;
}

void    Bureaucrat::decrease_grade()
{
    int current_grade = this->_grade;
    current_grade++;
    if (current_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = current_grade;
}

void	Bureaucrat::signForm(AForm& obj) const
{
	try
	{
		obj.beSigned(*this);
		std::cout << GREEN << this->getName() << " signed " << obj.getName() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << this->getName() << " couldn't sign " << obj.getName() << " because required grade is " << obj.getSignGrade() << " and " << this->getName() << " is grade " << this->getGrade() << RESET << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm& obj) const
{
	try
	{
		obj.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << this->getName() <<" couldn't execute form " << obj.getName() << " because : " << e.what() << RESET << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Error with grade , it's over grade 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Error with grade , it's under grade 150");
}

std::ostream & operator<<(std::ostream &os, const Bureaucrat &obj)
{
    os << obj.getName() << " , bureaucrat grade " << obj.getGrade() << "." << std::endl;
    return (os);
}
