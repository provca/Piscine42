/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:46:00 by provira-          #+#    #+#             */
/*   Updated: 2024/07/10 10:46:04 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

/*
 * Function: ft_putnbr(int nb)
 * ---------------------------
 * Writes the integer `nb` to the standard output.
 * 
 * Syntax:
 * void ft_putnbr(int nb)
 * 
 * Arguments:
 * - int nb: The integer to be written.
 * 
 * Returns:
 * - None
 * 
 * Examples:
 * - ft_putnbr(123) -> "123" (prints "123" to the standard output)
 * - ft_putnbr(-456) -> "-456" (prints "-456" to the standard output)
 * - ft_putnbr(INT_MIN) -> "-2147483648"
 * - (prints "-2147483648" to the standard output)
 */
void	ft_putnbr(int nb)
{
	char	n;

	if (nb == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(nb * -1);
	}
	else if (nb <= 9)
	{
		n = nb + '0';
		write(1, &n, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
