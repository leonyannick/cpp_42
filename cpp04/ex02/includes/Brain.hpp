/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:01:19 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/20 22:08:28 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

#include <iostream>

class Brain
{
public:
	Brain();
	Brain(Brain const & src);
	~Brain();

	Brain &operator=(Brain const & rhs);
private:
	std::string ideas[100];
};

std::ostream &		operator<<(std::ostream & o, Brain const & i);

#endif
