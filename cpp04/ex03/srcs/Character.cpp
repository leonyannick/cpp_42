/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:50:12 by lbaumann          #+#    #+#             */
/*   Updated: 2023/11/07 13:13:26 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string& name) : _name(name) {
	for (int i = 0; i < 4; i++) {
    	_inventory[i] = 0;
    }
	// std::cout << "Character " << _name << " created." << std::endl;
}

Character::Character(Character const &src)
{
	// std::cout << "character copy constructor" << std::endl;
//assign attributes
//or use definition from copy assignment operator
	*this = src;
}

Character::~Character() {
	// std::cout << "Character " << _name << " vanished." << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

Character &Character::operator=(Character const &rhs)
{
	// std::cout << "character copy assignment" << std::endl;
	if (this != &rhs)
		{
			_name = rhs._name;
			for (size_t i = 0; i < 4; i++)
			{
				delete _inventory[i];
				_inventory[i] = rhs._inventory[i]->clone();
			}
		}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Character const &i)
{
	o << i.getName();
	return (o);
}

std::string const & Character::getName() const { return (_name); }

//unequip does not delete materia!
void Character::equip(AMateria *m) {
	if (!m)
	{
		std::cout << "Cannot equip nothing" << std::endl;
		return ;
	}
	for (size_t i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			break;	
		}
	}
}

void	Character::unequip(int idx) { 
	if (idx >= 0 && idx < 4)
	{
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}
