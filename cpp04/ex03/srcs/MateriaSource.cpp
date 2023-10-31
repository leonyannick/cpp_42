/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:59:03 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/31 14:52:55 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _storageIdx(0) {
	for (int i = 0; i < 4; i++) {
    	_storage[i] = 0;
    }
	// std::cout << "Materia source created." << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
//assign attributes
//or use definition from copy assignment operator
	*this = src;
}

MateriaSource::~MateriaSource() {
	// std::cout << "Deleting MateriaSource and deleting storage" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		if (_storage[i])
			delete _storage[i];
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
	if (this != &rhs)
		{
			_storageIdx = rhs._storageIdx;
			for (size_t i = 0; i < 4; i++)
			{
				delete _storage[i];
				_storage[i] = rhs._storage[i]->clone();
			}
		}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* src) {
	if (_storageIdx >= 0 && _storageIdx < 4)
	{
		_storage[_storageIdx] = src;
		_storageIdx++;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (size_t i = 0; i < 4; i++)
	{
		if (_storage[i] && type == _storage[i]->getType())
			return (_storage[i]->clone());
	}
	// std::cout << "Materia type unknown" << std::endl;
	return (0); 
}
