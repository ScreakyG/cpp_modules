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

bool PhoneBook::addContact(void)
{
	if (_contact_tab.fillContact() == false)
		return (false);
	return (true);
}