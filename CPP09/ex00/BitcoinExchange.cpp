#include "BitcoinExchange.hpp"
#include <limits>

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

static std::string trim(const std::string& str,
                 const std::string& whitespace)
{
    const std::string::size_type strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return "";

    const std::string::size_type strEnd = str.find_last_not_of(whitespace);
    const std::string::size_type strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

static void verifyValue(std::string &value)
{
	double	valueDouble;
	char	*endptr;

	if (value.empty())
		throw std::runtime_error("invalid value => no value.");
	valueDouble = std::strtod(value.c_str(), &endptr);
	if (*endptr != '\0')
		throw std::runtime_error("invalid value => " + value);
	if (valueDouble < 0)
		throw std::runtime_error("not a positive number.");
	if (valueDouble > 1000)
		throw std::runtime_error("too large a number.");
}

static bool isBissextileYear(int &year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return (true);
    return (false);
}

static void verifyDateFormat(std::string &date)
{
    std::string year;
    std::string month;
    std::string day;
    size_t      found;
    size_t      old_found;

    if (date.empty())
        throw std::runtime_error("invalid date => " + date);
    if (date.size() != 10)
        throw std::runtime_error("invalid date => (not YYYY-MM-DD format) " + date);
    found = date.find('-');
    year = date.substr(0, found);
    if (year.size() != 4)
        throw std::runtime_error("invalid date => (wrong year format) " + date);
    old_found = found;
    found = date.find('-', found + 1);
    month = date.substr(old_found + 1, found - old_found - 1);
    if (month.size() != 2)
        throw std::runtime_error("invalid date => (wrong month format) " + date);
    day = date.substr(found + 1);
    if (day.size() != 2)
        throw std::runtime_error("invalid date => (wrong day format) " + date);
}

static void verifyDate(std::string &date, std::map<std::string, float> &map)
{
	// std::tm				tm = {};
	// std::tm				tmDatabase = {};
	// std::istringstream	ss(date);
	// std::istringstream	ssDatabase(map.begin()->first);

	// ss >> std::get_time(&tm, "%Y-%m-%d");
	// if (ss.fail() || !ss.eof())
	// 	throw std::runtime_error("invalid date => " + date);
	// //std::cout << tm.tm_year + 1900 << " / " << tm.tm_mon + 1 << " / " << tm.tm_mday << std::endl;

	// ss >> std::get_time(&tmDatabase, "%Y-%m-%d");
	// if (tm.tm_year + 1900 < tmDatabase.tm_year + 1900)
	// 	throw std::runtime_error("no reference found, date too old");

    int	year, month, day;
	int	lowestDate = 0;

    if (map.empty() == false)
	    std::sscanf(map.begin()->first.c_str(), "%d", &lowestDate);
	if (std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) == 3)
	{
        verifyDateFormat(date);
        if (year > 5000)
            throw std::runtime_error("invalid date => "+ date + " (out of range)");
		if (month < 1 || month > 12)
			throw std::runtime_error("invalid date => " + date);
		if (day < 1 || day > 31)
			throw std::runtime_error("invalid date => " + date);
        //Check if month is 30 or 31 days.
        if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
            throw std::runtime_error("invalid date => " + date);
        if (month == 2)
        {
            if (isBissextileYear(year) == true && day > 29)
                throw std::runtime_error("invalid date => " + date);
            else if (isBissextileYear(year) == false && day > 28)
                throw std::runtime_error("invalid date => " + date);
        }
		if (year < lowestDate)
			throw std::runtime_error("no reference found, date too old");
	}
	else
		throw std::runtime_error("invalid date => " + date);
}

static void addDatabase(std::map<std::string, float> &dataBase, std::string &line)
{
    size_t  find;
    std::map<std::string, float> dummyDb;
    std::string keyValue;
    std::string mappedValue;
    float       mappedValueConverted;
    char        *endptr = NULL;

    find = line.find(',');
    if (find == std::string::npos)
        throw std::runtime_error("wrong format =>  " + line);
    keyValue = line.substr(0, find);
    verifyDate(keyValue, dummyDb);
    if (find + 1 >= line.size())
        throw std::runtime_error("no value =>  " + line);
    mappedValue = line.substr(find + 1);
    mappedValueConverted = std::strtof(mappedValue.c_str(), &endptr);
    if (*endptr != '\0' || mappedValueConverted > 10000000 || mappedValueConverted < 0)
        throw std::runtime_error("value is not valid =>  " + line);
    dataBase[keyValue] = mappedValueConverted;
}

static std::map<std::string, float> importValues(std::ifstream &file)
{
	std::map<std::string, float>	dataBase;
	std::string line;

	while (std::getline(file, line))
	{
		if (line == "date,exchange_rate" || line.empty())
			continue;
        try
        {
            addDatabase(dataBase, line);
        }
	    catch (std::exception &e)
	    {
		    std::cout << RED <<  "[Database]" << " : " << e.what() << RESET << std::endl;
	    }
	}

	// std::map<std::string, float>::iterator it;
	// for (it = dataBase.begin(); it != dataBase.end(); it++)
	// 	std::cout << it->first << " " << it->second <<  std::endl;

    if (dataBase.empty() == true)
    {
        file.close();
        throw std::runtime_error("Database is empty");
    }
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
	else // Find closest date.
	{
		it = dataBase.upper_bound(date);
		if (it == dataBase.begin())
			throw std::runtime_error("no reference found, date too old");
		it--;
        // std::cout << BLUE"Reference date = " RESET << it->first << std::endl;
		std::cout << date << " => " << bitcoinAmount << " = " << it->second * bitcoinAmount << std::endl;
	}
}

static void	getDateAndValue(std::string &date, std::string &value, std::string &line, std::map<std::string, float> &dataBase)
{
	std::size_t	found = line.find("|");
	if (found == std::string::npos)
		throw std::runtime_error("bad input, missing '|' => " + line);
	else
	{
		date = line.substr(0, found);
		date = trim(date, " \t\r\v\f");
		verifyDate(date, dataBase);

		if (found + 1 >= line.size())
			throw std::runtime_error("invalid value => no value.");
		value = line.substr(found + 1);
		value = trim(value, " \t\r\v\f");
		verifyValue(value);
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
	inputFile.open(inputPath.c_str());
	if (inputFile.is_open())
	{
		std::cout << GREEN"Input File found = "<< inputPath << RESET << std::endl;
		while (std::getline(inputFile, line))
		{
			if (line == "date | value" || line.empty())
				continue;
			try
			{
				getDateAndValue(date, value, line, dataBase);
				printConversion(dataBase, date, value);
			}
			catch (const std::exception &e)
			{
				std::cout << "Error" << " : " << e.what() << std::endl;
			}
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

    if (!input)
    {
        std::cerr << "Error with input file\n" << std::endl;
        return ;
    }
	try
	{
		dataBaseCsv.open("data.csv");
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
		std::cout << RED <<  "Error" << " : " << e.what() << RESET << std::endl;
	}
}
