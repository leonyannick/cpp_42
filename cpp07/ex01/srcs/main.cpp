#include <cstdlib>
#include <iostream>
#include "iter.hpp"

template<typename T>
void	print(const T & t) {
	std::cout << t << std::endl;
}

int	main(void) {
	int intArr[5] = {3, 43, 3, 4, 5};

	iter(&intArr[0], 5, print<int>);

	return (EXIT_SUCCESS);
}
