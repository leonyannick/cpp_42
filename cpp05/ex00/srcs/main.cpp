#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
	try {
		Bureaucrat horst("horst", 150);
		std::cout << "horst created" << std::endl;
		horst.decrementGrade();
	}
	catch (std::exception& e) {
		std::cout << "horst " << e.what() << std::endl;
	}

	try {
		Bureaucrat renate("renate", 1);
		std::cout << "renate created" << std::endl;
		renate.incrementGrade();
		std::cout << renate.getGrade() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "renate " << e.what() << std::endl;
	}

	try {
		Bureaucrat guenther("guenther", 0);
		std::cout << "guenther created" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "guenther not created" << std::endl;
		std::cout << "guenther " << e.what() << std::endl;
	}

	try {
		Bureaucrat heinrich ("heinrich", 151);
		std::cout << "heinrich created" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "heinrich not created" << std::endl;
		std::cout << "heinrich " << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}

