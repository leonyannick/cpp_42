/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:47:30 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/27 21:09:39 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

AAnimal::AAnimal() : type("abstractAAnimal") {
  std::cout << "Created an AAnimal with the standard constructor." << std::endl;
}

AAnimal::AAnimal(AAnimal const &src) {
  *this = src;
}

AAnimal::~AAnimal() {
  std::cout << "Killed an AAnimal with the standard destructor." << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &rhs)
{
  if (this != &rhs) {
      type = rhs.type;
    }
  return (*this);
}

std::ostream &operator<<(std::ostream &o, AAnimal const &i)
{
  o << "AAnimal of type: " << i.getType() << ".";
  return (o);
}

std::string AAnimal::getType() const {
  return (type);
}
