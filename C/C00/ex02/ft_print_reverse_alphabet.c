/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:23:40 by provira-          #+#    #+#             */
/*   Updated: 2024/07/05 16:21:07 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_print_reverse_alphabet()
 * -------------------------------------
 * Writes the lowercase alphabet in reverse order from 'z' to 'a'
 * to the standard output (usually the terminal).
 * 
 * Syntax:
 * void ft_print_reverse_alphabet(void)
 * 
 * Arguments:
 * - None
 * 
 * Returns:
 * - None
 * 
 * Examples:
 * - ft_print_reverse_alphabet() -> "zyxwvutsrqponmlkjihgfedcba"
 *   (prints the lowercase alphabet in reverse order to the standard output)
 */
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	c;

	c = 'z';
	while (c >= 'a')
	{
		write(1, &c, 1);
		c--;
	}
}
