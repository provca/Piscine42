/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:23:12 by provira-          #+#    #+#             */
/*   Updated: 2024/07/11 19:23:14 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_recursive_power()
 * ------------------------------
 * Computes the power of a number using a recursive approach.
 *
 * Syntax:
 * int ft_recursive_power(int nb, int power)
 *
 * Arguments:
 * - int nb: The base number.
 * - int power: The exponent to which the base number is to be raised.
 *
 * Returns:
 * - The result of raising the base number to the given power.
 *   Returns 1 if the power is 0.
 *   Returns 0 if the power is negative or if the base number is 0
 *   (except when power is 0).
 *
 * Examples:
 * - ft_recursive_power(2, 3) -> 8
 * - ft_recursive_power(5, 0) -> 1
 * - ft_recursive_power(0, 5) -> 0
 */
int	ft_recursive_power(int nb, int power)
{
	if (nb == 0 || power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
