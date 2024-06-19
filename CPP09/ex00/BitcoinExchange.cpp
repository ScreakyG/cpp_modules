#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {};
BitcoinExchange::~BitcoinExchange(void) {};
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	(void)src;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	(void)rhs;
	return (*this);
}

static std::map<std::string, float> importValues(std::ifstream &file)
{
	std::map<std::string, float>	dataBase;
	std::string	keyValue;
	std::string	mappedValue;
	std::string line;
	char		*endptr = NULL;

	while (std::getline(file, line))
	{
		if (line == "date,exchange_rate")
			continue;
		keyValue = line.substr(0, line.find(","));
		mappedValue = line.substr(line.find(",") + 1);
		dataBase[keyValue] = std::strtof(mappedValue.c_str(), &endptr);
		if (*endptr != '\0')
			std::cout << "Unvalind price detected" << std::endl;
	}

	// std::map<std::string, float>::iterator it;
	// for (it = dataBase.begin(); it != dataBase.end(); it++)
	// 	std::cout << it->first << " " << it->second <<  std::endl;

	return (dataBase);
}

static void	convert(std::map<std::string, float> &dataBase, char *input)
{
	std::string		inputPath;
	std::ifstream	inputFile;
	std::string		line;
	std::string		keyValue;
	std::string		mappedValue;

	std::map<std::string, float>::iterator	it;

	inputPath = input;
	inputFile.open(inputPath);
	if (inputFile.is_open())
	{
		std::cout << "Input File found = "<< inputPath << std::endl;
		while (std::getline(inputFile, line))
		{
			if (line == "data | value")
				continue;
			keyValue = line.substr(0, line.find(" |"));
			mappedValue = line.substr(line.find("|") + 2);
			it = dataBase.find(keyValue);
			if (it != dataBase.end()) // A KEYVALUE WAS FOUND
				std::cout << keyValue << " => " << mappedValue << " = " << " ? " << std::endl;
			else
				std::cout << "Couldnt find a matching key" << std::endl;
		}
		inputFile.close();
	}
	else
		throw std::runtime_error(std::strerror(errno));
}

void	BitcoinExchange::ImportDataBase(char *input)
{
	std::ifstream	dataBaseCsv;
	std::ifstream	inputFile;
	std::string		line;

	std::map<std::string, float>	dataBase;

	try
	{
		dataBaseCsv.open("data_tests.csv");
		if (dataBaseCsv.is_open())
		{
			dataBase = importValues(dataBaseCsv);
			dataBaseCsv.close();
		}
		else
			throw std::runtime_error(std::strerror(errno));
		convert(dataBase, input);
	}

	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	(void)input;
}
