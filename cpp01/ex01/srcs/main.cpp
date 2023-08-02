/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:56:59 by lbaumann          #+#    #+#             */
/*   Updated: 2023/08/02 13:59:30 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include <cstdlib>

int main() {
	Zombie*		Horde = zombieHorde( NZOMBIES, "nameless" );
	
	for (int i = 0; i < NZOMBIES; i++) {
		Horde[i].announce();
	}
	
	delete[] Horde;
	return(EXIT_SUCCESS);
}
