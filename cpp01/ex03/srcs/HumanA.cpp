/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:04:12 by lbaumann          #+#    #+#             */
/*   Updated: 2023/08/01 17:52:47 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &tatwaffe ) : _name( name ),
				_refTatwaffe( tatwaffe ) {
	return;
}

void	HumanA::attack() const {
	std::cout << _name << " attacks with their " << _refTatwaffe.getType() << std::endl;
	return;
}
