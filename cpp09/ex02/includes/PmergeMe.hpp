#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <utility>
#include <cmath>

#include "LogMsg.hpp"

const int jacobsthalIndeces[] =
	{2, 4, 10, 20, 42, 84, 170, 340, 682, 1364, 2730,
	5460, 10922, 21844, 43690, 87380, 174762, 349524, 699050};

class PmergeMe
{
public:
	// public methods

	//Getters and Setters

	// Constructors, Assignment, Destructors
	PmergeMe(void);

	int	vecFill(int argc, char *argv[]);
	// void	vecPrintPair(std::vector<std::pair<int, int> > &vec) const;
	// void	vecPrint(std::vector<int> &vec) const;
	void	vecPairwiseComparison();
	void	sortPairs(std::size_t itSize);
	void	mergeSort();
	void	createChains();
	void	insertion();
	
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe(void);

private:
	// Data
	std::vector<int>	_vector;
	int					_stray;
	std::vector<std::pair<int, int> > _pairs;
	std::vector<int>	_mainchain;
	std::vector<int>	_pend;
	std::size_t			_itSize;
};

std::ostream &		operator<<(std::ostream & o, PmergeMe const & i);

#endif