/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:05:29 by provira-          #+#    #+#             */
/*   Updated: 2024/11/27 08:05:33 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

/*
 * File: ft_stock_str.h
 * ---------------------
 * This header file defines the structure `s_stock_str` used to store a string,
 * its length, and a copy of the string. The include guard ensures the header
 * is only included once in the compilation process.
 */

/*
 * Struct: s_stock_str
 * --------------------
 * Represents a structure to hold information about a string.
 *
 * Members:
 * - int size: The length of the string `str`.
 * - char *str: A pointer to the original string.
 * - char *copy: A pointer to a duplicate of the original string.
 *
 * Typedef:
 * - t_stock_str: An alias for `struct s_stock_str`.
 *
 * Example:
 * t_stock_str my_struct;
 * my_struct.size = 5;
 * my_struct.str = "Hello";
 * my_struct.copy = "Hello";
 */
typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;

#endif
