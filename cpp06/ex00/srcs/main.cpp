#include "ScalarConverter.hpp"

int	main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Correct usage: ./converter <literal to convert>" << std::endl;
		return (EXIT_SUCCESS);
	}
	ScalarConverter::convert(argv[1]);
	return (EXIT_SUCCESS);
}
