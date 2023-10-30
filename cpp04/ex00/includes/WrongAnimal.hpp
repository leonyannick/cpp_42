/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:09:48 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/30 14:07:40 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
public:
  WrongAnimal();
  WrongAnimal(WrongAnimal const & src);
  ~WrongAnimal();

  WrongAnimal &operator=(WrongAnimal const & rhs);

  std::string getType() const;
  void makeSound() const;
protected:
  std::string type;
};

std::ostream &		operator<<(std::ostream & o, WrongAnimal const & i);

#endif
