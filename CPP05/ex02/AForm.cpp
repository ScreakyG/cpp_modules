#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _isSigned(false), _name("Default"), _requiredSignGrade(150), _requiredExecGrade(150)
{
	std::cout << YELLOW << "Successfully created default form" << std::endl;
}

AForm::AForm(const std::string &name, const int signGrade, const int execGrade): _isSigned(false), _name(name), _requiredSignGrade(signGrade), _requiredExecGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	std::cout << YELLOW << "Successfully created form named " << this->_name << RESET << std::endl;
}

AForm::AForm(const AForm &src): _isSigned(false), _name(src._name), _requiredSignGrade(src._requiredSignGrade), _requiredExecGrade(src._requiredExecGrade)
{
	std::cout << YELLOW << "Successfully copied form named " << this->_name << RESET << std::endl;
}

AForm::~AForm()
{
	std::cout << YELLOW << "Successfully called destructor for form named " << this->_name << RESET << std::endl;
}

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
		std::cout << YELLOW << "Successfully assigned form named " << this->_name << RESET << std::endl;
	}
	return (*this);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

const bool& AForm::getIsSigned() const
{
	return (this->_isSigned);
}

const std::string& AForm::getName() const
{
	return (this->_name);
}

int AForm::getSignGrade() const
{
	return (this->_requiredSignGrade);
}

int AForm::getExecGrade() const
{
	return (this->_requiredExecGrade);
}

std::ostream& operator << (std::ostream &os, const AForm &obj)
{
	os << obj.getName() << " : " << "Is Signed = " << obj.getIsSigned() << ", Required Sign Grade = " << obj.getSignGrade() << ", Required Exec Grade = " << obj.getExecGrade() << std::endl;
	return (os);
}

void AForm::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	else
		this->_isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (this->_isSigned == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->_requiredExecGrade)
		throw AForm::GradeTooLowException();
	else
	{
		exec_form();
		std::cout << GREEN << executor.getName() + " executed " + this->getName() << RESET << std::endl;
	}
}


