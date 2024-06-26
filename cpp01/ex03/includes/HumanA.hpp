/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:43:26 by lbaumann          #+#    #+#             */
/*   Updated: 2023/08/01 17:52:32 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {

private:
	std::string		_name;
	Weapon			&_refTatwaffe;

public:
	HumanA( std::string name, Weapon &tatwaffe );
	void			attack() const;
};

#endif
