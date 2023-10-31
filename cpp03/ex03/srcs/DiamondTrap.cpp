/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:00:50 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/31 15:01:36 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : 
	ClapTrap(name + "_clap_trap"), FragTrap("FT"), ScavTrap("ST"), _name(name) {
	this->_hitPoints = 100; //from FragTrap
	this->_energyPoints = 50; //from ScavTrap
	this->_attackDamage = 30; //from FragTrap
	std::cout << "DT " << _name << " constructed." << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DT " << _name << " destructed." << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "My name is: " << _name << std::endl;
	std::cout << "My Claptrap name is: " << ClapTrap::_name << std::endl;
}

