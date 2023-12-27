#include "BitcoinExchange.hpp"

#define DB_FILE "data.csv"



int	main(int argc, char* argv[]) {
	(void) argc;
	(void) argv;
	BitcoinExchange	be;

	be.loadDatabase(DB_FILE);
}