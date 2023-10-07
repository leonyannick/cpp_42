/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:56:59 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/06 17:15:04 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  std::cout << "Tests from subject:" << std::endl;
  Fixed a;
  Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max( a, b ) << std::endl;

  std::cout << "more tests:" << std::endl;
  Fixed c(4);
  std::cout << c << std::endl;
  c = c + 1.2f;
  std::cout << c << std::endl;
  std::cout << Fixed::min(a, c) << std::endl;
  
  Fixed d(2);
  Fixed e(2);
  std::cout << Fixed::min(d, e) << std::endl;

  if (d == e)
    std::cout << "d equals e" << std::endl;
  
  if (c != e)
    std::cout << "c does not equal e" << std::endl;

  if (d >= e && d <= e)
    std::cout << "d and e. less/greater equals" << std::endl;

  std::cout << "d divided by e: " << d / e << std::endl;
  std::cout << "--e: " << --e << std::endl;
  return (EXIT_SUCCESS);
}
