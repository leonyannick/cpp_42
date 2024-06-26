/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:59:00 by lbaumann          #+#    #+#             */
/*   Updated: 2023/07/29 11:26:56 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(){
	std::cout << "Zombie created (default constructor)" << std::endl;
	return;
}

Zombie::Zombie( std::string name ) : _name( name ) {
	std::cout << "Zombie created" << std::endl;
	return;
}

Zombie::~Zombie() {
	std::cout << "Zombie destroyed" << std::endl;
	return;
}

void	Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}
