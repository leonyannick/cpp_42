#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form
{
public:
	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

	// public methods
	void	beSigned(Bureaucrat& b) throw (GradeTooLowException);
	void	signForm() const;

	//Getters and Setters
	std::string getName() const;
	bool	getSignStatus() const;
	int	getGradeSign() const;
	int	getGradeExec() const;

	// Constructors, Assignment, Destructors
	Form(std::string name, int gradeSign, int gradeExec) throw (std::exception);
	Form(const Form& copy);
	~Form(void);

private:
	//Data
	const std::string _name;
	std::string _signedBy;
	bool _isSigned;
	const int _gradeSign;
	const int _gradeExec;

	//hide from user
	Form(void);
	Form& operator=(const Form& other);
};

std::ostream &		operator<<(std::ostream & o, Form const & i);

#endif