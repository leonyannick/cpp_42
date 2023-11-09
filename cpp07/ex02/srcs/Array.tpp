#include "Array.hpp"

// template<class T>
// class array{};

/*------------------PUBLIC METHODS -----------------*/

/*----------------GETTERS AND SETTERS --------------*/

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

template<class T>
Array::Array(void)
{}

Array::Array(const Array& src)
{
//assign attributes
//or use definition from copy assignment operator
// *this = src;
}

Array &Array::operator=(Array const &rhs)
{
	if (this != &rhs)
		{
		//copying of member attributes here
		}
	return (*this);
}

Array::~Array(void)
{}

/*----------------OPERATOR OVERLOAD---------------*/

std::ostream &operator<<(std::ostream &o, Array const &i)
{
	//o << <fill ostream with attributes>
	return (o);
}