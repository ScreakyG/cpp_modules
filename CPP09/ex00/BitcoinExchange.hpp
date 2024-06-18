#pragma once

#include <iostream>
#include <exception>
#include <fstream>
#include <map>

class BitcoinExchange
{
	public:
		~BitcoinExchange();
		static void ImportDataBase(void);
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange& operator=(const BitcoinExchange &rhs);

};
