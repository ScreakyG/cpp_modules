#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		bool	addContact(void);
		bool	printSearch(void);

	private:
		Contact	_contact_tab[8];
		int		_nbContact;
		void	_printHeader();
		void	_printBookContacts(std::string str, bool seperator);
		bool	_printIndexPrompt(void);
};

#endif