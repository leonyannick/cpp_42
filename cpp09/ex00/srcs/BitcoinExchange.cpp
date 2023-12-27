#include "BitcoinExchange.hpp"

/*------------------PUBLIC METHODS -----------------*/

int	BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream	inputFile(filename);
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
	_printExchangeRates();
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


