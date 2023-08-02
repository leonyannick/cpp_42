/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:04:12 by lbaumann          #+#    #+#             */
/*   Updated: 2023/08/02 14:19:44 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

void Harl::debug()
{
	std::cout << "[DEBUG]\n" 
		<< "I love having extra bacon for my 7XL-double-cheese-triple"
		<< "-pickle-special- ketchup burger. I really do!\n" << std::endl;
	return;
}

void Harl::info()
{
	std::cout << "[INFO]\n"
		<< "I cannot believe adding extra bacon costs more money."
		<< "You didn’t put enough bacon in my burger! If you did, "
		<< "I wouldn’t be asking for more!\n" << std::endl;
	return;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]\n"
		<< "I think I deserve to have some extra bacon for free. "
		<< "I’ve been coming for years whereas you started working here"
		<< " since last month.\n" << std::endl;
	return;
}

void Harl::error()
{
	std::cout << "[ERROR]\n"
		<< "This is unacceptable! I want to speak to the manager now.\n"
		<< std::endl;
	return;
}

void Harl::complain(std::string level)
{
	void (Harl::*ptrToMember[4])() = {&Harl::debug, &Harl::info,
									  &Harl::warning, &Harl::error};

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i;
	for (i = 0; i < 4; i++)
	{
		if (level == levels[i])
			break;
	}
	switch (i) {
		case 0:
			(this->*ptrToMember[0])();
		case 1:
			(this->*ptrToMember[1])();
		case 2:
			(this->*ptrToMember[2])();
		case 3:
			(this->*ptrToMember[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"
				<< std::endl;
	}
	return;
}
