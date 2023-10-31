/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:56:59 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/31 14:54:57 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <cstdlib>
#include <iostream>

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	ICharacter* bob = new Character("bob");
	
	me->equip(tmp);
	me->use(0, *bob);
	
	//unequiped materia has to be manually deleted
	me->unequip(0);
	delete tmp;
	
	tmp = src->createMateria("cure");
	me->equip(tmp);

	//not created
	tmp = src->createMateria("unknown");
	
	
	me->use(2, *bob);
	me->use(0, *bob); //not output again because unequiped
	me->use(1, *bob);

	
	delete bob;
	delete me;
	delete src;
	
	return 0;
}

