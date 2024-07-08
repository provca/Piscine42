/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:27:27 by provira-          #+#    #+#             */
/*   Updated: 2024/07/05 16:21:46 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_print_numbers()
 * -----------------------------
 * Writes the digits '0' to '9' to the standard output (usually the terminal).
 * 
 * Syntax:
 * void ft_print_numbers(void)
 * 
 * Arguments:
 * - None
 * 
 * Returns:
 * - None
 * 
 * Examples:
 * - ft_print_numbers() -> "0123456789"
 *   (prints the digits from '0' to '9' to the standard output)
 */
#include <unistd.h>

void	ft_print_numbers(void)
{
	char	c;

	c = '0';
	while (c <= '9')
	{
		write(1, &c, 1);
		c++;
	}
}
