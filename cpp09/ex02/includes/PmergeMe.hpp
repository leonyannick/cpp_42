#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <numeric>
#include <algorithm>
#include <utility>

class PmergeMe
{
public:
	// public methods

	//Getters and Setters

	// Constructors, Assignment, Destructors
	PmergeMe(void);

	int	vecFill(int argc, char *argv[]);
	void	vecPrint() const;
	void	vecPairwiseComparison();
	
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe(void);

private:
	// Data
	std::vector<int>	_vector;
};

std::ostream &		operator<<(std::ostream & o, PmergeMe const & i);

#endif