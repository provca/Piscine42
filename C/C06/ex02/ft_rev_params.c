/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:06:01 by provira-          #+#    #+#             */
/*   Updated: 2024/07/12 14:06:03 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	

/*
 * Function: ft_putstr()
 * ---------------------
 * Writes a string to the standard output.
 *
 * Syntax:
 * void ft_putstr(char *str)
 *
 * Arguments:
 * - char *str: The string to write to the standard output.
 *
 * Returns:
 * - None.
 *
 * Examples:
 * - ft_putstr("Hello, World!");
 */
void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &(*str), 1);
		str++;
	}
}

/*
 * Function: main()
 * ----------------
 * Entry point of the program. Prints each argument passed to the program
 * in reverse order, each on a new line.
 *
 * Syntax:
 * int main(int argc, char *argv[])
 *
 * Arguments:
 * - int argc: The number of command-line arguments.
 * - char *argv[]: The array of command-line arguments.
 *
 * Returns:
 * - 0 on successful execution.
 *
 * Note:
 * - The program prints each argument passed to it in reverse order,
 *   each on a new line.
 * - If no arguments are passed, nothing is printed.
 */
int	main(int argc, char *argv[])
{
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
