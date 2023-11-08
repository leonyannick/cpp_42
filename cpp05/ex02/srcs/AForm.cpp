#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*------------------PUBLIC METHODS -----------------*/

void	AForm::beSigned(Bureaucrat& b) throw (GradeTooLowException) {
	if (b.getGrade() <= this->_gradeSign) {
		std::cout << this->getName() << " signed by " << b.getName() << std::endl;
		this->_isSigned = true;
	}
	else {
		throw (GradeTooLowException());
	}
}

void	AForm::execute(Bureaucrat const & executor) const
	throw (GradeTooLowException, NotSignedException) {
		if (!this->getSignStatus())
			throw (NotSignedException());
		if (executor.getGrade() > this->getGradeExec())
			throw (GradeTooLowException());
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		this->action();
	}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("AForm exception: grade too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("AForm exception: grade too low");
}

const char *AForm::NotSignedException::what() const throw() {
	return ("AForm exception: not signed");
}


/*----------------GETTERS AND SETTERS --------------*/

std::string AForm::getName() const {return (_name);};

bool AForm::getSignStatus() const {return (_isSigned);}

int	AForm::getGradeSign() const {return (_gradeSign);}

int AForm::getGradeExec() const {return (_gradeExec);}

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

AForm::AForm(std::string name, int gradeSign, int gradeExec) throw (std::exception)
	: _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
		if (gradeSign > 150 || gradeExec > 150)
			throw (GradeTooLowException());
		if (gradeSign < 1 || gradeExec < 1)
			throw(GradeTooHighException());
	}


AForm::AForm(const AForm& src)
	: _name(src._name), _isSigned(src._isSigned),
	_gradeSign(src._gradeSign), _gradeExec(src._gradeExec) {}


AForm::~AForm(void)
{}

/*----------------OPERATOR OVERLOAD---------------*/

std::ostream &operator<<(std::ostream &o, AForm const &i)
{
	o << "AForm " << i.getName() << " requires " << i.getGradeSign()
	<< "/" << i.getGradeExec() << " to sign/exec. It is "
	<< ((i.getSignStatus()) ? "signed" : "not signed");
	return (o);
}