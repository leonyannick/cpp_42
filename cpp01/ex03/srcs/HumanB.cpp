/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:53:07 by lbaumann          #+#    #+#             */
/*   Updated: 2023/08/01 17:49:39 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

/**
 * initialize _pTatwaffe to NULL so we can check in attack function before
 * dereferencing the pointer
*/
HumanB::HumanB( std::string name ) : _name( name ), _pTatwaffe( NULL ) {
	return;
}

/**
 * only attack if HumanB really has a Weapon -> SEGFAULT would occurr otherwise
*/
void	HumanB::attack() const {
	if (_pTatwaffe)
		std::cout << _name << " attacks with their " << _pTatwaffe->getType() << std::endl;
	return;
}

/**
 * set _pTatwaffe pointer to address of reference of tatwaffe passed as a parameter
*/
void	HumanB::setWeapon( Weapon &tatwaffe ) {
	_pTatwaffe = &tatwaffe;
	std::cout << _name << " is now armed with " << _pTatwaffe->getType() << std::endl;
}
