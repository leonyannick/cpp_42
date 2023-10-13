/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:09:48 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/13 17:23:47 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

#include <iostream>

class ClapTrap
{
public:
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(ClapTrap const & src);
  ~ClapTrap();

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  std::string  getName() const;
  int          getHitPoints() const;
  int          getEnergyPoints() const;
  int          getAttackDamage() const;

  void         setHitPoints(int amount);
  void         setEnergyPoints(int amount);
  void         setAttackDamage(int amount);

  ClapTrap &operator=(ClapTrap const & rhs);

private:
  std::string _name;
  int         _hitPoints;
  int         _energyPoints;
  int         _attackDamage;
};

std::ostream &		operator<<(std::ostream & o, ClapTrap const & i);

#endif
