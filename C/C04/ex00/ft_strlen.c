/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:40:12 by provira-          #+#    #+#             */
/*   Updated: 2024/07/10 10:40:15 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_strlen(char *str)
 * ------------------------------
 * Calculates the length of a null-terminated string.
 * 
 * Syntax:
 * int ft_strlen(char *str)
 * 
 * Arguments:
 * - char *str: A pointer to the string whose length is to be calculated.
 * 
 * Returns:
 * - The length of the string (number of characters before the null terminator).
 * 
 * Examples:
 * - ft_strlen("hello") -> 5
 * - ft_strlen("") -> 0
 */
int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}
