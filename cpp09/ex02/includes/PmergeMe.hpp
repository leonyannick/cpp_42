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
#include <iomanip>
#include <deque>

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

	int	fillContainers(int argc, char *argv[]);


	// void	sortPairs(std::size_t itSize);
	void	FJvec();
	void	FJdeq();

	void	insertion();
	void	displayRuntime() const;
	
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe(void);

private:
	// Vector
	std::vector<int>					_vector;
	std::vector<std::pair<int, int> >	_pairsVec;
	std::vector<int>					_mainchainVec;
	std::vector<int>					_pendVec;

	// Deque
	std::deque<int>						_deque;
	std::deque<std::pair<int, int> >	_pairsDeq;
	std::deque<int>						_mainchainDeq;
	std::deque<int>						_pendDeq;

	int					_stray;


	clock_t		_startTimeVec;
	clock_t		_endTimeVec;
	clock_t		_startTimeDeq;
	clock_t		_endTimeDeq;

	// Ford-Johnson utility
	template <typename C, typename C_pair>
	void	_PairwiseComparison(C& arr, C_pair& arr_pair);

	template <typename C_pair, typename T, typename U>
	void	_createChains(C_pair& arr_pair, T& mainchain, U& pend);

	template <typename T, typename U>
	void	_insertion(T& mainchain, U& pend);
	// std::size_t			_itSize;
};

std::ostream &		operator<<(std::ostream & o, PmergeMe const & i);

#endif