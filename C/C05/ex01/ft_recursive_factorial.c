/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:38:13 by provira-          #+#    #+#             */
/*   Updated: 2024/07/11 18:38:15 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_recursive_factorial()
 * ----------------------------------
 * Computes the factorial of a non-negative integer using a recursive approach.
 *
 * Syntax:
 * int ft_recursive_factorial(int nb)
 *
 * Arguments:
 * - int nb: The non-negative integer whose factorial is to be computed.
 *
 * Returns:
 * - The factorial of the input integer. Returns 0 if the input is negative.
 *
 * Examples:
 * - ft_recursive_factorial(5) -> 120
 * - ft_recursive_factorial(0) -> 1
 */
int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else if (nb > 0)
		return (nb * ft_recursive_factorial(nb - 1));
	return (nb);
}
