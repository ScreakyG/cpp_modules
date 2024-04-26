#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _isSigned(false), _name("Default"), _requiredSignGrade(150), _requiredExecGrade(150)
{
	std::cout << YELLOW << "Successfully created default form" << std::endl;
}

Form::Form(const std::string &name, const int signGrade, const int execGrade): _isSigned(false), _name(name), _requiredSignGrade(signGrade), _requiredExecGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	std::cout << YELLOW << "Successfully created form named " << this->_name << RESET << std::endl;
}

Form::Form(const Form &src): _isSigned(false), _name(src._name), _requiredSignGrade(src._requiredSignGrade), _requiredExecGrade(src._requiredExecGrade)
{
	std::cout << YELLOW << "Successfully copied form named " << this->_name << RESET << std::endl;
}

Form::~Form()
{
	std::cout << YELLOW << "Successfully called destructor for form named " << this->_name << RESET << std::endl;
}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
		std::cout << YELLOW << "Successfully assigned form named " << this->_name << RESET << std::endl;
	}
	return (*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form required grades are too high , grade 1 is highest");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form required grades are too low, grade 150 is lowest");
}

const bool& Form::getIsSigned() const
{
	return (this->_isSigned);
}

const std::string& Form::getName() const
{
	return (this->_name);
}

int Form::getSignGrade() const
{
	return (this->_requiredSignGrade);
}

int Form::getExecGrade() const
{
	return (this->_requiredExecGrade);
}

std::ostream& operator << (std::ostream &os, const Form &obj)
{
	os << obj.getName() << " : " << "Is Signed = " << obj.getIsSigned() << ", Required Sign Grade = " << obj.getSignGrade() << ", Required Exec Grade = " << obj.getExecGrade() << std::endl;
	return (os);
}

void Form::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() > this->getSignGrade())
	{
		obj.signForm(*this);
		throw Form::GradeTooLowException();
	}
	this->_isSigned = true;
	obj.signForm(*this);
}
