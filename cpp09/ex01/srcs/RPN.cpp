#include "RPN.hpp"

static bool	isValidOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

/*------------------PUBLIC METHODS -----------------*/

int	RPN::parseInput(std::string& input) {
	std::istringstream ss(input);
	std::string token;

	while(std::getline(ss, token, ' ')) {
		if (token.length() != 1) {
			std::cout << "invalid token length" << std::endl;
			return (-1);
		}
		if (!(isValidOperator(token[0]) || std::isdigit(token[0]))) {
			std::cout << "invalid token" << std::endl;
			return (-1);
		}

		// std::cout << "Token: " << token << std::endl;
		if (processToken(token[0]) == -1)
			return (-1);
		// printTop();
	}
	return (0);
}

/**
 * c is either a operator or a digit
*/
int	RPN::processToken(char c) {
	if (std::isdigit(c)) {
		_numbers.push(c - '0');
	} else if (_numbers.size() >= 2) {
		//apply operation
		applyOperation(c);
	} else {
		std::cout << "invalid move" << std::endl;
		return (-1);
	}
	return (0);
}

void	RPN::applyOperation(char op) {
	int rightNum;
	int leftNum;
	int result;

	rightNum = _numbers.top();
	_numbers.pop();
	leftNum = _numbers.top();
	_numbers.pop();

	if (op == '+')
		result = leftNum + rightNum;
	else if (op == '-')
		result = leftNum - rightNum;
	else if (op == '*')
		result = leftNum * rightNum;
	else if (op == '/')
		result = leftNum / rightNum;
	
	_numbers.push(result);
}

void	RPN::printTop() const {
	if (_numbers.size() != 1)
		std::cout << "Error: wrong stack size due to invalid operation" << std::endl;
	else
		std::cout << _numbers.top() << std::endl;
}

/*----------------GETTERS AND SETTERS --------------*/

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

RPN::RPN(void)
{}

// RPN::RPN(const RPN& src)
// {
// //assign attributes
// //or use definition from copy assignment operator
// // *this = src;
// }

// RPN &RPN::operator=(RPN const &rhs)
// {
// 	if (this != &rhs)
// 		{
// 		//copying of member attributes here
// 		}
// 	return (*this);
// }

RPN::~RPN(void)
{}

// /*----------------OPERATOR OVERLOAD---------------*/

// std::ostream &operator<<(std::ostream &o, RPN const &i)
// {
// 	//o << <fill ostream with attributes>
// 	return (o);
// }