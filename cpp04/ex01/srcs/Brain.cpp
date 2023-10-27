/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:08:35 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/20 22:08:53 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

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
	o << "a lot of ideas.";
	return (o);
}
