#include "Form.hpp"

/*------------------PUBLIC METHODS -----------------*/

void Form::signForm() const {
	if (_isSigned)
		std::cout << _signedBy << " signed " << _name << std::endl;
	else
		std::cout << text << std::endl;
}

/*----------------GETTERS AND SETTERS --------------*/

std::string Form::getName() const {return (_name);};

bool Form::getSignStatus() const {return (_isSigned);}

int	Form::getGradeSign() const {return (_gradeSign);}

int Form::getGradeExec() const {return (_gradeExec);}

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

Form::Form(std::string name, int gradeSign, int gradeExec) throw (std::exception)
	: _name(name), _gradeSign(gradeSign), _gradeExec(_gradeExec), _isSigned(false) {
		if (gradeSign > 150 || gradeExec > 150)
			throw (GradeTooLowException());
		if (gradeSign < 1 || gradeExec > 1)
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
	<< (i.getSignStatus()) ? "signed" : "not signed";
	return (o);
}