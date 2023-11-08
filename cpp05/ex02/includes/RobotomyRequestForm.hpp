#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	// public methods
	void	action() const;

	//Getters and Setters

	// Constructors, Assignment, Destructors
	RobotomyRequestForm(std::string target);
	
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	~RobotomyRequestForm(void);

private:
	std::string	_target;

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	RobotomyRequestForm(void);
	// Data
};

std::ostream &		operator<<(std::ostream & o, RobotomyRequestForm const & i);

#endif