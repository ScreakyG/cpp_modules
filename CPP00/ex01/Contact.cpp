#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Contact Constructor called" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "Contact Deconstructor called" << std::endl;
	return ;
}

bool Contact::fillContact(void)
{
	_FirstName = "fgonzale";
	_LastName = "Gonzalez";
	std::cout << "FirstName = " << _FirstName << std::endl;
	std::cout << "LastName = " << _LastName << std::endl;
	return (true);
}