/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:09:48 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/31 15:29:46 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>


class Fixed {
public:
  Fixed();
  
  //copy constructor
  Fixed(Fixed const &src);
  Fixed(int const number);
  Fixed(float const number);
  ~Fixed();

  Fixed &operator=(Fixed const &rhs);

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
