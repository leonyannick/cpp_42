/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:47:30 by lbaumann          #+#    #+#             */
/*   Updated: 2023/11/07 11:12:50 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("abstractAnimal") {
  std::cout << "Created an animal with the standard constructor." << std::endl;
}

Animal::Animal(Animal const &src) {
  *this = src;
}

Animal::~Animal() {
  std::cout << "Killed an animal with the standard destructor." << std::endl;
}

Animal &Animal::operator=(Animal const &rhs)
{
  if (this != &rhs) {
      type = rhs.type;
    }
  return (*this);
}

std::ostream &operator<<(std::ostream &o, Animal const &i)
{
  o << "Animal of type: " << i.getType() << ".";
  return (o);
}

std::string Animal::getType() const {
  return (type);
}

void Animal::makeSound() const {
	std::cout << "abstractAnimalSound" << std::endl;
}
