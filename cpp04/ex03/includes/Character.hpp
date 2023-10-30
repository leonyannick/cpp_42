/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:10:05 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/30 09:57:22 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

#include <iostream>

class Character : public ICharacter
{
public:
	Character();
	Character(Character const & src);
	~Character();

	Character &operator=(Character const & rhs);
private:
	AMateria* inventory[4];
};

std::ostream &		operator<<(std::ostream & o, Character const & i);

Character::Character()
{
}

Character::Character(Character const &src)
{
//assign attributes
//or use definition from copy assignment operator
// *this = src;
}

Character::~Character()
{
}

Character &Character::operator=(Character const &rhs)
{
	if (this != &rhs)
		{
		//copying of member attributes here
		}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Character const &i)
{
	//o << <fill ostream with attributes>
	return (o);
}

#endif