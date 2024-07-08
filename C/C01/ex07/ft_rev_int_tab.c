/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 05:59:08 by provira-          #+#    #+#             */
/*   Updated: 2024/07/08 10:07:33 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_swap(int *a, int *b)
 * ---------------------------------
 * Swaps the values of two integers pointed to by `a` and `b`.
 * 
 * Syntax:
 * void ft_swap(int *a, int *b)
 * 
 * Arguments:
 * - int *a: A pointer to the first integer.
 * - int *b: A pointer to the second integer.
 * 
 * Returns:
 * - None
 * 
 * Examples:
 * - int x = 10, y = 20;
 *   ft_swap(&x, &y); // x is now 20, y is now 10
 */
void	ft_swap(int *a, int *b)
{
	int	aux;

	aux = *b;
	*b = *a;
	*a = aux;
}

/*
 * Function: ft_rev_int_tab(int *tab, int size)
 * --------------------------------------------
 * Reverses the elements of the integer array `tab` of given `size`.
 * 
 * Syntax:
 * void ft_rev_int_tab(int *tab, int size)
 * 
 * Arguments:
 * - int *tab: A pointer to the integer array to be reversed.
 * - int size: The number of elements in the array `tab`.
 * 
 * Returns:
 * - None
 * 
 * Examples:
 * - int arr1[] = {1, 2, 3, 4, 5};
 *   ft_rev_int_tab(arr1, 5); // arr1 is now {5, 4, 3, 2, 1}
 * - int arr2[] = {10, 20, 30};
 *   ft_rev_int_tab(arr2, 3); // arr2 is now {30, 20, 10}
 */
void	ft_rev_int_tab(int *tab, int size)
{
	int	*aux;
	int	i;

	i = 0;
	aux = &tab[size - 1];
	while (i < (size / 2))
	{
		ft_swap(&tab[i], aux);
		i++;
		aux--;
	}
}
