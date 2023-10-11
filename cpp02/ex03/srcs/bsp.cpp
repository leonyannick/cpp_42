/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:23:56 by lbaumann          #+#    #+#             */
/*   Updated: 2023/10/07 13:26:20 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

/**
 * calculate area of triangle spanned by points a, b, c
 * 
 * using coordinates formula: https://en.wikipedia.org/wiki/Area_of_a_triangle
 * 
 * sign area before returning -> returned area is always positive
*/
static float areaTriangle(Point const a, Point const b, Point const c)
{
	float	area;

	area = 0.5 * ( ( a.getX() - c.getX() ) * ( b.getY() - a.getY() ) 
		- ( a.getX() - b.getX() ) * ( c.getY() - a.getY() ) );
	if (area < 0)
		area = -area;
	return (area);
}

/**
 * Returns: True if the point is inside the triangle. False otherwise. 
 * Thus, if the point is a vertex or on edge, it will return False.
 * 
 * calculate area of subtriangles. point is inside if area if
 * subtriangles areas equals area of triangle abc
 * 
 * point is vertex or on edge if area of one of the subtriangles
 * is 0 
*/
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float area_pab = areaTriangle(point, a, b);
	float area_pac = areaTriangle(point, a, c);
	float area_pbc = areaTriangle(point, b, c);
	
	if (!area_pab || !area_pac || !area_pbc)
		return (false);
	
	float area_abc = areaTriangle(a, b, c);
	
	if ((area_pab + area_pac + area_pbc) == area_abc)
		return (true);
	return (false);
}
