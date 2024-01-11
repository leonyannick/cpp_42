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
	// public methods
	void	addNumber(int nb) throw (std::runtime_error);
	void	addNumbers(std::vector<int>::const_iterator begin,
		std::vector<int>::const_iterator end) throw (std::runtime_error);
	int		shortestSpan() const throw (std::runtime_error);
	int		longestSpan() const throw (std::runtime_error);

	void	printNumbers() const;

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
#endif