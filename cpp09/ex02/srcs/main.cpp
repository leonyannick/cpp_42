#include "PmergeMe.hpp"

// static void	generateJacobsthalNums() {
// 	double n;
	
// 	for (size_t i = 0; i < 30; i++)
// 	{
// 		n = (std::pow(2, i + 1) + std::pow(-1, i)) / 3;

// 		//subtract 1 to have indeces
// 		std::cout << n - 1 << ", ";
// 	}
	
// }

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
	
	fordJohnson.vecPairwiseComparison();
	fordJohnson.mergeSort();
	fordJohnson.createChains();
	fordJohnson.insertion();
	return (EXIT_SUCCESS);
}
