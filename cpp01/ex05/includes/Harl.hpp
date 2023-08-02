/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:43:26 by lbaumann          #+#    #+#             */
/*   Updated: 2023/08/02 12:15:52 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Harl_HPP
#define Harl_HPP

#include <iostream>

class Harl {

private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void ); 

public:
	void	complain( std::string level );
};

#endif
