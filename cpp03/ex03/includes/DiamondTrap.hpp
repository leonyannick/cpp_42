/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:50:20 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/18 15:32:32 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

# include <iostream>
# include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
	DiamondTrap(std::string name);
	~DiamondTrap();

	void	whoAmI();

	using ScavTrap::attack;

private:
	DiamondTrap();

	// using FragTrap::_hitPoints;
	// using ScavTrap::_energyPoints;
	// using FragTrap::_attackDamage;
	

	std::string _name;
};

#endif
