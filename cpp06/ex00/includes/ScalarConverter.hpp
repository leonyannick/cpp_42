#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits.h>
#include <sstream>
#include <cstring>
#include <iomanip>

class ScalarConverter
{
public:
	// public methods
	static void	convert(std::string literal);

private:
	static void	displayConversion(double d);
	ScalarConverter(void);
};

#endif