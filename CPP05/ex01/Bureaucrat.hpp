#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

class Form;

class Bureaucrat
{
    public:
		Bureaucrat(); //Default constructor
        Bureaucrat(const std::string &name, int grade);
        ~Bureaucrat(); // Default destructor.
        Bureaucrat(const Bureaucrat &src); // Copy constructor.
        Bureaucrat& operator=(const Bureaucrat &src); // Assignement operator.

        const std::string&	getName() const;
        int					getGrade() const;
        void				increase_grade();
        void				decrease_grade();
		void				signForm(Form& obj) const;

        class  GradeTooHighException : public std::exception
        {
            public :
                virtual const char * what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

    private:

        const std::string	_name;
        int					_grade;
};

std::ostream & operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
