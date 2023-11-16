#include "ScalarConverter.hpp"

/**
 * we static cast the our double number d to the remaining types: char, int, float
 * and check wether the conversion would make sense before actually displaying the
 * casted number
*/
void	ScalarConverter::displayConversion(double d) {
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	//char
	std::cout << "char: ";
	if (std::isnan(d) || d > CHAR_MAX || d < CHAR_MIN)
		std::cout << "impossible" << std::endl;
	else {
		if (!std::isprint(c))
			std::cout << "Non displayable" <<std::endl;
		else
			std::cout << "'" << c << "'" << std::endl;
	}

	//int
	std::cout << "int: ";
	if (std::isnan(d) || d > INT_MAX || d < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;

	//float
	std::cout << "float: ";
	if (!std::isinf(d) && (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max() || std::isnan(d)))
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;

	//double
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

/**
 * pop the f in the back of literal, so strtod has no problem with the conversion
*/
void	ScalarConverter::convert(std::string literal) {
	double	d;
	char *endptr;
	if (literal == "nan")
		d = std::numeric_limits<double>::quiet_NaN();
	else if (literal == "+inf" || literal == "+inff")
		d = std::numeric_limits<double>::infinity();
	else if (literal == "-inf" || literal == "-inff")
		d = -std::numeric_limits<double>::infinity();
	else {
		if (literal.back() == 'f')
			literal.pop_back();
		d = std::strtod(literal.c_str(), &endptr);
		if (*endptr != '\0') {
			std::cerr << "Conversion failed." << std::endl;
			return ;
		}
	}
	ScalarConverter::displayConversion(d);
}
