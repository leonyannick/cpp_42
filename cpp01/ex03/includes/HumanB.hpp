/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:54:09 by lbaumann          #+#    #+#             */
/*   Updated: 2023/08/01 14:44:54 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {

private:
	std::string		_name;
	Weapon			_tatwaffe;

public:
	HumanB( std::string name );
	void			attack() const;
	void			arm( Weapon tatwaffe );
};

#endif
