/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:09:48 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/03 12:14:33 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

#include <iostream>

class Fixed {
public:
  Fixed();
  
  //copy constructor
  Fixed(Fixed const &src);
  Fixed(int const number);
  Fixed(float const number);
  ~Fixed();

  Fixed &operator=(Fixed const &rhs);
  Fixed &operator+(Fixed const &rhs);
  Fixed &operator-(Fixed const &rhs);
  Fixed &operator*(Fixed const &rhs);
  Fixed &operator/(Fixed const &rhs);

  bool operator>(Fixed const &rhs) const;
  bool operator<(Fixed const &rhs) const;
  bool operator>=(Fixed const &rhs) const;
  bool operator<=(Fixed const &rhs) const;
  bool operator==(Fixed const &rhs) const;
  bool operator!=(Fixed const &rhs) const;

  //pre
  Fixed &operator++();
  Fixed &operator--();
  //post
  Fixed operator++(int);
  Fixed operator--(int);

  //static members: are not bound to specific members of class
  //specific for static member functions: no this-pointer
  static Fixed const &max( Fixed const &a, Fixed const &b );
  static Fixed const &min( Fixed const &a, Fixed const &b );
  static Fixed &max( Fixed &a, Fixed &b );
  static Fixed &min( Fixed &a, Fixed &b );

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat( void ) const;
  int toInt( void ) const;

private:
  int _numberValue;
  static const int _numberFractionalBits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif
