#ifndef PRESIDENTIALPARDONFORM_HPP
 #define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(); // Default constructor
		PresidentialPardonForm(const PresidentialPardonForm &src); // Copy constructor
		~PresidentialPardonForm(); // Destructor
		PresidentialPardonForm& operator=(const PresidentialPardonForm &rhs); // Assignment operator

		PresidentialPardonForm(const std::string target); // Target constructor

	private:
		std::string	_target;
		void exec_form() const;
};

#endif
