#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cctype>

class RPN
{
public:
	// public methods
	int	parseInput(std::string& input);
	int	processToken(char c);
	void	applyOperation(char op);
	void	printTop() const;

	//Getters and Setters

	// Constructors, Assignment, Destructors
	RPN(void);

	
	RPN(const RPN& copy);
	RPN& operator=(const RPN& other);
	~RPN(void);

private:
	// Data
	std::stack<int> _numbers;
};

std::ostream &		operator<<(std::ostream & o, RPN const & i);

#endif