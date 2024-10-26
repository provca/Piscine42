/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:50:12 by provira-          #+#    #+#             */
/*   Updated: 2024/10/25 14:50:20 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_ten_queens_puzzle
 * ---------------------------------
 * Solves the 10 queens puzzle and returns the total number of solutions.
 *
 * Syntax:
 * int ft_ten_queens_puzzle(void)
 *
 * Returns:
 * - The total number of distinct solutions for placing 10 queens on a 10x10
 *   chessboard such that no two queens threaten each other.
 *
 * Function details:
 * - Initializes an array to keep track of the positions of the queens.
 * - Calls the recursive `solve` function to explore all possible placements
 *   of the queens.
 * - Each valid configuration is printed, and the solution count
 *   is incremented.
 *
 * Supporting functions:
 * - is_safe(): Determines if a queen can be placed at a given position 
 *   without being attacked by other queens.
 * - print_solution(): Prints the current valid arrangement of queens in 
 *   a readable format.
 * - solve(): Recursively attempts to place queens in valid positions on 
 *   the board.
 *
 * Example:
 * int total_solutions = ft_ten_queens_puzzle();
 * // total_solutions will contain the number of valid arrangements 
 *    for 10 queens.
 */

#include <unistd.h>

int	is_safe(int *queens, int row, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (queens[i] == row
			|| queens[i] - i == row - col
			|| queens[i] + i == row + col)
			return (0);
		i++;
	}
	return (1);
}

void	print_solution(int *queens, int col)
{
	char	c;

	if (col < 10)
	{
		c = queens[col] + '0';
		write(1, &c, 1);
		print_solution(queens, col + 1);
	}
	else
		write(1, "\n", 1);
}

void	solve(int *queens, int col, int *count)
{
	int	row;

	row = 0;
	if (col == 10)
	{
		print_solution(queens, 0);
		(*count)++;
		return ;
	}
	while (row < 10)
	{
		if (is_safe(queens, row, col))
		{
			queens[col] = row;
			solve(queens, col + 1, count);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	queens[10];
	int	count;

	count = 0;
	solve(queens, 0, &count);
	return (count);
}
