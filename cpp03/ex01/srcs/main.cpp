/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:56:59 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/17 13:26:46 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  ScavTrap leon("leon");
  ScavTrap Dieter("dieter");
  ClapTrap heinrich("heinrich");
  std::cout << heinrich << std::endl;
  std::cout << leon << std::endl;

  ScavTrap leonDuplicate(leon);
  std::cout << leonDuplicate.getName() << std::endl;

  leonDuplicate = Dieter;
  std::cout << leonDuplicate.getName() << std::endl;

  leon.attack("everone in the room");
  leon.guardGate();
  //heinrich.guardGate() not possible
  return (EXIT_SUCCESS);
}
