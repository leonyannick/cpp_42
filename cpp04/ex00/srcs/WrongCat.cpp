/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:09:48 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/30 14:10:12 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() {
  type = "WrongCat";
  std::cout << "Created a WrongCat with the standard constructor." << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << "Killed a WrongCat with the standard destructor." << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Miau" << std::endl;
}
