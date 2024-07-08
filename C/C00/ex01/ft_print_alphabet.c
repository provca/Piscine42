/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:13:06 by provira-          #+#    #+#             */
/*   Updated: 2024/07/05 16:20:27 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_print_alphabet()
 * ---------------------------
 * Writes the alphabet from 'a' to 'z' to the standard output (terminal).
 * 
 * Syntax:
 * void ft_print_alphabet(void)
 * 
 * Arguments:
 * - None
 * 
 * Returns:
 * - None
 * 
 * Examples:
 * - ft_print_alphabet() -> "abcdefghijklmnopqrstuvwxyz"
 *   (prints the lowercase alphabet to the standard output)
 */
#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	c;

	c = 'a';
	while (c <= 'z')
	{
		write(1, &c, 1);
		c++;
	}
}
