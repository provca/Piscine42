/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 06:13:08 by provira-          #+#    #+#             */
/*   Updated: 2024/07/15 06:13:09 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_ultimate_range
 * ---------------------------
 * Allocates memory and creates an array of integers containing values from
 * min to max (excluding max).
 *
 * Syntax:
 * int ft_ultimate_range(int **range, int min, int max)
 *
 * Arguments:
 * - int **range: Pointer to a pointer that will be set to point to the newly
 *   allocated array.
 * - int min: The starting value (inclusive).
 * - int max: The ending value (exclusive).
 *
 * Returns:
 * - The size of the range (number of elements in the array).
 * - If min >= max, returns 0 and sets *range to NULL.
 * - If memory allocation fails, returns -1.
 *
 * Example:
 * - int *array;
 * - int size = ft_ultimate_range(&array, 5, 10); 
 *   // array contains {5, 6, 7, 8, 9}, size is 5
 *
 * Notes:
 * - This function provides more detailed error handling and 
 *   returns the size of the array.
 * - It uses a double pointer to modify the caller's pointer, 
 *   allowing for dynamic memory allocation within the function.
 * - Use this function when you need more control over memory
 *    allocation and error handling.
 */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;
	int	*int_array;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	size = max - min;
	int_array = (int *)malloc(size * sizeof(int));
	if (int_array == NULL)
		return (-1);
	while (i < size)
	{
		int_array[i] = i + min;
		i++;
	}
	*range = int_array;
	return (i);
}
