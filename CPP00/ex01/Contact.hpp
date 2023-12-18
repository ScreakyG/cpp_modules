#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <iostream>

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		bool	fillContact(void);
		std::string getFirstName(void);

	private:
		std::string _FirstName;
		std::string _LastName;
		std::string _Nickname;
		std::string	_PhoneNumber;
		std::string _Secret;
		bool	fill_infos(std::string msg, std::string *variable);
};

#endif
