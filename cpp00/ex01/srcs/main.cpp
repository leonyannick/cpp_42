/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:56:59 by lbaumann          #+#    #+#             */
/*   Updated: 2023/07/26 15:35:25 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
#include "../includes/Contact.hpp"
#include "../includes/PhoneBook.hpp"

int main( void ) {
	
	std::string		line;
	PhoneBook		yellowPages;

	std::cout << "------Welcome to the yellow pages-------" << std::endl << std::endl
			<< "enter one of the following commands:" << std::endl
			<< "-<ADD>" << std::endl
			<< "-<SEARCH>" << std::endl
			<< "-<EXIT>" << std::endl << std::endl;
	while (1) {
		std::getline(std::cin, line);
		if (line.compare("ADD") == 0)
			yellowPages.add();
		else if (line.compare("SEARCH") == 0)
			yellowPages.search();
		else if (line.compare("EXIT") == 0)
			break;
		else {
			std::cout << "enter a valid command" << std::endl;
			continue;
		}
		std::cout << std::endl << "ready to take a new command:" << std::endl;
	}
}
