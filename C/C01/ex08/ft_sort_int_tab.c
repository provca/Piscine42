/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:15:31 by provira-          #+#    #+#             */
/*   Updated: 2024/10/25 14:16:30 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_sort_int_tab
 * -------------------------
 * Sorts an integer array in ascending order using the bubble sort algorithm.
 *
 * Syntax:
 * void ft_sort_int_tab(int *tab, int size)
 *
 * Arguments:
 * - int *tab: Pointer to the array of integers to be sorted.
 * - int size: The number of elements in the array.
 *
 * Returns:
 * - This function does not return a value; it modifies the array directly.
 *
 * Notes:
 * - This implementation uses bubble sort, 
 *   which repeatedly swaps adjacent elements
 *   if they are in the wrong order, iterating until the array is sorted.
 * - The variable `sorted` is set to 1 when
 *   no swaps are made during an iteration,
 *   which breaks the loop and confirms that the array is sorted.
 * - This function will return immediately if the array has 1 or fewer elements.
 *
 * Example:
 * int arr[] = {3, 1, 4, 1, 5};
 * ft_sort_int_tab(arr, 5);  // arr is now {1, 1, 3, 4, 5}
 */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;
	int	sorted;

	if (size <= 1)
		return ;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				sorted = 0;
			}
			i++;
		}
		size--;
	}
}
