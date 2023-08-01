/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:54:09 by lbaumann          #+#    #+#             */
/*   Updated: 2023/08/01 17:49:24 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

/**
 * save Weapon here as a pointer, because HumanB is created without a weapon
 * and a Reference cannot be declared without initializing
*/
class HumanB {

private:
	std::string		_name;
	Weapon			*_pTatwaffe;

public:
	HumanB( std::string name );
	void			attack() const;
	void			setWeapon( Weapon &tatwaffe );
};

#endif
