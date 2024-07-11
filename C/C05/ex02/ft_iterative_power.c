/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:57:17 by provira-          #+#    #+#             */
/*   Updated: 2024/07/11 18:57:19 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_iterative_power()
 * ------------------------------
 * Computes the power of a number using an iterative approach.
 *
 * Syntax:
 * int ft_iterative_power(int nb, int power)
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
 * - ft_iterative_power(2, 3) -> 8
 * - ft_iterative_power(5, 0) -> 1
 * - ft_iterative_power(0, 5) -> 0
 */
int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (nb == 0)
		return (0);
	result = 1;
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}
