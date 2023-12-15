#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <iostream>

class Contact
{
	public:
		Contact(void);
		~Contact(void);
	private:
		std::string FirstName;
		std::string LastName;
		std::string Nickname;
		std::string	PhoneNumber;
};

#endif
