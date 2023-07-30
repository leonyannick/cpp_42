/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:53:07 by lbaumann          #+#    #+#             */
/*   Updated: 2023/07/30 20:02:18 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB( std::string name) {
	_name = name;
	return;
}

void	HumanB::attack() const {
	std::cout << _name << "attacks with their" << _tatwaffe.getType() << std::endl;
	return;
}
