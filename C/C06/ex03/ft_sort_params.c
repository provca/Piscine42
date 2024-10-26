/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 08:13:51 by provira-          #+#    #+#             */
/*   Updated: 2024/10/26 08:13:55 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Program: main
 * --------------------
 * Sorts command-line arguments in alphabetical order and prints them.
 *
 * Description:
 * This program takes a list of arguments passed to it from the command line,
 * sorts them lexicographically, and prints each argument on a new line.
 *
 * Functions:
 * - swap(): Swaps two strings by their pointers.
 * - sort_params(): Sorts the array of strings (command-line arguments) 
 *   in ascending order.
 * - print_params(): Prints each string in the sorted list of command-line
 *   arguments.
 *
 * Notes:
 * - `swap` is used to facilitate swapping pointers to strings.
 * - Sorting is done by comparing the first character of each string only.
 * - `print_params` advances the pointer for each character in each argument
 *   for proper display, as arguments are processed in-place.
 *
 * Example usage:
 * ./a.out apple banana cherry
 * // Output:
 * apple
 * banana
 * cherry
 */

#include <unistd.h>

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_params(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (argv[i][0] > argv[j][0])
				swap(&argv[i], &argv[j]);
			j++;
		}
		i++;
	}
}

void	print_params(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		while (*argv[i])
		{
			write(1, argv[i], 1);
			argv[i]++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	sort_params(argc, argv);
	print_params(argc, argv);
	return (0);
}
