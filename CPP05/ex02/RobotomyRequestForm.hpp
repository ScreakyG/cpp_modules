#ifndef ROBOTOMY_HPP
 #define ROBOTOMY_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(); // Default constructor
		RobotomyRequestForm(const RobotomyRequestForm &src); // Copy constructor
		~RobotomyRequestForm(); // Destructor
		RobotomyRequestForm& operator=(const RobotomyRequestForm &rhs); // Assigmement operator`

		RobotomyRequestForm(const std::string target); // Target constructor

	private:
		std::string	_target;
		void exec_form() const;
};

#endif
