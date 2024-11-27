/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:04:06 by provira-          #+#    #+#             */
/*   Updated: 2024/11/27 08:04:08 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

/*
 * Function: ft_strlen
 * --------------------
 * Calculates the length of a string.
 *
 * Parameters:
 * - char *str: The input string.
 *
 * Returns:
 * - The length of the string (number of characters before
 *   the null terminator).
 */
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

/*
 * Function: ft_strdup
 * --------------------
 * Creates a duplicate of a string by allocating memory for it.
 *
 * Parameters:
 * - char *src: The source string to duplicate.
 *
 * Returns:
 * - A pointer to the newly allocated duplicate string, or NULL if memory allocation fails.
 */
char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;
	int		len;

	len = ft_strlen(src);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*
 * Function: ft_strs_to_tab
 * -------------------------
 * Converts an array of strings into an array of `t_stock_str` structures.
 *
 * Parameters:
 * - int ac: The number of strings in the array `av`.
 * - char **av: The array of strings to convert.
 *
 * Returns:
 * - A pointer to an array of `t_stock_str` structures, or NULL if memory allocation fails.
 *
 * Notes:
 * - The function creates a copy of each string in `av` for the `copy` member of the structure.
 * - If memory allocation for any `copy` fails, all allocated memory is freed, and the function returns NULL.
 * - The last element of the array is a sentinel with `str` set to `0`.
 */
t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*array;
	int			i;

	array = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		array[i].size = ft_strlen(av[i]);
		array[i].str = av[i];
		array[i].copy = ft_strdup(av[i]);
		if (array[i].copy == NULL)
		{
			while (i-- > 0)
				free(array[i].copy);
			free(array);
			return (NULL);
		}
		i++;
	}
	array[i].str = 0;
	return (array);
}
