/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:31:04 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/17 14:10:21 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# include <iostream>
# include <string>

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(std::string name);
	~FragTrap();

	// void attack(const std::string& target);
	void highFivesGuys();

private:
	FragTrap();
};

#endif
