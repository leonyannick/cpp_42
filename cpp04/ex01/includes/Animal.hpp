/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:09:48 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/27 21:08:19 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
public:
  Animal(Animal const & src);
  virtual ~Animal();

  Animal &operator=(Animal const & rhs);

  std::string getType() const;
  virtual void makeSound() const;



protected:
  Animal();
  std::string type;
};

std::ostream &		operator<<(std::ostream & o, Animal const & i);

#endif
