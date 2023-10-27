/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:04:31 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/27 22:07:02 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice constructed" << std::endl;
}

Ice::Ice(Ice const &src) : AMateria("ice") {
	*this = src;
	std::cout << "Ice copy constructed" << std::endl;
}

Ice::~Ice()	{
	std::cout << "Ice destroyed" << std::endl;
}

Ice &Ice::operator=(Ice const &rhs)
{
	if (this != &rhs)
		{
			this->type = rhs.type;
		}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Ice const &i)
{
	o << i.getType();
	return (o);
}

AMateria* Ice::clone() const {
	return (new Ice());
}
