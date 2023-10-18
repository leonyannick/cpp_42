/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:36:27 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/17 13:23:15 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# include <iostream>
# include <string>

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string name);
	// ScavTrap(ScavTrap const & src);
	~ScavTrap();

	void attack(const std::string& target);
	void guardGate();

	// ScavTrap &operator=(ScavTrap const & rhs);
private:
	ScavTrap();
};

#endif
