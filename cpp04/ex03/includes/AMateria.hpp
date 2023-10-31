/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:29:58 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/31 12:17:59 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
private:
  AMateria();

protected:
  std::string type;

public:
  AMateria(std::string const & type);

  virtual ~AMateria();

  std::string const & getType() const; //Returns the materia type

  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);
};

#endif
