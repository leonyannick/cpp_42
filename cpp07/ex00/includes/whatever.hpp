#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template < typename T >
void	swap(T& fst, T& scd) {
	T tmp = fst;
	fst = scd;
	scd = tmp;
}

template < typename T >
const T &	min(const T& fst, const T& scd) {
	if (scd <= fst)
		return (scd);
	return (fst);
}

template < typename T >
const T &	max(const T& fst, const T& scd) {
	if (scd >= fst)
		return (scd);
	return (fst);
}

#endif