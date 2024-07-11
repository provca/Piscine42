/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:08:35 by provira-          #+#    #+#             */
/*   Updated: 2024/07/11 18:08:37 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_iterative_factorial()
 * ----------------------------------
 * Computes the factorial of a non-negative integer using an iterative approach.
 *
 * Syntax:
 * int ft_iterative_factorial(int nb)
 *
 * Arguments:
 * - int nb: The non-negative integer whose factorial is to be computed.
 *
 * Returns:
 * - The factorial of the input integer. Returns 0 if the input is negative.
 *
 * Examples:
 * - ft_iterative_factorial(5) -> 120
 * - ft_iterative_factorial(0) -> 1
 * 
 * Notes:
 * - nb *= --i; ---> nb = nb * (i - 1);
 */
int	ft_iterative_factorial(int nb)
{
	int	i;

	i = nb;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	while (i > 1)
		nb *= --i;
	return (nb);
}
