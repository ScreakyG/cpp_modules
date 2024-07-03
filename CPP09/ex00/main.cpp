#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		BitcoinExchange::ImportDataBase(argv[1]);
	}
	else
		std::cout << RED "Usage : ./btc 'input.txt'" RESET << std::endl;
}
