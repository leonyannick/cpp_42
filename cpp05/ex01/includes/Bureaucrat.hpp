#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
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
	void	incrementGrade() throw(GradeTooHighException);
	void	decrementGrade() throw(GradeTooLowException);

	//Getters and Setters
	std::string	getName() const;
	int			getGrade() const;

	// Constructors, Assignment, Destructors
	Bureaucrat(std::string name, int grade) throw (std::exception);
	Bureaucrat(const Bureaucrat& copy);
	~Bureaucrat(void);


private:
	//leaving the copy assignment private because of const string _name
	Bureaucrat& operator=(const Bureaucrat& other);
	Bureaucrat(void);
	const std::string _name;
	int	_grade;
};

std::ostream &		operator<<(std::ostream & o, Bureaucrat const & i);

#endif