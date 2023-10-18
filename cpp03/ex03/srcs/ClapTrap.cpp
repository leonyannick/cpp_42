/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:23:56 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/17 13:46:02 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "CT default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
  : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "CT " << _name << " constructed." << std::endl;
  }

ClapTrap::ClapTrap(ClapTrap const &src)
{
//assign attributes
//or use definition from copy assignment operator
	std::cout << "CT Copy constructor called: " << src._name << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap() {
	std::cout << "CT " << _name << " destructed." << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
  if (this != &rhs)
    {
      _name = rhs._name;
	  _hitPoints = rhs._hitPoints;
	  _energyPoints = rhs._energyPoints;
	  _attackDamage = rhs._attackDamage;
    }
  return (*this);
}

std::ostream &operator<<(std::ostream &o, ClapTrap const &i)
{
  o << "Name:" << i.getName() << " HP:" << i.getHitPoints()
	<< " EP:" << i.getEnergyPoints() << " AD:" << i.getAttackDamage();
  return (o);
}

std::string ClapTrap::getName() const { return (_name); }

int ClapTrap::getHitPoints() const { return (_hitPoints); }

int ClapTrap::getEnergyPoints() const { return (_energyPoints); }

int ClapTrap::getAttackDamage() const { return (_attackDamage); }

void	ClapTrap::setHitPoints(int amount) { _hitPoints = amount; }

void	ClapTrap::setEnergyPoints(int amount) { _energyPoints = amount; }

void	ClapTrap::setAttackDamage(int amount) { _attackDamage = amount; }

void	ClapTrap::setName(std::string name) { _name = name; }

void ClapTrap::attack(const std::string& target) {
	if (_energyPoints <= 0) {
		std::cout << "Not enough EP to attack" << std::endl;
		return;
	}
	if (_hitPoints <= 0) {
		std::cout << "Dead ClapTrap cannot attack" << std::endl;
		return;
	}
	--_energyPoints;
	std::cout << "ClapTrap " << _name << " attacks "  << target
		<< " causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " took " << amount 
		<< " damage." << std::endl;
	_hitPoints -= amount;
	if (_hitPoints <= 0)
		std::cout << "ClapTrap died." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints <= 0) {
		std::cout << "Not enough EP to repair" << std::endl;
		return;
	}
	if (_hitPoints <= 0) {
		std::cout << "Dead ClapTrap cannot repair itself" << std::endl;
		return;
	}
	--_energyPoints;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repaired itself by " << amount 
		<< " hitpoints." << std::endl;
}
