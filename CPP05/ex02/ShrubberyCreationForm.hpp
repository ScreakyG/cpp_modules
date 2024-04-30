#ifndef SHRUBBERY_FORM
#define SHRUBERRY_FORM

#include "AForm.hpp"

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

class ShrubberyCreationForm : public AForm
{
	public :
		// CANONICAL FORM
		ShrubberyCreationForm(); // Default constructor
		ShrubberyCreationForm(const ShrubberyCreationForm &src); // Copy constructor
		~ShrubberyCreationForm(); // Deconstructor
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &rhs); // Assignement operator

		ShrubberyCreationForm(const std::string target);
		void exec_form(const Bureaucrat &executor) const;

	private :
		std::string _target;
};

#endif
