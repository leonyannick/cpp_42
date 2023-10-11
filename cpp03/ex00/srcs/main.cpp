/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:56:59 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/11 19:32:19 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  ClapTrap leon("Leon");
  ClapTrap dieter("Dieter");
  ClapTrap heinrich(leon);
  //ClapTrap günther(); should not work because standard constructor is private

  std::cout << leon.getName() << std::endl;
  std::cout << dieter.getName() << std::endl;

  dieter = leon;

  std::cout << dieter.getName() << std::endl;
  std::cout << "heinrich copy constructor with leon: " << heinrich.getName() << std::endl;

  std::cout << leon << std::endl;
  leon.attack("Dieter");
  std::cout << leon << std::endl;
  leon.takeDamage(1);
  std::cout << leon << std::endl;
  leon.beRepaired(2);
  std::cout << leon << std::endl;
  leon.takeDamage(12);
  std::cout << leon << std::endl;
  leon.beRepaired(1);
  leon.attack("Heinrich");

  for (size_t i = 0; i < 10; i++) {
    dieter.beRepaired(1);
  }
  std::cout << dieter << std::endl;
  dieter.beRepaired(1);
  dieter.attack("Leon");
  
  
  return (EXIT_SUCCESS);
}
