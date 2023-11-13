#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <list>
#include <numeric>

class Span
{
public:
	class SpanFullException : std::exception
	{
		public:
			const char *what() const throw() {return ("Spann is full");};
	};
	// public methods
	void	addNumber(int nb) throw (SpanFullException);
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
	unsigned int _count;
	std::list<int> _numbers;
};

#endif