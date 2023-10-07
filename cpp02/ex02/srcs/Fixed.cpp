/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:04:12 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/03 12:42:49 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : _numberValue(0) {
  //std::cout << "Default constructor called" << std::endl;
}

/**
 * different implementation using the copy assigment operator also possible
*/
Fixed::Fixed(Fixed const &src) {
  //std::cout << "Copy constructor called" << std::endl;
  this->setRawBits(src.getRawBits());
	// *this = src;
}

Fixed::Fixed(int const number) 
  : _numberValue(number << _numberFractionalBits) {
  //std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const number)
  : _numberValue(roundf(number * (1 << _numberFractionalBits))){
  //std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() { 
  //std::cout << "Destructor called" << std::endl;
}

/**
 * self-assignment is possible in c++ -> in cases where the assignment
 * operator allocates memory it can be dangerous, so a check is important
 * (here it is not necessary)
 */
Fixed &Fixed::operator=(Fixed const &rhs) {
  //std::cout << "Copy assignment operator called" << std::endl;
  if (this != &rhs)
  	this->setRawBits(rhs.getRawBits());
  return (*this);
}

Fixed &Fixed::operator+(Fixed const &rhs) {
  this->setRawBits(this->getRawBits() + rhs.getRawBits());
  return (*this);
}

Fixed &Fixed::operator-(Fixed const &rhs) {
  this->setRawBits(this->getRawBits() - rhs.getRawBits());
  return (*this);
}

Fixed &Fixed::operator*(Fixed const &rhs) {
  Fixed res(this->toFloat() * rhs.toFloat());
  this->setRawBits(res.getRawBits());
  return (*this);
}

Fixed &Fixed::operator/(Fixed const &rhs) {
  Fixed res(this->toFloat() / rhs.toFloat());
  this->setRawBits(res.getRawBits());
  return (*this);
}

bool Fixed::operator>(Fixed const &rhs) const {
  if (this->toFloat() > rhs.toFloat())
    return (true);
  return (false);
}

bool Fixed::operator<(Fixed const &rhs) const {
  if (this->toFloat() < rhs.toFloat())
    return (true);
  return (false);
}

bool Fixed::operator>=(Fixed const &rhs) const {
  if (this->toFloat() >= rhs.toFloat())
    return (true);
  return (false);
}

bool Fixed::operator<=(Fixed const &rhs) const {
  if (this->toFloat() <= rhs.toFloat())
    return (true);
  return (false);
}

bool Fixed::operator==(Fixed const &rhs) const {
  if (this->toFloat() == rhs.toFloat())
    return (true);
  return (false);
}

bool Fixed::operator!=(Fixed const &rhs) const {
  return (!((*this)==rhs));
}

Fixed &Fixed::operator++() {
  this->setRawBits(this->getRawBits() + 1);
  return (*this);
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  operator++();
  return (tmp);
}

Fixed &Fixed::operator--() {
  this->setRawBits(this->getRawBits() - 1);
  return (*this);
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  operator--();
  return (tmp);
}

Fixed const &Fixed::max( Fixed const &a, Fixed const &b ) {
  if (a > b)
    return (a);
  return (b);
}

Fixed const &Fixed::min( Fixed const &a, Fixed const &b ) {
  if (a > b)
    return (b);
  return (a);
}

Fixed &Fixed::max( Fixed &a, Fixed &b ) {
  if (a > b)
    return (a);
  return (b);
}

Fixed &Fixed::min( Fixed &a, Fixed &b ) {
  if (a > b)
    return (b);
  return (a);
}

int Fixed::getRawBits(void) const {
  //std::cout << "getRawBits member function called" << std::endl;
  return (_numberValue);
}

void Fixed::setRawBits(int const raw) {
  //std::cout << "setRawBits member function called" << std::endl;
  _numberValue = raw;
}

float Fixed::toFloat( void ) const {
  return ((float)_numberValue / (float)(1 << _numberFractionalBits));
}

int Fixed::toInt( void ) const {
  return (_numberValue >> _numberFractionalBits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &i) {
  o << i.toFloat();
  return (o);
}
