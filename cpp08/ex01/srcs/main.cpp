#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "Span.hpp"
#include <ctime>



int	main(void) {
	Span span1(10);

	//generate random numbers
	std::srand(std::time(NULL));

	for (size_t i = 0; i < 10; i++) {
		if (i == 5)
			span1.addNumber(5);
		else
			span1.addNumber(12);
	}
	



	std::cout  << span1.shortestSpan() << std::endl;
	std::cout << std::endl;
	std::cout  << span1.longestSpan() << std::endl;


	// std::cout << *it << std::endl;
	

	
	
	return (EXIT_SUCCESS);
}


