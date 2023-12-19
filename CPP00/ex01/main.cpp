#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook repertoire;
	std::string input;

	while (std::cout << "PhoneBook : " && std::getline(std::cin, input))
	{
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
		{
			if (repertoire.addContact() == false)
				break ;
		}
		else if (input == "SEARCH")
		{
			if (repertoire.printSearch() == false)
				break ;
		}
		else
			std::cout << "Command not found , use only ADD, SEARCH or EXIT" << std::endl;
	}
	return (0);
}
