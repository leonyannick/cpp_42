#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

// class elementNotFoundException : std::exception
// {
// 	public:
// 		const char *what() const throw() {return ("Element not found in Container");};
// };


//i am not throwing an error, im using the convention from find and return container.end() in case the element is not found
template<typename T>
typename T::iterator	easyfind(T& container, int toFind) {
	typename T::iterator it;
	it = find(container.begin(), container.end(), toFind);
	if (it == container.end())
		std::cout << "element not in container, returning c.end()" << std::endl;
	return (it);
}

#endif