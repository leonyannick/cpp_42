/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:00:12 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/17 13:39:55 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ST default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ST " << _name << " constructed." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ST " << _name << " destructed." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (_energyPoints <= 0) {
		std::cout << "Not enough EP to attack" << std::endl;
		return;
	}
	if (_hitPoints <= 0) {
		std::cout << "Dead ClapTrap cannot attack" << std::endl;
		return;
	}
	--_energyPoints;
	std::cout << "ScavTrap " << _name << " attacks "  << target
		<< " causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now in gate keeper mode"
		<< std::endl;
}
