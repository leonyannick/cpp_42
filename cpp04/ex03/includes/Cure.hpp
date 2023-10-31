/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:48:29 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/31 12:48:59 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <iostream>

class Cure : public AMateria
{
public:
	Cure();
	Cure(Cure const & src);
	~Cure();

	Cure &operator=(Cure const & rhs);
	virtual AMateria* clone() const;
	//virtual void use(ICharacter& target);
private:
	
};

std::ostream &		operator<<(std::ostream & o, Cure const & i);
#endif
