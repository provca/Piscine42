/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:25:44 by provira-          #+#    #+#             */
/*   Updated: 2024/07/12 13:25:46 by provira-         ###   ########.fr       */
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
 * Entry point of the program. Prints the program name if
 * there is at least one argument.
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
 * - The program always prints its own name followed by a newline.
 * - The behavior of this function can be modified for different purposes.
 */
int	main(int argc, char *argv[])
{
	if (argc >= 1)
		ft_putstr(argv[0]);
	write(1, "\n", 1);
	return (0);
}
