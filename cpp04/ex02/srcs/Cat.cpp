/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:56:28 by lbaumann          #+#    #+#             */
/*   Updated: 2023/11/07 13:04:56 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): _brain(new Brain()) {
  type = "cat";
  std::cout << "Created a cat with the standard constructor." << std::endl;
}

Cat::~Cat() {
  delete _brain;
  std::cout << "Killed a cat with the standard destructor." << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Miau" << std::endl;
}

Cat::Cat(Cat const &src) : _brain(new Brain())
{
//assign attributes
//or use definition from copy assignment operator
  *this = src;
}

/**
 * this is the usual way for allocated memory to be reassigned in the copy assignment
 * -> check dog class for another way in this specific case
*/
Cat &Cat::operator=(Cat const &rhs)
{
	if (this != &rhs)
		{
			delete _brain;
			type = rhs.type;
			_brain = new Brain(*rhs._brain);
		}
	return (*this);
}
