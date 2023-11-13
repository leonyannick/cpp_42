#include "Span.hpp"

/*------------------PUBLIC METHODS -----------------*/

template<typename T>
void	print(const T & t) {
	std::cout << t << std::endl;
}


void	Span::addNumber(int nb) throw (Span::SpanFullException) {
	if (_numbers.size() < _max)
		_numbers.push_back(nb);
	else
		throw (Span::SpanFullException());
}

void	Span::addNumbers(std::vector<int>::const_iterator begin,
		std::vector<int>::const_iterator end) throw (Span::SpanFullException) {
			int	nElements = end - begin;
			if ((nElements + this->_numbers.size()) <= this->_max)
				this->_numbers.insert(_numbers.begin(), begin, end);
			else
				throw (Span::SpanFullException());
			// std::for_each(_numbers.begin(), _numbers.end(), print<int>);
		}

/**
 * small helper function to change the actual value of the variable passed
 * to the absolute value so we can change all the values in a the vector
 * to the absolute value with for_each
*/
static void	abs_ref(int& x) {
	x = abs(x);
}

/**
 * calculate the adjacent_differences between all the adjacent values
 * in the vector
 * calculate their absolute value because: v(5, 1, 5) -> adjacent difference would be:
 * diff(5, -4, 4)
 * -> this also explains why we beginn with the second element when searching the min/max element
 * because first difference calulated is always between 0 and first element in array
*/
int		Span::shortestSpan() const {
	std::vector<int> differences(_numbers.size());
	std::adjacent_difference(_numbers.begin(), _numbers.end(), differences.begin());
	std::for_each(differences.begin(), differences.end(), abs_ref);
	// std::for_each(differences.begin() + 1, differences.end(), print<int>);
	return (*std::min_element(differences.begin() + 1, differences.end()));
}

/**
 * here we can print out index of biggest difference to confirm we chose the correct
 * distance
*/
int		Span::longestSpan() const {
	std::vector<int>::iterator	it;
	std::vector<int> differences(_numbers.size());
	std::adjacent_difference(_numbers.begin(), _numbers.end(), differences.begin());
	std::for_each(differences.begin(), differences.end(), abs_ref);
	it = std::max_element(differences.begin() + 1, differences.end());
	// std::cout << "dist: " << std::distance(differences.begin(), it) << std::endl;
	// std::cout << std::endl;
	return (*it);
}

/*----------------GETTERS AND SETTERS --------------*/

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

Span::Span(unsigned int n) : _max(n) {
	_numbers.reserve(n);
}

Span::Span(const Span& src) : _max(src._max)
{
	_numbers.reserve(_max);
	_numbers = src._numbers;
}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
		{
			_numbers = rhs._numbers;
		}
	return (*this);
}

Span::~Span(void)
{}

