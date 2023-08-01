/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:04:12 by lbaumann          #+#    #+#             */
/*   Updated: 2023/08/01 13:44:38 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

/**
 * initialize _contactIdx to -1 as there are no Contacts in the beginning
*/
PhoneBook::PhoneBook() : _contactIdx( -1 ) , _nContacts( 0 ) {
	std::cout << "phonebook created" << std::endl;
}

PhoneBook::~PhoneBook() {
	std::cout << "phonebook destroyed" << std::endl;
}

void	PhoneBook::_listEntries() const {
	std::string		outstr;

	std::cout << std::endl;
	std::cout << std::setw(10) << std::right << "Index" << '|';
	std::cout << std::setw(10) << std::right << "First Name" << '|';
	std::cout << std::setw(10) << std::right << "Last Name" << '|';
	std::cout << std::setw(10) << std::right << "Nickname" << std::endl;
	for (int i = 0; i < this->_nContacts; i++) {
		std::cout << std::setw(10) << std::right << i << '|';
		this->_contacts[ i ].displayInfo();
	}
}

/**
 * -increase _contactIdx by one each time add is called
 * -reset _contactIdx to 0 if MAX_CONTACTS is reached
 * -increase _nContacts by one each time add is called,
 * as long as MAX_CONTACTS is not reached
*/
void	PhoneBook::add() {
	(this->_contactIdx)++;
	if (this->_nContacts < MAX_CONTACTS)
		(this->_nContacts)++;
	if (this->_contactIdx == MAX_CONTACTS)
		this->_contactIdx = 0;
	(this->_contacts[ this->_contactIdx ]).setAttributes();
}

void	PhoneBook::search() const {
	std::string		line;
	int				idxFromUser;
	
	if (!this->_nContacts) {
		std::cout << "No contacts in phonebook" << std::endl;
		return;
	}
	
	this->_listEntries();
	std::cout << std::endl 
		<< "Please enter index of contact you want more details"
	 	<< std::endl;
	while (1) {
		std::getline(std::cin, line);
		idxFromUser = (int)line[ 0 ] - '0';
		if (line.length() == 1 && idxFromUser >= 0 && idxFromUser < this->_nContacts)
			break;
		std::cout << "Please enter a valid index" << std::endl;
	}
	(this->_contacts[ idxFromUser ]).displayContact();
}
