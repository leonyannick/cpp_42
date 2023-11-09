#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<class T>
class Array
{
public:
	// public methods
	size_t	size() const;
	//Getters and Setters

	// Constructors, Assignment, Destructors
	Array(void);
	Array(size_t n);
	
	Array(const Array& copy);
	Array& operator=(const Array& other);
	const T& operator[](size_t idx);

	~Array(void);

private:
	// Data
	size_t	_nElements;
};

//#include "Array.tpp"

#endif