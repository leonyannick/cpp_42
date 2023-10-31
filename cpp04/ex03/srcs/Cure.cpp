/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:49:13 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/31 14:52:35 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	// std::cout << "Cure constructed" << std::endl;
}

Cure::Cure(Cure const &src) : AMateria("cure") {
	*this = src;
	// std::cout << "Cure copy constructed" << std::endl;
}

Cure::~Cure()	{
	// std::cout << "Cure destroyed" << std::endl;
}

Cure &Cure::operator=(Cure const &rhs)
{
	if (this != &rhs)
		{
			this->type = rhs.type;
		}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Cure const &i)
{
	o << i.getType();
	return (o);
}

AMateria* Cure::clone() const {
	return (new Cure());
}
