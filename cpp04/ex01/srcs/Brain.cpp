/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:08:35 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/30 16:19:46 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Created Brain." << std::endl;
}

Brain::Brain(Brain const &src)
{
//assign attributes
//or use definition from copy assignment operator
  *this = src;
}

Brain::~Brain()
{
	std::cout << "Destroyed Brain." << std::endl;
}

Brain &Brain::operator=(Brain const &rhs)
{
	if (this != &rhs)
		{
			for (size_t i = 0; i < 100; i++)
			{
				ideas[i] = rhs.ideas[i];
			}
			
		}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Brain const &i)
{
	(void)i;
	o << "a lot of ideas.";
	return (o);
}

void Brain::saveMemory(const std::string& memory) {
	ideas[0] = memory;
}

std::string Brain::retrieveMemory() const { return (ideas[0]); }
