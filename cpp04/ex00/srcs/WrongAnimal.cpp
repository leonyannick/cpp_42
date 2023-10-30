/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:07:54 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/30 14:15:25 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("abstractWrongAnimal") {
  std::cout << "Created an WrongAnimal with the standard constructor." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) {
  *this = src;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "Killed an WrongAnimal with the standard destructor." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
  if (this != &rhs) {
      type = rhs.type;
    }
  return (*this);
}

std::ostream &operator<<(std::ostream &o, WrongAnimal const &i)
{
  o << "WrongAnimal of type: " << i.getType() << ".";
  return (o);
}

std::string WrongAnimal::getType() const {
  return (type);
}

void WrongAnimal::makeSound() const {
	std::cout << "abstractWrongAnimalSound" << std::endl;
}
