/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:26:20 by provira-          #+#    #+#             */
/*   Updated: 2024/07/06 10:39:23 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
 * Function: ft_putchars(int n)
 * -----------------------------
 * Writes two digits corresponding to the given integer `n`
 * to the standard output.
 * 
 * Syntax:
 * void ft_putchars(int n)
 * 
 * Arguments:
 * - int n: The integer to be converted and written.
 * 
 * Returns:
 * - None
 * 
 * Examples:
 * - ft_putchars(23) -> "23" (prints "23" to the standard output)
 */
void	ft_putchars(int n)
{
	char	d;
	char	m;

	d = (n / 10) + '0';
	m = (n % 10) + '0';
	write(1, &d, 1);
	write(1, &m, 1);
}

/*
 * Function: ft_print_comb2()
 * --------------------------
 * Prints all unique pairs of two-digit numbers in ascending order,
 * separated by spaces and commas.
 * 
 * Syntax:
 * void ft_print_comb2(void)
 * 
 * Arguments:
 * - None
 * 
 * Returns:
 * - None
 * 
 * Examples:
 * - ft_print_comb2() -> "00 01, 00 02, ..., 98 99"
 * - (prints all pairs to the standard output)
 */
void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_putchars(a);
			write(1, " ", 1);
			ft_putchars(b);
			if (a <= 97)
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}
