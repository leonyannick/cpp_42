#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "easyfind.hpp"
#include <algorithm>
#include <list>



int	main(void) {
	std::list<int> intList;
	std::list<int>::iterator it;

	intList.push_back(5);
	intList.push_back(7);
	intList.push_back(11);
	intList.push_back(13);
	intList.push_back(17);

	it = easyfind(intList, 21);
	
	
	it = easyfind(intList, 13);
	std::cout << "element in list" << std::endl;
	std::cout << *it << std::endl;
	std::cout << "index: " <<  std::distance(intList.begin(), it) << std::endl;



	// std::cout << *it << std::endl;
	

	
	
	return (EXIT_SUCCESS);
}


