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

void Bureaucrat::signForm(AForm& f) const {
	if (f.getSignStatus()) {
		std::cout << this->getName() << " signed " << f.getName()
			<< std::endl;
	}
	else {
		std::cout << this->getName() << " couldn't sign " << f.getName()
			<< " because the stars weren't aligned right." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
	throw (GradeTooLowException, AForm::NotSignedException) {
	if (!form.getSignStatus())
		throw (AForm::NotSignedException());
	if (this->getGrade() >= form.getGradeExec()) {
		throw (GradeTooLowException());
	}
	form.execute(*this);
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

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		{
			//
		}
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{}

/*----------------OPERATOR OVERLOAD---------------*/

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return (o);
}
