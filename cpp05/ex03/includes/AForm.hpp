#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm
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
	class NotSignedException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

	// public methods
	void			beSigned(Bureaucrat& b) throw (GradeTooLowException);
	void			execute(Bureaucrat const & executor) const
		throw (GradeTooLowException, NotSignedException);
	virtual void	action() const = 0;


	//Getters and Setters
	std::string getName() const;
	bool	getSignStatus() const;
	int	getGradeSign() const;
	int	getGradeExec() const;

	// Constructors, Assignment, Destructors
	AForm(std::string name, int gradeSign, int gradeExec) throw (std::exception);
	AForm(const AForm& copy);
	virtual ~AForm(void);

private:
	//Data
	const std::string _name;
	bool _isSigned;
	const int _gradeSign;
	const int _gradeExec;

	//hide from user
	AForm(void);
	AForm& operator=(const AForm& other);
};

std::ostream &		operator<<(std::ostream & o, AForm const & i);

#endif