/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:56:59 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/06 17:56:41 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  Point a(1, 1);
  Point b(a);
  Point c(2, 2);
  c = a;
  //Point c = a;
  std::cout << "a " << a << std::endl;
  std::cout << "b " << b << std::endl;
  std::cout << "c initial " << c << std::endl;
  std::cout << "a assigned to c " << c << std::endl;
  std::cout << "a " << a << std::endl;
  
  Point one(0, 0);
  Point two(0, 50);
  Point three(50, 0);
  Point d(0, 0);
  std::cout << "point(0, 0) on border: " << bsp(one, two, three, d) << std::endl;

  Point e(0, 50.01);
  std::cout << "point(50.01, 0) outside " << bsp(one, two, three, e) << std::endl;

  Point f(0, 50.001);
  std::cout << "point(50.001, 0) outside, but imprecision " << bsp(one, two, three, f) << std::endl;

  Point g(20, 20);
  std::cout << "point(20, 20) inside " << bsp(one, two, three, g) << std::endl;
  
  return (EXIT_SUCCESS);
}
