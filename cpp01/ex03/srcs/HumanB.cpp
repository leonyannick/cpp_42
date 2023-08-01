/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:53:07 by lbaumann          #+#    #+#             */
/*   Updated: 2023/08/01 14:52:46 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB( std::string name ) : _name( name ) {
	return;
}

void	HumanB::attack() const {
	std::cout << _name << " attacks with their " << _tatwaffe.getType() << std::endl;
	return;
}

void	HumanB::arm( Weapon tatwaffe ) {
	_tatwaffe = tatwaffe;
	std::cout << _name << " is now armed with " << _tatwaffe.getType() << std::endl;
}
