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
		if (line == "date,exchange_rate" || line.empty())
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

static void	printConversion(std::map<std::string, float> &dataBase,std::string &date, std::string &value)
{
	std::map<std::string, float>::iterator	it;
	float	bitcoinAmount;
	char	*endptr;

	bitcoinAmount = std::strtof(value.c_str(), &endptr);

	it = dataBase.find(date);
	if (it != dataBase.end())
		std::cout << date << " => " << bitcoinAmount << " = " << dataBase[date] * bitcoinAmount << std::endl;
	else // CHANGER POUR TROUVER LA DATE LA PLUS PROCHE
		return ;
		// getClosestDate()
		//std::cout << "Couldnt find a matching key" << std::endl;
}

static void	getDateAndValue(std::string &date, std::string &value, std::string &line)
{
	std::size_t	found = line.find("|");
	if (found == std::string::npos)
		std::cout << "Error: bad input => " << line << std::endl;
	else
	{
		date = line.substr(0, found - 1);
		// TRIM LES WHITESPACES
		// VERIFIER DATE VALIDE
		value = line.substr(found + 2);
		// TRIM LES WHITESPACES
		// VERIFIER VALUE
	}
}

static void	convert(std::map<std::string, float> &dataBase, char *input)
{
	std::string		inputPath;
	std::ifstream	inputFile;
	std::string		line;
	std::string		date;
	std::string		value;

	inputPath = input;
	inputFile.open(inputPath);
	if (inputFile.is_open())
	{
		std::cout << GREEN"Input File found = "<< inputPath << RESET << std::endl;
		while (std::getline(inputFile, line))
		{
			if (line == "date | value" || line.empty())
				continue;
			getDateAndValue(date, value, line);
			printConversion(dataBase, date, value);
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
		std::cerr << RED <<  "Error" << " : " << e.what() << RESET << std::endl;
	}
	(void)input;
}
