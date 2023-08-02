/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:56:59 by lbaumann          #+#    #+#             */
/*   Updated: 2023/08/02 14:19:57 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"
#include <cstdlib>

int main(int argc, char **argv) {
	Harl	grumpy;

	if (argc != 2) {
		std::cout << "Usage: ./harlfilter <level>" << std::endl;
		return ( EXIT_SUCCESS );
	}
	
	grumpy.complain(argv[1]);
	return ( EXIT_SUCCESS );
}
