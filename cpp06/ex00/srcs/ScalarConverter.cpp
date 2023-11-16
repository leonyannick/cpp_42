#include "ScalarConverter.hpp"

// static bool isValidFloat(const std::string& str, float *f) {
// 	std::istringstream iss(str);
// 	iss >> std::noskipws >> *f;  // Try to read the float without skipping whitespaces
// 	// Check if the entire string was consumed and the stream is in a good state
// 	return iss.eof() && !iss.fail();
// }

// static bool isValidInt(const std::string& str, int *i) {
// 	std::istringstream iss(str);
// 	iss >> std::noskipws >> *i;  // Try to read the float without skipping whitespaces
// 	// Check if the entire string was consumed and the stream is in a good state
// 	return iss.eof() && !iss.fail();
// }

// static bool isValidDouble(const std::string& str, double *d) {
// 	std::istringstream iss(str);
// 	iss >> std::noskipws >> *d;  // Try to read the float without skipping whitespaces
// 	// Check if the entire string was consumed and the stream is in a good state
// 	if (iss.eof() && !iss.fail())
// 		return (true);
// 	if (str[iss.tellg()] == 'f' && iss.tellg() == (str.size() - 1))
// 		return (true);
// 	return (false);
// }

// static bool isValidChar(const std::string& str, char* c) {
// 	std::istringstream iss(str);
// 	if (str.size() == 1 && std::isprint(str[0]) && !std::isdigit(str[0])) {
// 		iss >> std::noskipws >> *c;
// 		return (true);
// 	}
// 	return (false);
// }

// static void	displayConversion(char c) {
// 	std::cout << "char: ";
// 	if (!std::isprint(c))
// 		std::cout << "Non displayable" << std::endl;
// 	else
// 		std::cout << c << std::endl;
// 	std::cout << "int: " << static_cast<int>(c) << std::endl;
// 	std::cout << "float: " << static_cast<float>(c) << std::endl;
// 	std::cout << "double: " << static_cast<double>(c) << std::endl;
// }

// static void	displayConversion(int i) {
// 	char c = static_cast<char>(i);
// 	std::cout << "char: ";
// 	if (i > CHAR_MAX && i < CHAR_MIN && !std::isprint(c))
// 		std::cout << "Non displayable" << std::endl;
// 	else
// 		std::cout << c << std::endl;
// 	std::cout << "int: " << i << std::endl;
// 	std::cout << "float: " << static_cast<float>(i) << std::endl;
// 	std::cout << "double: " << static_cast<double>(i) << std::endl;
// }

// static void	displayConversion(float f) {
// 	char c = static_cast<char>(f);
// 	int i = static_cast<int>(f);
// 	double d = static_cast<double>(f);
// 	std::cout << "char: ";
// 	if (i > CHAR_MAX && i < CHAR_MIN && !std::isprint(c))
// 		std::cout << "Non displayable" << std::endl;
// 	else
// 		std::cout << c << std::endl;
// 	std::cout << "int: ";
// 	if (i > INT_MAX && i < INT_MIN)
// 		std::cout << "impossible" << std::endl;
// 	else
// 		std::cout << c << std::endl;
// 	std::cout << "float: " << f << std::endl;
// 	std::cout << "double: " << static_cast<double>(f) << std::endl;
// }

void	ScalarConverter::displayConversion(double d) {
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);
	std::cout << "char: ";
	if (std::isnan(d) || d > CHAR_MAX || d < CHAR_MIN)
		std::cout << "impossible" << std::endl;
	else {
		if (!std::isprint(c))
			std::cout << "Non displayable" <<std::endl;
		else
			std::cout << "'" << c << "'" << std::endl;
	}
	std::cout << "int: ";
	if (std::isnan(d) || d > INT_MAX || d < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;
	std::cout << "float: ";
	if (!std::isinf(d) && (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << d << std::endl;
}

void	ScalarConverter::convert(std::string literal) {
	double	d;
	char *endptr;
	if (literal == "nan" || literal == "nanf")
		d = std::numeric_limits<double>::quiet_NaN();
	else if (literal == "inf" || literal == "inff")
		d = std::numeric_limits<double>::infinity();
	else if (literal == "-inf" || literal == "-inff")
		d = -std::numeric_limits<double>::infinity();
	else {
		if (literal.back() == 'f')
		literal.pop_back();
		d = std::strtod(literal.c_str(), &endptr);
		if (*endptr != '\0') {
			std::cerr << "Conversion failed. Not all characters were converted." << std::endl;
			return ;
		}
	}
	ScalarConverter::displayConversion(d);
}
