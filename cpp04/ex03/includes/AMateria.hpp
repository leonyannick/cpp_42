/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:29:58 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/27 21:38:23 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMateria_HPP
#define AMateria_HPP

#include <iostream>
#include <string>

class AMateria
{
private:
  AMateria();

protected:
  std::string type;

public:
  AMateria(std::string const & type);

  std::string const & getType() const; //Returns the materia type
  
  virtual AMateria* clone() const = 0;
};

#endif
