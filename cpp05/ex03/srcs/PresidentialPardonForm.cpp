#include "PresidentialPardonForm.hpp"

/*------------------PUBLIC METHODS -----------------*/

void	PresidentialPardonForm::action() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

/*----------------GETTERS AND SETTERS --------------*/

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
	: AForm(src), _target(src._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
		{
			this->_target = rhs._target;
		}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{}

/*----------------OPERATOR OVERLOAD---------------*/

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i)
{
	o << i.getName();
	return (o);
}
