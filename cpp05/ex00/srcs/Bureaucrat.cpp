#include "Bureaucrat.hpp"

/*------------------PUBLIC METHODS -----------------*/

void Bureaucrat::incrementGrade() throw (GradeTooHighException) {
	if ((_grade - 1) < 1)
		throw (GradeTooHighException());
	--_grade;
}

void Bureaucrat::decrementGrade() throw (GradeTooLowException) {
	if ((_grade + 1) > 150)
		throw (GradeTooLowException());
	++_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Exception: Grade cannot be higher than 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Exception: Grade cannot be lower than 150");
}


/*----------------GETTERS AND SETTERS --------------*/

std::string	Bureaucrat::getName() const {return (_name);}

int Bureaucrat::getGrade() const {return (_grade);}

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

Bureaucrat::Bureaucrat(void)
{}

Bureaucrat::Bureaucrat(std::string name, int grade) throw (std::exception)
	: _name(name), _grade(grade) {
		if (grade < 1)
			throw (GradeTooHighException());
		if (grade > 150)
			throw (GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) 
	: _name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat(void)
{}

/*----------------OPERATOR OVERLOAD---------------*/

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return (o);
}
