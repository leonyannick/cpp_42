/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:56:59 by lbaumann          #+#    #+#             */
/*   Updated: 2023/11/07 13:07:45 by lbaumann         ###   ########.fr       */
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

	Dog a;
	a.memorize("bones");
	Dog b;
	b.memorize("postmen");
	std::cout << "a: ";
	a.retrieve();
	std::cout << "b: ";
	b.retrieve();


	a = b;

	std::cout << "a after a = b: ";
	a.retrieve();
	std::cout << "b after a = b: ";
	b.retrieve();

  delete j;
  delete i;

  const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
  for ( int i = 0; i < 4; i++ ) {
		delete animals[i];
    }
  
  return (EXIT_SUCCESS);
}
