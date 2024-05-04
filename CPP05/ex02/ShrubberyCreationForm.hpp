#ifndef SHRUBBERY_FORM
#define SHRUBERRY_FORM

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public :
		// CANONICAL FORM
		ShrubberyCreationForm(); // Default constructor
		ShrubberyCreationForm(const ShrubberyCreationForm &src); // Copy constructor
		~ShrubberyCreationForm(); // Deconstructor
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &rhs); // Assignement operator

		ShrubberyCreationForm(const std::string target);

	private :
		std::string _target;
		void exec_form() const;
};

#endif
