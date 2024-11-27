/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:09:07 by provira-          #+#    #+#             */
/*   Updated: 2024/11/27 08:09:10 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

/*
 * Function: ft_putstr
 * --------------------
 * Outputs a string to the standard output.
 *
 * Parameters:
 * - char *str: The string to be displayed.
 *
 * Returns:
 * - Nothing.
 */
void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

/*
 * Function: ft_putnbr
 * --------------------
 * Outputs an integer as a string of characters to the standard output.
 *
 * Parameters:
 * - int nbr: The integer to be displayed.
 *
 * Returns:
 * - Nothing.
 *
 * Notes:
 * - Handles the special case of `-2147483648` directly,
 *   as it cannot be represented 
 *   using positive values in a 32-bit signed integer system.
 */
void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

/*
 * Function: ft_show_tab
 * ---------------------
 * Displays the content of an array of `t_stock_str` structures.
 *
 * Parameters:
 * - struct s_stock_str *par: Pointer to an array of `t_stock_str` structures.
 *
 * Returns:
 * - Nothing.
 *
 * Output Format:
 * - For each structure in the array:
 *   1. The original string (`str`), followed by a newline.
 *   2. The size of the string (`size`), followed by a newline.
 *   3. The copied string (`copy`), followed by a newline.
 * - Stops processing when `par[i].str` is NULL (sentinel).
 */
void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
