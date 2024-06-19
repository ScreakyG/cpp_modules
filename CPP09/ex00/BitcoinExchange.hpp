#pragma once

#include <iostream>
#include <exception>
#include <fstream>
#include <map>
#include <string>

class BitcoinExchange
{
	public:
		~BitcoinExchange();
		static void ImportDataBase(char *input);
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange& operator=(const BitcoinExchange &rhs);

};
