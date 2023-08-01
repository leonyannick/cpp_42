/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:59:00 by lbaumann          #+#    #+#             */
/*   Updated: 2023/08/01 13:37:12 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

void	Contact::displayContact() const {
	
	std::cout << std::endl << "The contact you were looking for:" << std::endl;
	std::cout << "First name:\t";
	std::cout << this->_firstName << std::endl;
	std::cout << "Last name:\t";
	std::cout << this->_lastName << std::endl;
	std::cout << "Nickname:\t";
	std::cout << this->_nickname << std::endl;
	std::cout << "Phone Number:\t";
	std::cout << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret:\t";
	std::cout << this->_darkestSecret << std::endl << std::endl;
}

void	Contact::displayInfo() const {
	std::string		outstr;

	outstr = this->_firstName.substr(0, 10);
	if (outstr.length() == 10)
		outstr[9] = '.';
	std::cout << std::setw(10) << std::right << outstr << '|';
	
	outstr = this->_lastName.substr(0, 10);
	if (outstr.length() == 10)
		outstr[9] = '.';
	std::cout << std::setw(10) << std::right << outstr << '|';
	
	outstr = this->_nickname.substr(0, 10);
	if (outstr.length() == 10)
		outstr[9] = '.';
	std::cout << std::setw(10) << std::right << outstr << std::endl;
}

static std::string	getInput( std::string ContactAttribute) {
	std::string		line;
	
	std::cout << std::endl << "Please enter " << ContactAttribute << ":" << std::endl;
	while (line.compare("") == 0) {
		std::getline(std::cin, line);
	}
	return (line);
}

void	Contact::setAttributes() {
	this->_firstName = getInput("first name");
	this->_lastName = getInput("last name");
	this->_nickname = getInput("nickname");
	this->_phoneNumber = getInput("phone number");
	this->_darkestSecret = getInput("darkest secret");
}
