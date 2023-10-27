/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:56:59 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/27 21:26:57 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  const AAnimal* j = new Cat();


  //should not create a 
  // delete i;

  // const Cat* Katze = new Cat();
  // delete Katze;
  
  return (EXIT_SUCCESS);
}
