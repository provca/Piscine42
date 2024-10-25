/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:49:10 by provira-          #+#    #+#             */
/*   Updated: 2024/07/05 15:20:44 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_putchar()
 * -------------
 * Writes a single character to the standard output (usually the terminal).
 * 
 * Syntax:
 * void ft_putchar(char c)
 * 
 * Arguments:
 * - char c: The character to be written.
 * 
 * Returns:
 * - None
 * 
 * Examples:
 * - ft_putchar('A') -> "A" (prints the character 'A' to the standard output)
 * - ft_putchar('b') -> "b" (prints the character 'b' to the standard output)
 */
#include <unistd.h>	

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
