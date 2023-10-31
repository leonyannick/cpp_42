/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:30:24 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/31 14:52:14 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) {
  this->type = type;
//   std::cout << "Materia type has been set to: " << type << std::endl;
}

AMateria::~AMateria() {
	// std::cout << "Materia destroyed." << std::endl;
}

std::string const & AMateria::getType() const {
  return (type);
}

void AMateria::use(ICharacter& target) {
	if (this->getType() == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName()
			<< " *" << std::endl;
	else if (this->getType() == "cure")
		std::cout << "* heals " << target.getName()
			<< "'s wounds *" << std::endl;
}
