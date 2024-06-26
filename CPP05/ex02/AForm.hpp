#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
	public:
		AForm(); // Canonical default constructor
		AForm(const std::string &name, const int signGrade, const int execGrade);
		AForm(const AForm &src); // Canonical copy constructor
		virtual ~AForm(); // Canonical destructor
		AForm &operator=(const AForm &rhs); // Canonical assignment operator


		//Getters
		const	bool&	getIsSigned() const;
		const	std::string& getName() const;
		int	getSignGrade() const;
		int	getExecGrade() const;

		void	beSigned(const Bureaucrat &obj);
		void	execute(Bureaucrat const & executor) const;


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
		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};

	private:
		bool				_isSigned;
		const std::string	_name;
		const int			_requiredSignGrade;
		const int			_requiredExecGrade;
		virtual void	exec_form() const = 0;
};

std::ostream& operator<<(std::ostream &os, const AForm& obj);

#endif
