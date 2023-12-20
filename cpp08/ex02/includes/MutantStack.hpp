#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	// public methods

	//Getters and Setters

	// Constructors, Assignment, Destructors
	MutantStack(void) : std::stack<T, Container>() {};
	
	MutantStack(const MutantStack& copy) {*this = copy;};

	MutantStack& operator=(const MutantStack& other) {
		std::stack<T, Container>::operator=(other);
		return *this;
	};

	~MutantStack(void) {};

	typedef typename Container::iterator iterator;
	
	//c is a member object of std::stack containing the underlaying container
	//MutantStacks begin and end member function call begin and end of the
	//underlaying container
	iterator	begin() {return this->c.begin();};
	iterator	end() {return this->c.end();};
};

// std::ostream &		operator<<(std::ostream & o, MutantStack const & i);

#endif