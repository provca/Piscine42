/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:38 by provira-          #+#    #+#             */
/*   Updated: 2024/07/05 18:51:41 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_print_combn()
 * --------------------------
 * Prints all combinations of `n` digits in ascending order.
 *
 * Syntax:
 * void ft_print_combn(int n)
 *
 * Arguments:
 * - int n: The number of digits for the combination. Must be between 1 and 10.
 *
 * Behavior:
 * - Generates and prints all combinations of 
 *   `n` different digits in ascending order.
 * - Combinations are printed without repetition, separated by a comma and space.
 * - Example for `n = 2`: "01, 02, 03, ..., 89".
 *
 * Functions used:
 * - `write_combination()`: Prints a combination of `n` digits.
 *    If it's not the last one, it adds a comma and space.
 * - `is_last_comb()`: Checks if the current combination 
 *    is the last possible combination for `n` digits.
 * - `init_comb()`: Initializes the first combination of `n` digits as "012...n".
 *
 * Example:
 * - ft_print_combn(2) will output: "01, 02, 03, ..., 89".
 * 
 * Note:
 * - The function avoids using recursive calls and instead uses a loop
 *   to generate all combinations.
 * - Combinations are printed using `write` for efficient output.
 */

#include <unistd.h>

void	write_combination(char *comb, int n, int is_last)
{
	write(1, comb, n);
	if (!is_last)
		write(1, ", ", 2);
}

int	is_last_comb(char *comb, int n)
{
	return (comb[0] == '9' - n + 1);
}

void	init_comb(char *comb, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		comb[i] = '0' + i;
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	comb[10];
	int		i;

	init_comb(comb, n);
	while (1)
	{
		write_combination(comb, n, is_last_comb(comb, n));
		i = n - 1;
		while (i >= 0 && comb[i] == '9' - (n - 1 - i))
			i--;
		if (i < 0)
			break ;
		comb[i]++;
		while (++i < n)
			comb[i] = comb[i - 1] + 1;
	}
}
