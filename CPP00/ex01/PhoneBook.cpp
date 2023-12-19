#include "PhoneBook.hpp"
#include <cstdlib>

PhoneBook::PhoneBook(void) : _nbContact(0)
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
	if (_contact_tab[_nbContact % 8].fillContact() == false) //Si j'ajoute un 9eme contact je lecris dans lemplacement 0.
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
		std::cout << "Trimmed."; // Faire un substr de str et trim.
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
	if (_nbContact == 0)
	{
		std::cout << "No contact in phonebook";
		std::cout << std::endl;
		return (true);
	}
	else
	{
		_printHeader();
		while (i < _nbContact && i < 8) // _nbContact peut etre superieur a 8.
		{
			_printBookContacts(std::string(1, (i + '0')), 1);
			_printBookContacts(_contact_tab[i].getFirstName(), 1);
			_printBookContacts(_contact_tab[i].getLastName(), 1);
			_printBookContacts(_contact_tab[i].getNickname(), 0);
			std::cout << std::endl;
			i++;
		}
	}
	if (_printIndexPrompt() == false)
		return (false);
	return (true);
}

bool PhoneBook::_printIndexPrompt(void)
{
	int			index;
	std::string index_ascii;

	std::cout << "Enter contact index : ";
	if (!(getline(std::cin, index_ascii)))
		return (false);
	// Gerer si index_ascii est empty et si i < 0 ou > nb_contact;
	index = std::atoi(index_ascii.c_str());
	if (index_ascii.empty() || index < 0 || index >= _nbContact)
	{
		if (_printIndexPrompt() == false)
			return (false);
	}
	_contact_tab[index].printInfos();
	return (true);
}