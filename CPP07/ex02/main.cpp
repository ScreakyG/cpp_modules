#include "Array.hpp"

int main(void)
{
	Array<char> str(5);
	str[0] = 'S';
	str[1] = 'a';
	str[2] = 'l';
	str[3] = 'u';
	str[4] = 't';
	try
	{
		str[5] = '\0';
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}

	for (unsigned int idx = 0; idx < str.size(); idx++)
	{
		std::cout << str[idx] << std::endl;
	}

}
