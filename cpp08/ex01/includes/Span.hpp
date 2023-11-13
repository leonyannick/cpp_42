#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <numeric>

class Span
{
public:
	class SpanFullException : std::exception
	{
		public:
			const char *what() const throw() {return ("Span is full");};
	};
	// public methods
	void	addNumber(int nb) throw (SpanFullException);
	void	addNumbers(std::vector<int>::const_iterator begin,
		std::vector<int>::const_iterator end) throw (SpanFullException);
	int		shortestSpan() const;
	int		longestSpan() const;

	//Getters and Setters

	// Constructors, Assignment, Destructors
	Span(unsigned int n);
	
	Span(const Span& copy);
	Span& operator=(const Span& other);
	~Span(void);

private:
	Span();
	// Data
	unsigned int _max;
	std::vector<int> _numbers;
};

std::ostream &		operator<<(std::ostream & o, Span const & i);

#endif