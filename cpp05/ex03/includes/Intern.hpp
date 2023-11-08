#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	class FormNotExisting : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	// public methods
	AForm	*makeForm(std::string formName, std::string target) const
		throw (FormNotExisting);
	//Getters and Setters

	// Constructors, Assignment, Destructors
	Intern(void);
	~Intern(void);
	
private:
	// Data
	
	Intern(const Intern& copy);
	Intern& operator=(const Intern& other);
};

#endif