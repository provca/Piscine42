/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:36:11 by provira-          #+#    #+#             */
/*   Updated: 2024/07/06 15:46:20 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_div_mod(int a, int b, int *div, int *mod)
 * ------------------------------------------------------
 * Computes the quotient and remainder of the division of `a` by `b`.
 * 
 * Syntax:
 * void ft_div_mod(int a, int b, int *div, int *mod)
 * 
 * Arguments:
 * - int a: The dividend.
 * - int b: The divisor (must not be zero).
 * - int *div: A pointer to an integer to store the quotient.
 * - int *mod: A pointer to an integer to store the remainder.
 * 
 * Returns:
 * - None
 * 
 * Examples:
 * - int x = 10, y = 3, quotient, remainder;
 *   ft_div_mod(x, y, &quotient, &remainder); // quotient = 3, remainder = 1
 */
void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b == 0)
		return ;
	*div = a / b;
	*mod = a % b;
}
