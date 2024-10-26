/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:45:58 by provira-          #+#    #+#             */
/*   Updated: 2024/10/25 14:46:05 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_find_next_prime
 * -------------------------------
 * Finds the next prime number greater than or equal to a given number.
 *
 * Syntax:
 * int ft_find_next_prime(int nb)
 *
 * Arguments:
 * - int nb: The number from which to find the next prime.
 *
 * Returns:
 * - The next prime number greater than or equal to nb.
 *
 * Function details:
 * - The function continuously checks if the current number is prime
 *   by calling the `is_prime()` function.
 * - If the number is not prime, it increments the number and checks again.
 * - This continues until a prime number is found, which is then returned.
 *
 * Supporting function:
 * - is_prime(): Checks if a given number is prime by testing divisibility
 *   from 2 up to the square root of the number.
 *
 * Example:
 * int next_prime = ft_find_next_prime(10);
 * // next_prime will be 11, the next prime number after 10.
 */
#include <unistd.h>

int	is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (is_prime(nb) == 0)
		nb++;
	return (nb);
}
