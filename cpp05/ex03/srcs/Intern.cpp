#include "Intern.hpp"

/*------------------PUBLIC METHODS -----------------*/

const char *Intern::FormNotExisting::what() const throw() {
	return ("Intern exception: Form does not exist");
}

AForm	*Intern::makeForm(std::string formName, std::string target) const
	throw (FormNotExisting) {
		AForm *form;
		std::string formsAvailable[]
			= {"srubbery creation", "robotomy request", "presidential pardon"};
		size_t i = 0;
		for (; i < 3 && formName != formsAvailable[i]; i++);
		switch(i) {
			case 0:
				form = new ShrubberyCreationForm(target);
				break;
			case 1:
				form = new RobotomyRequestForm(target);
				break;
			case 2:
				form = new PresidentialPardonForm(target);
				break;
			default:
				std::cout << "This intern does not know this Form" << std::endl;
				throw (FormNotExisting());
		}
		std::cout << "Intern creates " << form->getName() << std::endl;
		return (form);
}

/*----------------GETTERS AND SETTERS --------------*/

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

Intern::Intern(void) {}

Intern::~Intern(void) {}

