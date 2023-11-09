#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T, typename U>
void	iter(T* arr, size_t arrLen, U function) {
	for (size_t i = 0; i < arrLen; i++) {
		function(arr[i]);
	}
}

#endif