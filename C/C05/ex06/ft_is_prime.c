/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:55:58 by provira-          #+#    #+#             */
/*   Updated: 2024/07/11 20:56:02 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_is_prime()
 * -----------------------
 * Checks if a given number is a prime number.
 *
 * Syntax:
 * int ft_is_prime(int nb)
 *
 * Arguments:
 * - int nb: The number to check for primality.
 *
 * Returns:
 * - 1 if the number is a prime number.
 * - 0 if the number is not a prime number.
 *
 * Examples:
 * - ft_is_prime(1) -> 0
 * - ft_is_prime(2) -> 1
 * - ft_is_prime(3) -> 1
 * - ft_is_prime(4) -> 0
 * - ft_is_prime(17) -> 1
 */
int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	i = 3;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

/*
int	ft_is_prime(int nb)
{
	int	i;
	int	is_prime;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	i = 1;
	is_prime = 0;
	while (i <= nb)
	{
		if (nb % i == 0)
			is_prime++;
		i++;
	}
	if (is_prime == 2)
		return (1);
	return (0);
}*/