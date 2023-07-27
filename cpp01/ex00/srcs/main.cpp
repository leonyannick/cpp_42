/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:56:59 by lbaumann          #+#    #+#             */
/*   Updated: 2023/07/27 20:15:12 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main() {
	Zombie*		leonOnHeap = newZombie( "Leon on heap" );
	randomChump( "Leon on stack" );
	leonOnHeap->announce();
	delete leonOnHeap;
	return(EXIT_SUCCESS);
}
