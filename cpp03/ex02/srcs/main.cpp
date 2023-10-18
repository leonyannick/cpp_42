/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:56:59 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/17 13:47:10 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/FragTrap.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  FragTrap leon("leon");
  FragTrap Dieter("dieter");
  ClapTrap heinrich("heinrich");
  std::cout << heinrich << std::endl;
  std::cout << leon << std::endl;

  FragTrap leonDuplicate(leon);
  std::cout << leonDuplicate.getName() << std::endl;

  leonDuplicate = Dieter;
  std::cout << leonDuplicate.getName() << std::endl;
  leonDuplicate.setName("dietercopiedtoleonduplicate");

  leon.highFivesGuys();
  //heinrich.guardGate() not possible
  return (EXIT_SUCCESS);
}
