#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

class Form
{
	public:
		Form(); // Canonical default constructor
		Form(const std::string &name, const int signGrade, const int execGrade);
		Form(const Form &src); // Canonical copy constructor
		~Form(); // Canonical destructor
		Form &operator=(const Form &rhs); // Canonical assignment operator

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

	private:
		bool				_isSigned;
		const std::string	_name;
		const int			_requiredSignGrade;
		const int			_requiredExecGrade;
};

#endif
