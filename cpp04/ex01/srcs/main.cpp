/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:56:59 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/27 21:07:31 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  const Animal* j = new Dog();
  const Animal* i = new Cat();


  delete j;
  //should not create a 
  // delete i;

  // const Cat* Katze = new Cat();
  // delete Katze;
  
  return (EXIT_SUCCESS);
}
