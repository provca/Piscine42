/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 05:57:01 by provira-          #+#    #+#             */
/*   Updated: 2024/07/15 05:57:04 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_range
 * ------------------
 * Creates an array of integers containing values from min to max 
 * (excluding max).
 *
 * Syntax:
 * int *ft_range(int min, int max)
 *
 * Arguments:
 * - int min: The starting value (inclusive).
 * - int max: The ending value (exclusive).
 *
 * Returns:
 * - A pointer to an array of integers containing values from min to max - 1.
 * - If min >= max or if memory allocation fails, returns NULL.
 *
 * Example:
 * - int *array = ft_range(5, 10); // array contains {5, 6, 7, 8, 9}
 *
 * Notes:
 * - This function allocates memory dynamically for the array.
 *   The caller is responsible for freeing the memory.
 * - This function is simpler and returns the array directly.
 *   Use it when you don't need detailed error handling or the size of the array.
 */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	size;
	int	*int_array;

	if (min >= max)
		return (NULL);
	i = 0;
	size = max - min;
	int_array = (int *)malloc(size * sizeof(int));
	if (int_array == NULL)
		return (NULL);
	while (i < size)
	{
		int_array[i] = i + min;
		i++;
	}
	return (int_array);
}
