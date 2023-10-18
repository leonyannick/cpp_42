/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:04:55 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/18 16:05:23 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

# include <iostream>
# include <string>

class Dog : public Animal
{
public:
	Dog();
	~Dog();

	virtual void makeSound() const;
};

#endif
