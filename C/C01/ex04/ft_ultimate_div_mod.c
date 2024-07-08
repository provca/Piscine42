/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:50:59 by provira-          #+#    #+#             */
/*   Updated: 2024/07/06 15:55:31 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_ultimate_div_mod(int *a, int *b)
 * ---------------------------------------------
 * Computes the quotient and remainder of the division of `*a` by `*b`,
 * and updates the values pointed to by `a` and `b` with the
 * quotient and remainder, respectively.
 * 
 * Syntax:
 * void ft_ultimate_div_mod(int *a, int *b)
 * 
 * Arguments:
 * - int *a: A pointer to an integer (will be updated with the quotient).
 * - int *b: A pointer to an integer (will be updated with the remainder).
 * 
 * Returns:
 * - None
 * 
 * Examples:
 * - int x = 10, y = 3;
 *   ft_ultimate_div_mod(&x, &y); // x is now 3, y is now 1
 */
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	quotient;
	int	remainder;

	if (b == 0)
		return ;
	quotient = *a / *b;
	remainder = *a % *b;
	*a = quotient;
	*b = remainder;
}
