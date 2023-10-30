/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:05:34 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/30 16:25:12 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() {
  type = "dog";
  _brain = new Brain();
  std::cout << "Created a dog with the standard constructor." << std::endl;
}

Dog::~Dog() {
  delete _brain;
  std::cout << "Killed a dog with the standard destructor." << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Wuff" << std::endl;
}

Dog::Dog(Dog const &src)
{
//assign attributes
//or use definition from copy assignment operator
  *this = src;
}

/**
 * in this specific case we can use the copy assignment operator from Brain
 * class, because the brain array has a fixed size and the copy assignment copies
 * every value
*/
Dog &Dog::operator=(Dog const &rhs)
{
	if (this != &rhs)
		{
			// delete _brain;
			type = rhs.type;
			// _brain = new Brain(*rhs._brain);
			*(_brain) = *(rhs._brain);
		}
	return (*this);
}

void	Dog::memorize(std::string memory) {
	(*_brain).saveMemory(memory);
}

void	Dog::retrieve() const {
	std::cout << (*_brain).retrieveMemory() << std::endl;
}
