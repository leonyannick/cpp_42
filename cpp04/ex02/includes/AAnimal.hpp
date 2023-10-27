/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:09:48 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/27 21:12:36 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAAnimal_HPP
#define AAAnimal_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class AAnimal
{
public:
  AAnimal(AAnimal const & src);

  AAnimal &operator=(AAnimal const & rhs);

  std::string getType() const;
  virtual void makeSound() const = 0;

  virtual ~AAnimal();


protected:
  AAnimal();
  std::string type;
};

std::ostream &		operator<<(std::ostream & o, AAnimal const & i);

#endif
