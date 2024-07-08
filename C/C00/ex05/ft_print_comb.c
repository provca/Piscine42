/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:34:56 by provira-          #+#    #+#             */
/*   Updated: 2024/07/05 16:23:52 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
 * Function: ft_putchars(char a, char b, char c)
 * --------------------------------------------
 * Writes three characters followed by a comma and space 
 * if the first character is not '7'.
 * 
 * Syntax:
 * void ft_putchars(char a, char b, char c)
 * 
 * Arguments:
 * - char a: The first character to be written.
 * - char b: The second character to be written.
 * - char c: The third character to be written.
 * 
 * Returns:
 * - None
 * 
 * Examples:
 * - ft_putchars('0', '1', '2') -> "012, "
 * - (prints "012, " to the standard output)
 */
void	ft_putchars(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a != '7')
	{
		write(1, ", ", 2);
	}
}

/*
 * Function: ft_print_comb()
 * -------------------------
 * Prints all unique combinations of three digits in ascending order,
 * separated by commas.
 * 
 * Syntax:
 * void ft_print_comb(void)
 * 
 * Arguments:
 * - None
 * 
 * Returns:
 * - None
 * 
 * Examples:
 * - ft_print_comb() -> "012, 013, 014, ..., 789"
 * - (prints all combinations to the standard output)
 */

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	b = '1';
	c = '2';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				ft_putchars(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
