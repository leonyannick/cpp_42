/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:59:00 by lbaumann          #+#    #+#             */
/*   Updated: 2023/07/30 19:42:27 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

const std::string		&Weapon::getType() const {
	return (_type);
}

void		Weapon::setType( std::string newType ) {
	_type = newType;
}
