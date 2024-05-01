#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

class AForm;

class Intern
{
	public:
		Intern(); // Default constructor
		Intern(const Intern &src); // Copy constructor
		Intern& operator=(const Intern &rhs); // Asssignement operator
		~Intern(); // Destructor

		AForm* makeForm(const std::string &form_name, const std::string &target);
};

#endif
