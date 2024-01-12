#include "BitcoinExchange.hpp"

/*------------------PUBLIC METHODS -----------------*/

int	BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream	inputFile(filename.c_str());
	std::string		line;

	if (!inputFile.is_open()) {
		std::cerr << "db open failed" << std::endl;
		return (-1);
	}

	//skip first line
	std::getline(inputFile, line);

	while (std::getline(inputFile, line)) {
		std::istringstream ss(line);
		float			exchangeRate;
		std::string		date;

		if (!std::getline(ss, date, ',')){
			std::cerr << "db parse date failed" << std::endl;
			return (-1);
		}

		if (!(ss >> exchangeRate)) {
			std::cerr << "db parse exchangeRate failed" << std::endl;
			return (-1);
		}
		
		_exchangeRates.insert(std::make_pair(date, exchangeRate));
	}

	inputFile.close();
	// _printExchangeRates();
	return (0);
}

static bool isValidDateFormat(const std::string& dateStr) {
    // Check if the length is correct
    if (!(dateStr.length() == 10 || dateStr.length() == 11))
        return false;

    // Check the position of hyphens
    if (dateStr[4] != '-' || dateStr[7] != '-')
        return false;

    // Extract year, month, and day parts
    std::string yearStr = dateStr.substr(0, 4);
    std::string monthStr = dateStr.substr(5, 2);
    std::string dayStr = dateStr.substr(8, 2);

    // Convert parts to integers
    int year, month, day;
    if (!(std::istringstream(yearStr) >> year) ||
        !(std::istringstream(monthStr) >> month) ||
        !(std::istringstream(dayStr) >> day)) {
        return false;
    }

    // Check the range of year, month, and day
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
	}


    return true;
}

int	BitcoinExchange::calculateValue(const std::string& filename) {
	std::ifstream	inputFile(filename.c_str());
	std::string		line;

	if (!inputFile.is_open()) {
		std::cerr << "input file opening failed" << std::endl;
		return (-1);
	}

	//skip first line
	std::getline(inputFile, line);

	while (std::getline(inputFile, line)) {
		std::istringstream ss(line);
		float			nbitcoins;
		float			value;
		std::string		date;

		if (!std::getline(ss, date, '|')){
			std::cerr << "db parse date failed" << std::endl;
			continue;
		}

		if (date[date.length() - 1] == ' ') //remove whitespace
			date.erase(date.end() - 1);

		if (!isValidDateFormat(date)) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		} 

		if (!(ss >> nbitcoins)) {
			std::cerr << "db parse exchangeRate failed" << std::endl;
			continue;
		}

		if (nbitcoins < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		} 

		if (nbitcoins >= 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		
		std::map<std::string, float>::const_iterator it;
		// it = _exchangeRates.find(date);
		// if (it == _exchangeRates.end()) {
		// 	it = _exchangeRates.lower_bound(date);
		// }
		it = _exchangeRates.upper_bound(date);

		

		if (it == _exchangeRates.begin() || it == _exchangeRates.end()) { //exact date found
			std::cerr << "err: no lower bound (date lays probably in the past before bitcoins)" << std::endl;
			continue;
		}

		it--;

		value = it->second * nbitcoins;
		// std::cout << "corr date: " << it->first << std::endl;

		std::cout << date << " => " << nbitcoins << " = " << value << std::endl;
	}

	inputFile.close();
	return (0);
}



/*----------------PRIVATE METHODS--------------*/

void	BitcoinExchange::_printExchangeRates() const {
	std::map<std::string, float>::const_iterator it;
    for (it = _exchangeRates.begin(); it != _exchangeRates.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << std::setprecision(7)
			<< it->second << std::endl;
    }
}

BitcoinExchange::BitcoinExchange(void)
{}

// BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
// {
// //assign attributes
// //or use definition from copy assignment operator
// // *this = src;
// }

// BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
// {
// 	if (this != &rhs)
// 		{
// 		//copying of member attributes here
// 		}
// 	return (*this);
// }

BitcoinExchange::~BitcoinExchange(void)
{}


