#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
	try {
		Form bafoeg("bafoeg", -1, 1);
	}
	catch (std::exception& e) {
		std::cout << "bafoeg " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Form bafoeg("bafoeg", 1, 151);
	}
	catch (std::exception& e) {
		std::cout << "bafoeg " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat renate("renate", 3);
		Form bafoeg("bafoeg", 2, 150);
		std::cout << bafoeg << std::endl;
		renate.signForm(bafoeg);
		bafoeg.beSigned(renate);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat renate("renate", 1);
		std::cout << renate << std::endl;
		Form bafoeg("bafoeg", 2, 150);
		std::cout << bafoeg << std::endl;
		bafoeg.beSigned(renate);
		renate.signForm(bafoeg);
		std::cout << bafoeg << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}

