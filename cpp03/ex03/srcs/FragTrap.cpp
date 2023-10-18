/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:33:32 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/17 13:38:39 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "FT default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FT " << _name << " constructed." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FT " << _name << " destructed." << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << _name << " wants to high five someone"
		<< std::endl;
}
