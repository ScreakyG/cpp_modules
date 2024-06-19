#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		BitcoinExchange::ImportDataBase(argv[1]);
	}
	else
		std::cout << "Usage : ./btc 'input.txt'" << std::endl;
}
