/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:50:20 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/31 15:02:57 by lbaumann         ###   ########.fr       */
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

	using ScavTrap::attack; //alternative: have attack class that calls ScavTrap::attack

private:
	DiamondTrap();

	std::string _name;
};

#endif
