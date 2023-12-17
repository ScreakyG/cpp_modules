#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <iostream>

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		bool	fillContact(void);

	private:
		std::string _FirstName;
		std::string _LastName;
		std::string _Nickname;
		std::string	_PhoneNumber;
};

#endif
