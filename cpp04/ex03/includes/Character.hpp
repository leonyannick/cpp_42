/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:10:05 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/31 12:41:03 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"


class Character : public ICharacter
{
public:
	Character(const std::string& name);
	Character(Character const & src);
	~Character();

	Character &operator=(Character const & rhs);

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
private:
	Character();
	
	AMateria* _inventory[4];
	std::string _name;
};

std::ostream &		operator<<(std::ostream & o, Character const & i);

#endif