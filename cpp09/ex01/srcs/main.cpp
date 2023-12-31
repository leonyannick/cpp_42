#include "RPN.hpp"

int	main(int argc, char* argv[]) {
	RPN	calculator;

	if (argc != 2)
		return (EXIT_SUCCESS);
	
	std::string input(argv[1]);
	if (calculator.parseInput(input) == -1) {
		std::cout << "Error" << std::endl;
		return (EXIT_FAILURE);
	}

	calculator.printTop();
	return (EXIT_SUCCESS);
}
