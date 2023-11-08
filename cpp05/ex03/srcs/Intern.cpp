#include "Intern.hpp"

/*------------------PUBLIC METHODS -----------------*/

const char *Intern::FormNotExisting::what() const throw() {
	return ("Intern exception: Form does not exist");
}

AForm	*Intern::makeForm(std::string formName, std::string target) const
	throw (FormNotExisting) {
		std::string formsAvailable[]
			= {"srubbery creation", "robotomy request", "presidential pardon"};
		size_t i = 0;
		for (; i < 3 && formName != formsAvailable[i]; i++);
		switch(i) {
			case 0:
				return (new ShrubberyCreationForm(target));
				break;
			case 1:
				return (new RobotomyRequestForm(target));
				break;
			case 2:
				return (new PresidentialPardonForm(target));
				break;
		}
		std::cout << "This intern does not know this Form" << std::endl;
		throw (FormNotExisting());
}

/*----------------GETTERS AND SETTERS --------------*/

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

Intern::Intern(void) {}

Intern::~Intern(void) {}

