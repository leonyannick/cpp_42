/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:30:24 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/27 22:02:19 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria(std::string const & type) {
  this->type = type;
  std::cout << "Materia type has been set to: " << type << std::endl;
}

std::string const & AMateria::getType() const {
  return (type);
}
