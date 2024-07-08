/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:21:13 by provira-          #+#    #+#             */
/*   Updated: 2024/07/06 15:32:56 by provira-         ###   ########.fr       */
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
