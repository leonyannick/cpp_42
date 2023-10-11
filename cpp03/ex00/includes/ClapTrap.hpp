/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:09:48 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/11 19:23:50 by lbaumann         ###   ########.fr       */
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

  ClapTrap &operator=(ClapTrap const & rhs);

private:
  ClapTrap();
  std::string _name;
  int         _hitPoints;
  int         _energyPoints;
  int         _attackDamage;
};

std::ostream &		operator<<(std::ostream & o, ClapTrap const & i);

#endif
