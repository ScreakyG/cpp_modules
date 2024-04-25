#include "Form.hpp"

Form::Form(): _isSigned(false), _name("Default"), _requiredSignGrade(150), _requiredExecGrade(150)
{
	std::cout << YELLOW << "Successfully created default form" << std::endl;
}

Form::Form(const std::string &name, const int signGrade, const int execGrade): _isSigned(false), _name(name), _requiredSignGrade(signGrade), _requiredExecGrade(execGrade)
{
	if (signGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150)
		throw Form::GradeTooLowException();
	std::cout << YELLOW << "Successfully created form named " << this->_name << RESET << std::endl;
}

Form::~Form()
{
	std::cout << YELLOW << "Successfully called destructor for form named " << this->_name << RESET << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form required grades are too high , grade 1 is highest");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form required grades are too low, grade 150 is lowest");
}
