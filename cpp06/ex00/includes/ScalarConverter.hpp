#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <limits>

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