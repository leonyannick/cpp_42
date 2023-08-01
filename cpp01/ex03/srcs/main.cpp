/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:56:59 by lbaumann          #+#    #+#             */
/*   Updated: 2023/08/01 17:45:11 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"
#include <cstdlib>

// int main() {
// 	Weapon		loeffel;
// 	Weapon		roundhousekick;
// 	loeffel.setType( "Loeffel" );
// 	roundhousekick.setType( "Roundhouse-Kick" );
// 	HumanA		dieter = HumanA( "Dieter", loeffel);
// 	HumanB		gerlinde = HumanB( "Gerlinde");
	
// 	dieter.attack();
// 	gerlinde.attack();

// 	gerlinde.arm( roundhousekick );

// 	gerlinde.attack();

	
// 	return (EXIT_SUCCESS);
// }

int main() {
	{
		Weapon 	club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	
	return 0;
}
