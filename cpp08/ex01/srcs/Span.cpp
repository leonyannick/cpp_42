#include "Span.hpp"

/*------------------PUBLIC METHODS -----------------*/

template<typename T>
void	print(const T & t) {
	std::cout << t << std::endl;
}


void	Span::addNumber(int nb) throw (SpanFullException) {
	if (_count < _max) {
		_numbers.push_back(nb);
		++_count;
	}
	else
		std::cout << "full" << std::endl;
}

int		Span::shortestSpan() const {
	std::list<int> differences(_numbers.size());
	std::adjacent_difference(_numbers.begin(), _numbers.end(), differences.begin());
	std::for_each(differences.begin(), differences.end(), print<int>);
	std::cout << std::endl;
	return (abs(*std::min_element(differences.begin(), differences.end())));
}

int		Span::longestSpan() const {
	std::list<int>::iterator	it;
	std::list<int> differences(_numbers.size());
	std::adjacent_difference(_numbers.begin(), _numbers.end(), differences.begin());
	it = std::max_element(differences.begin(), differences.end());
	//std::cout << "dist: " << std::distance(differences.begin(), it) << std::endl;
	std::for_each(differences.begin(), differences.end(), print<int>);
	std::cout << std::endl;
	return (abs(*it));
}

/*----------------GETTERS AND SETTERS --------------*/

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

Span::Span(unsigned int n) : _max(n), _count(0) {}

Span::Span(const Span& src)
{
	(void)src;
//assign attributes
//or use definition from copy assignment operator
// *this = src;
}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
		{
		//copying of member attributes here
		}
	return (*this);
}

Span::~Span(void)
{}
