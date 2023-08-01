/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:59:00 by lbaumann          #+#    #+#             */
/*   Updated: 2023/08/01 15:35:51 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon() {
	return;
}

Weapon::Weapon( std::string type ) : _type( type ) {
	return;
}

const std::string		&Weapon::getType() const {
	return (_type);
}

void		Weapon::setType( std::string newType ) {
	_type = newType;
}
