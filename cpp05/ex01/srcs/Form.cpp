#include "Form.hpp"
#include "Bureaucrat.hpp"

/*------------------PUBLIC METHODS -----------------*/

void	Form::beSigned(Bureaucrat& b) throw (GradeTooLowException) {
	if (b.getGrade() <= this->_gradeSign) {
		this->_isSigned = true;
	}
	else {
		throw (GradeTooLowException());
	}
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Form exception: grade too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Form exception: grade too low");
}

/*----------------GETTERS AND SETTERS --------------*/

std::string Form::getName() const {return (_name);};

bool Form::getSignStatus() const {return (_isSigned);}

int	Form::getGradeSign() const {return (_gradeSign);}

int Form::getGradeExec() const {return (_gradeExec);}

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

Form::Form(std::string name, int gradeSign, int gradeExec) throw (std::exception)
	: _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
		if (gradeSign > 150 || gradeExec > 150)
			throw (GradeTooLowException());
		if (gradeSign < 1 || gradeExec < 1)
			throw(GradeTooHighException());
	}


Form::Form(const Form& src)
	: _name(src._name), _isSigned(src._isSigned),
	_gradeSign(src._gradeSign), _gradeExec(src._gradeExec) {}

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
		{
		//copying of member attributes here
		}
	return (*this);
}

Form::~Form(void)
{}

/*----------------OPERATOR OVERLOAD---------------*/

std::ostream &operator<<(std::ostream &o, Form const &i)
{
	o << "Form " << i.getName() << " requires " << i.getGradeSign()
	<< "/" << i.getGradeExec() << " to sign/exec. It is "
	<< ((i.getSignStatus()) ? "signed" : "not signed");
	return (o);
}