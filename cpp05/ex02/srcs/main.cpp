#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	AForm *form1 = new ShrubberyCreationForm("test");
	try {
		Bureaucrat angela("angela", 1);
		form1->beSigned(angela);
		angela.signForm(*form1);
		form1->execute(angela);
	}
	catch (std::exception& e) {
		std::cout << "form1:" << e.what() << std::endl;
	}
	delete form1;
	
	std::cout << std::endl;
	form1 = new ShrubberyCreationForm("test");
	try {
		Bureaucrat angela("angela", 1);
		form1->beSigned(angela);
		angela.signForm(*form1);
		angela.executeForm(*form1);
	}
	catch (std::exception& e) {
		std::cout << "form1:" << e.what() << std::endl;
	}
	delete form1;

	std::cout << std::endl;
	form1 = new ShrubberyCreationForm("test");
	try {
		Bureaucrat angela("angela", 1);
		// form1->beSigned(angela);
		angela.signForm(*form1);
		form1->execute(angela);
	}
	catch (std::exception& e) {
		std::cout << "form1:" << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete form1;

	form1 = new RobotomyRequestForm("test");
	try {
		Bureaucrat angela("angela", 1);
		form1->beSigned(angela);
		angela.signForm(*form1);
		form1->execute(angela);

	}
	catch (std::exception& e) {
		std::cout << "form1:" << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete form1;

	form1 = new PresidentialPardonForm("test");
	try {
		Bureaucrat angela("angela", 1);
		form1->beSigned(angela);
		angela.signForm(*form1);
		form1->execute(angela);
	}
	catch (std::exception& e) {
		std::cout << "form1:" << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete form1;

	form1 = new PresidentialPardonForm("test");
	try {
		Bureaucrat angela("angela", 25);
		std::cout << angela << std::endl;
		std::cout << *form1 << std::endl;
		form1->beSigned(angela);
		angela.signForm(*form1);
		form1->execute(angela);
	}
	catch (std::exception& e) {
		std::cout << "form1:" << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete form1;

	form1 = new ShrubberyCreationForm("test");
	try {
		Bureaucrat angela("angela", 146);
		std::cout << angela << std::endl;
		std::cout << *form1 << std::endl;
		form1->beSigned(angela);
		angela.signForm(*form1);
		form1->execute(angela);
	}
	catch (std::exception& e) {
		std::cout << "form1:" << e.what() << std::endl;
	}
	delete form1;
	return (EXIT_SUCCESS);
}

