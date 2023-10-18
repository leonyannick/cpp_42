/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:00:50 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/18 15:34:18 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : 
	ScavTrap("ST"), FragTrap("FT"), ClapTrap(name + "_clap_trap"), _name(name) {
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	// _energyPoints = ScavTrap::_energyPoints;
	std::cout << "ST name: " << ScavTrap::getName() << std::endl;
	std::cout << "FT name: " << FragTrap::getName() << std::endl;
	// std::cout << FragTrap::_hitPoints << std::endl;
	// std::cout << FragTrap::_attackDamage << std::endl;
	// std::cout << ScavTrap::_energyPoints << std::endl;
	// std::cout << ScavTrap::_attackDamage << std::endl;
	std::cout << "DT " << _name << " constructed." << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DT " << _name << " destructed." << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "My name is: " << _name << std::endl;
	std::cout << "My Claptrap name is: " << ClapTrap::_name << std::endl;
}

