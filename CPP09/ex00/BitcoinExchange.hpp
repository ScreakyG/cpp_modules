#pragma once

#include <iostream>
#include <exception>
#include <fstream>
#include <map>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include <iomanip>
#include <cstdio>

#include <sstream>

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

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
