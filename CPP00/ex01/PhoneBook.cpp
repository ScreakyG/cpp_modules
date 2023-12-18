#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _nbContact(-1)
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
	_nbContact++;
	return (true);
}

void PhoneBook::_printHeader(void)
{
	std::cout << std::setw(10) << std::setfill(' ') << "INDEX";
	std::cout << "|";
	std::cout << std::setw(10) << std::setfill(' ') << "FIRST NAME";
	std::cout << "|";
	std::cout << std::setw(10) << std::setfill(' ') << "LAST NAME";
	std::cout << "|";
	std::cout << std::setw(10) << std::setfill(' ') << "NICKNAME" << std::endl;
	std::cout << "----------|----------|----------|----------" << std::endl;
}

void	PhoneBook::_printBookContacts(std::string str, bool separator)
{
	if (str.size() > 10)
	{
		std::cout << "Trimmed.";
	}
	else
		std::cout << std::setw(10) << std::setfill(' ') << str;
	if (separator == true)
		std::cout << "|";
}

bool PhoneBook::printSearch(void)
{
	int	i;

	i = 0;
	if (_nbContact < 0)
		std::cout << "No contact in phonebook";
	else
	{
		_printHeader();
		while (i < _nbContact + 1)
		{
			_printBookContacts("1", 1);
			_printBookContacts(_contact_tab.getFirstName(), 1);
			_printBookContacts(_contact_tab.getFirstName(), 1);
			_printBookContacts(_contact_tab.getFirstName(), 0);
			std::cout << std::endl;
			i++;
		}
	}
	std::cout << std::endl;
	return (true);
}