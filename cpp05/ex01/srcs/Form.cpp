#include "Form.hpp"

/*------------------PUBLIC METHODS -----------------*/

/*----------------GETTERS AND SETTERS --------------*/

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

Form::Form(void) {}

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