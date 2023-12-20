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

bool Contact::fill_infos(std::string msg, std::string *variable)
{
	std::string input;

	std::cout << msg << " : ";
	if (!(getline(std::cin, input)))
	{
		std::cout << "Exiting" << std::endl;
		return (false);
	}
	if (input.empty())
	{
		if (fill_infos(msg, variable) == false)
			return (false);
	}
	else
		*variable = input;
	return (true);

}

bool Contact::fillContact(void)
{
	if (fill_infos("First Name", &_FirstName) == false)
		return (false);
	if (fill_infos("Last Name", &_LastName) == false)
		return (false);
	if (fill_infos("Nickame", &_Nickname) == false)
		return (false);
	if (fill_infos("PhoneNumber", &_PhoneNumber) == false)
		return (false);
	if (fill_infos("Your darkest secret", &_Secret) == false)
		return (false);
	std::cout << GREEN << "CONTACT ADDED" << RESET << std::endl;
	return (true);
}

std::string Contact::getFirstName(void)
{
	return (this->_FirstName);
}

std::string Contact::getLastName(void)
{
	return (this->_LastName);
}

std::string Contact::getNickname(void)
{
	return (this->_Nickname);
}

void Contact::printInfos(void)
{
	std::cout << "First Name : " << _FirstName << std::endl;
	std::cout << "Last Name : " << _LastName << std::endl;
	std::cout << "Nickname : " << _Nickname << std::endl;
	std::cout << "PhoneNumber : " << _PhoneNumber << std::endl;
	std::cout << "Darkest Secret : " << _Secret << std::endl;
}