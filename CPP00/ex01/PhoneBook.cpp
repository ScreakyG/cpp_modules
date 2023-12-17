#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook Constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook Deconstructor called" << std::endl;
	return ;
}

void PhoneBook::addContact(void)
{
	_contact_tab.fillContact();
}