#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	// public methods
	void	action() const;


	//Getters and Setters

	// Constructors, Assignment, Destructors
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& copy);
	~PresidentialPardonForm(void);

private:
	// Data
	std::string _target;

	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	PresidentialPardonForm(void);
};

std::ostream &		operator<<(std::ostream & o, PresidentialPardonForm const & i);

#endif