/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:05:34 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/18 16:06:16 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() {
  type = "dog";
  std::cout << "Created a dog with the standard constructor." << std::endl;
}

Dog::~Dog() {
  std::cout << "Killed a dog with the standard destructor." << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Wuff" << std::endl;
}
