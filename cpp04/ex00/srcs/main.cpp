/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:56:59 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/30 14:25:41 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  
  std::cout << "should be a cat: " << j->getType() << " " << std::endl;
  std::cout << "should be a dog: " << i->getType() << " " << std::endl;
  
  std::cout << "Catsound: ";
  i->makeSound(); //will output the cat sound! j->makeSound();
  
  std::cout << "abstractanimal sound: ";
  meta->makeSound();

  const WrongAnimal * fake = new WrongCat();
  fake->makeSound();

  delete j;
  delete meta;
  delete i;
  delete fake;
  
  return (EXIT_SUCCESS);
}
