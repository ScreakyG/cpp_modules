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

	std::getline(file, line);
	while (std::getline(file, line))
	{
		keyValue = line.substr(0, line.find(","));
		mappedValue = line.substr(line.find(",") + 1);
		dataBase.insert(std::pair<std::string, float>(keyValue, std::atof(mappedValue.c_str())));
	}

	std::map<std::string, float>::iterator it;
	for (it = dataBase.begin(); it != dataBase.end(); it++)
		std::cout << it->first << " " << it->second <<  std::endl;

	return dataBase;

}

void	BitcoinExchange::ImportDataBase(void)
{
	std::ifstream	myfile;
	std::string		line;

	std::map<std::string, float>	dataBase;

	try
	{
		myfile.open("data.csv");
		if (myfile.is_open())
		{
			// while (std::getline(myfile, line))
			// 	std::cout << line << "\n";
			dataBase = importValues(myfile);
			myfile.close();
		}
		else
			throw std::runtime_error(std::strerror(errno));
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
