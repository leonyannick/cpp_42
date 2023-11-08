#include "RobotomyRequestForm.hpp"

/*------------------PUBLIC METHODS -----------------*/

void	RobotomyRequestForm::action() const {
	//take current time as seed for the random generator
	std::srand(std::time(NULL));
	//generate a random number
	int n = std::rand();
	if (n % 2)
		std::cout << _target << " has been robotomized." << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;
}

/*----------------GETTERS AND SETTERS --------------*/

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
	: AForm(src), _target(src._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
		{
			this->_target = rhs._target;
		}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{}

/*----------------OPERATOR OVERLOAD---------------*/

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i)
{
	o << i.getName();
	return (o);
}