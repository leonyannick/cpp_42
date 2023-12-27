#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>


class BitcoinExchange
{
public:
	// public methods
	int	loadDatabase(const std::string& filename);

	//Getters and Setters

	// Constructors, Assignment, Destructors
	BitcoinExchange(void);
	~BitcoinExchange(void);
	

private:
	void	_printExchangeRates() const;

	BitcoinExchange& operator=(const BitcoinExchange& other);
	BitcoinExchange(const BitcoinExchange& copy);
	
	std::map<std::string, float>	_exchangeRates;
};

std::ostream &		operator<<(std::ostream & o, BitcoinExchange const & i);

#endif