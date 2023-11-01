/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:04:12 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/31 15:28:17 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : _numberValue(0) {
  std::cout << "Default constructor called" << std::endl;
}

/**
 * different implementation using the copy assigment operator also possible
*/
Fixed::Fixed(Fixed const &src) {
  std::cout << "Copy constructor called" << std::endl;
//   this->setRawBits(src.getRawBits());
	*this = src;
}

/**
 * self-assignment is possible in c++ -> in cases where the assignment
 * operator allocates memory it can be dangerous, so a check is important
 * (here it is not necessary)
 */
Fixed &Fixed::operator=(Fixed const &rhs) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &rhs)
  	this->setRawBits(rhs.getRawBits());
  return (*this);
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return (_numberValue);
}

void Fixed::setRawBits(int const raw) {
//   std::cout << "setRawBits member function called" << std::endl;
  _numberValue = raw;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i) {
  o << i.getRawBits();
  return (o);
}
