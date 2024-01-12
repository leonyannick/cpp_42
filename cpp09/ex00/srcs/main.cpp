#include "BitcoinExchange.hpp"
#include <cstdlib>

#define DB_FILE "data.csv"

/** EXAMPLE INPUT.TXT
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
2009-01-01 | 1
2009-01-02 | 1
*/


int	main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Error: not enough parameters to run program." << std::endl;
		return (EXIT_FAILURE);
	}

	BitcoinExchange	be;

	if (be.loadDatabase(DB_FILE) == -1) {
		std::cout << "Error: loading Database failed." << std::endl;
		return (EXIT_FAILURE);
	}
	
	const std::string input_file(argv[1]);
	if (be.calculateValue(input_file) == -1) {
		std::cout << "Error: error while calculating." << std::endl;
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
