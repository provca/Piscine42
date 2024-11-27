/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:09:35 by provira-          #+#    #+#             */
/*   Updated: 2024/11/27 08:09:37 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

/*
 * Header Guard:
 * -------------
 * Prevents multiple inclusions of this header file in a single translation unit,
 * which could otherwise cause redefinition errors.
 */
/*
 * Structure: s_stock_str
 * -----------------------
 * Represents a structure to store a string and its related information.
 *
 * Members:
 * - int size: The length of the string `str`.
 * - char *str: A pointer to the original string.
 * - char *copy: A pointer to a copy of the string `str`.
 *
 * Notes:
 * - This structure is used to handle strings with additional metadata,
 *   such as their size and a duplicate for safe manipulation.
 */
typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;

#endif
