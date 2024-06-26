/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:36:27 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/30 16:29:46 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"

# include <iostream>
# include <string>

class Cat : public AAnimal
{
public:
	Cat();
	~Cat();
	
	Cat(Cat const & src);
	Cat &operator=(Cat const & rhs);

	virtual void makeSound() const;
private:
	Brain *_brain;
};

#endif
