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

bool Contact::fill_infos(std::string msg)
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
		if (fill_infos(msg) == false)
			return (false);
	}
	return (true);

}

bool Contact::fillContact(void)
{
	if (fill_infos("First Name") == false)
		return (false);
	return (true);
}