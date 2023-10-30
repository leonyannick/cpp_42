/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:04:55 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/30 16:29:50 by lbaumann         ###   ########.fr       */
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

	Dog(Dog const & src);
	Dog &operator=(Dog const & rhs);

	virtual void makeSound() const;
	void	memorize(std::string memory);
	void	retrieve() const;
private:
	Brain *_brain;
};

#endif
