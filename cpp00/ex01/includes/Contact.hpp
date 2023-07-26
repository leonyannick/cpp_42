/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:39:21 by lbaumann          #+#    #+#             */
/*   Updated: 2023/07/26 15:47:25 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iomanip>
#include <iostream>
#include <string>

class Contact
{

	/**
	 * prefix private attributes with '_'
	 */
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;

	/**
	 * displayConact is const because it doesnt change the Contact instance
	 */
public:
	void displayContact() const;
	void displayInfo() const;
	void setAttributes();
};
#endif
