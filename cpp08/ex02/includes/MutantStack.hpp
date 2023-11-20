#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack< T, Container>
{
public:
	// public methods

	//Getters and Setters

	// Constructors, Assignment, Destructors
	MutantStack(void);
	
	MutantStack(const MutantStack& copy);
	MutantStack& operator=(const MutantStack& other);
	~MutantStack(void);

	
};

std::ostream &		operator<<(std::ostream & o, MutantStack const & i);

#endif