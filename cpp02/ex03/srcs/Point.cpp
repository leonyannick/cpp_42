/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:12:20 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/06 17:22:14 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::Point(Point const &src) : _x(src._x), _y(src._y) {}

Point::~Point() {}

Point &Point::operator=(Point const &rhs) {
	if (this != &rhs)
	{
		(Fixed) _x = rhs._x;
		(Fixed) _y = rhs._y;
	}
	return (*this);
}

float	Point::getX() const { return (_x.toFloat()); }
float	Point::getY() const { return (_y.toFloat()); }

std::ostream &operator<<(std::ostream &o, Point const &i)
{
	//o << <fill ostream with attributes>
	o << "x:" << i.getX() << " y:" << i.getY();
	return (o);
}
