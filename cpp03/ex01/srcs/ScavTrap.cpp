/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:00:12 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/13 17:29:31 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ST default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ST constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ST destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->getEnergyPoints() <= 0) {
		std::cout << "Not enough EP to attack" << std::endl;
		return;
	}
	if (this->getHitPoints() <= 0) {
		std::cout << "Dead ClapTrap cannot attack" << std::endl;
		return;
	}
	this->setEnergyPoints(this->getEnergyPoints() - 1);
	std::cout << "ScavTrap " << this->getName() << " attacks "  << target
		<< " causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->getName() << " is now in gate keeper mode"
		<< std::endl;
}
