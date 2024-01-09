#include "PmergeMe.hpp"

int	main(int argc, char* argv[]) {
	PmergeMe	fordJohnson;

	if (argc == 1) {
		std::cout << "Error: program needs list of positive integers to sort" << std::endl;
		return (EXIT_FAILURE);
	}

	if (fordJohnson.vecFill(argc, argv) == -1) {
		std::cout << "Error: filling vector failed" << std::endl;
		return (EXIT_FAILURE);
	}
	
	fordJohnson.vecPrint();
	fordJohnson.vecPairwiseComparison();
	fordJohnson.vecPrint();
	return (EXIT_SUCCESS);
}
