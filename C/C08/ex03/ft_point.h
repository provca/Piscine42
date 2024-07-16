/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:22:53 by provira-          #+#    #+#             */
/*   Updated: 2024/07/16 17:22:54 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Header: FT_POINT_H
 * -----------------
 * Defines a structure `t_point` representing a point with integer coordinates.
 *
 * Structure:
 * - typedef struct s_point: Defines a structure named `s_point`
 *   with two members:
 *   - int x: Represents the x-coordinate of the point.
 *   - int y: Represents the y-coordinate of the point.
 * - typedef t_point: Alias `t_point` for `struct s_point`.
 *
 * Usage:
 * - This header allows programs to work with points in a Cartesian 
 *   coordinate system.
 * - Example usage:
 *   ```
 *   t_point pt1 = {10, 20};
 *   pt1.x = 15;
 *   printf("Coordinates: (%d, %d)\n", pt1.x, pt1.y);
 *   ```
 *   This snippet declares a point `pt1` with coordinates (10, 20), 
 *   updates the x-coordinate, and prints the coordinates using printf.
 */
#ifndef FT_POINT_H
# define FT_POINT_H

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

#endif
