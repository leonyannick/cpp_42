#include <iostream>
#include <cstdlib>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Intern randomIntern;
	AForm *randomForm;
	try {
		randomForm = randomIntern.makeForm("unknown", "president");
	}
	catch (std::exception& e) {
		std::cout << "form1: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		randomForm = randomIntern.makeForm("presidential pardon", "president");
		std::cout << *randomForm << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "form1: " << e.what() << std::endl;
	}
	delete randomForm;
	std::cout << std::endl;

	try {
		randomForm = randomIntern.makeForm("robotomy request", "president");
		std::cout << *randomForm << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "form1: " << e.what() << std::endl;
	}
	delete randomForm;
	std::cout << std::endl;

	try {
		randomForm = randomIntern.makeForm("srubbery creation", "president");
		std::cout << *randomForm << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "form1: " << e.what() << std::endl;
	}
	delete randomForm;
	return (EXIT_SUCCESS);
}

