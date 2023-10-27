/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:04:55 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/27 21:15:26 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"

# include <iostream>
# include <string>

class Dog : public AAnimal
{
public:
	Dog();
	~Dog();

	virtual void makeSound() const;
private:
	Brain *_brain;
};

#endif
