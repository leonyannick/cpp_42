/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:40:15 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/31 12:22:59 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <iostream>

class Ice : public AMateria
{
public:
	Ice();
	Ice(Ice const & src);
	~Ice();

	Ice &operator=(Ice const & rhs);
	virtual AMateria* clone() const;
	//virtual void use(ICharacter& target);
private:
	
};

std::ostream &		operator<<(std::ostream & o, Ice const & i);
#endif
