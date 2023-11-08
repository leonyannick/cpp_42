#include "ShrubberyCreationForm.hpp"
#include <fstream>

/*------------------PUBLIC METHODS -----------------*/

void	ShrubberyCreationForm::action() const {
	std::ofstream outfile((this->_target + "_shrubbery").c_str());
	outfile << "      %%%,%%%%%%%" << std::endl;
	outfile << "       ,'%% \\-*%%%%%%%" << std::endl;
    outfile << " ;%%%%%*%   _%%%%" << std::endl;
    outfile << "  ,%%%       \\(_.*%%%%." << std::endl;
    outfile << "  % *%%, ,%%%%*(    '" << std::endl;
    outfile << "%^     ,*%%% )\\|,%%*%,_" << std::endl;
    outfile << "     *%    \\/ #).-\"*%%*" << std::endl;
    outfile << "         _.) ,/ *%," << std::endl;
    outfile << "  _________)#(_____________" << std::endl;
	outfile.close();
}

/*----------------GETTERS AND SETTERS --------------*/

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	: AForm(src), _target(src._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
		{
			this->_target = rhs._target;
		}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{}

/*----------------OPERATOR OVERLOAD---------------*/

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i)
{
	o << i.getName();
	return (o);
}