/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:28:13 by provira-          #+#    #+#             */
/*   Updated: 2024/07/11 20:28:15 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_sqrt()
 * -------------------
 * Computes the square root of a given number using a recursive approach.
 *
 * Syntax:
 * int ft_sqrt(int nb)
 *
 * Arguments:
 * - int nb: The number for which to compute the square root.
 *           Must be a non-negative integer.
 *
 * Returns:
 * - The square root of the given number if it is a perfect square.
 *   Returns 0 if the number is negative or if it is not a perfect square.
 *
 * Examples:
 * - ft_sqrt(0) -> 0
 * - ft_sqrt(1) -> 1
 * - ft_sqrt(4) -> 2
 * - ft_sqrt(16) -> 4
 * - ft_sqrt(15) -> 0 (since 15 is not a perfect square)
 */
int	ft_sqrt_recursive(int nb, int guess)
{
	if (guess * guess == nb)
		return (guess);
	if (guess * guess > nb)
		return (0);
	return (ft_sqrt_recursive(nb, guess + 1));
}

int	ft_sqrt(int nb)
{
	if (nb < 0)
		return (0);
	return (ft_sqrt_recursive(nb, 0));
}

/*
int	ft_sqrt(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	i = 0;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		++i;
	}
	return (0);
}
*/