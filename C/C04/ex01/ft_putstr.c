/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:42:52 by provira-          #+#    #+#             */
/*   Updated: 2024/07/10 10:42:54 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_putstr(char *str)
 * ------------------------------
 * Writes the null-terminated string `str` to the standard output.
 * 
 * Syntax:
 * void ft_putstr(char *str)
 * 
 * Arguments:
 * - char *str: A pointer to the null-terminated string to be written.
 * 
 * Returns:
 * - None
 * 
 * Examples:
 * - char *str1 = "Hello, world!";
 *   ft_putstr(str1); // Prints "Hello, world!"
 * - char *str2 = "";
 *   ft_putstr(str2); // Prints nothing (empty string)
 */
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &(*str), 1);
		str++;
	}
}
