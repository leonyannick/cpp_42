/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:04:12 by lbaumann          #+#    #+#             */
/*   Updated: 2023/07/29 11:26:43 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

/**
 * first we create a Zombie arraz on the heap using the default constructor
 * -> N times constructor called
 * 
 * then for each array entry we create a new Zombie instance on the stack and
 * passing it name and copy it over to the heap array
 * -> this means that N times constructor and destructor is called
*/
Zombie*		zombieHorde( int N, std::string name ) {
	Zombie*	Horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		Horde[i] = Zombie( name );
		// new (&Horde[i]) Zombie( name );
	}
	
	return (Horde);
}
