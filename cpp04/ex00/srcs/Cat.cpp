/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:56:28 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/30 14:20:48 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
  type = "cat";
  std::cout << "Created a cat with the standard constructor." << std::endl;
}

Cat::~Cat() {
  std::cout << "Killed a cat with the standard destructor." << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Miau" << std::endl;
}
