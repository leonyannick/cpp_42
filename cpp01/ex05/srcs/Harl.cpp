/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:04:12 by lbaumann          #+#    #+#             */
/*   Updated: 2023/08/02 14:17:11 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple"
		<< "-pickle-special- ketchup burger. I really do!" << std::endl;
	return;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money."
		<< "You didn’t put enough bacon in my burger! If you did, "
		<< "I wouldn’t be asking for more!" << std::endl;
	return;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. "
		<< "I’ve been coming for years whereas you started working here"
		<< " since last month." << std::endl;
	return;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now."
		 << std::endl;
	return;
}

void	Harl::complain( std::string level ) {
	void		(Harl::*ptrToMember[])() = {&Harl::debug, &Harl::info,
					&Harl::warning, &Harl::error};
	
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++) {
		if (level == levels[i])
			(this->*ptrToMember[i])();
	}
	return;
}
