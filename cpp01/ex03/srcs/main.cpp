/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:56:59 by lbaumann          #+#    #+#             */
/*   Updated: 2023/08/01 14:51:21 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"
#include <cstdlib>

int main() {
	Weapon		loeffel;
	Weapon		roundhousekick;
	loeffel.setType( "Loeffel" );
	roundhousekick.setType( "Roundhouse-Kick" );
	HumanA		dieter = HumanA( "Dieter", loeffel);
	HumanB		gerlinde = HumanB( "Gerlinde");
	
	dieter.attack();
	gerlinde.attack();

	gerlinde.arm( roundhousekick );

	gerlinde.attack();

	
	return (EXIT_SUCCESS);
}
