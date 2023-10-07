/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:05:08 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/06 17:43:06 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(float const x, float const y);
	Point(Point const & src);
	~Point();

	float	getX() const;
	float	getY() const;

	Point &operator=(Point const & rhs);
private:
	Fixed const _x;
	Fixed const _y;
};

std::ostream &		operator<<(std::ostream & o, Point const & i);

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
