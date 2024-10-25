/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:01:49 by provira-          #+#    #+#             */
/*   Updated: 2024/07/07 05:57:28 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_strlen(char *str)
 * ------------------------------
 * Calculates the length of the string `str`.
 * 
 * Syntax:
 * int ft_strlen(char *str)
 * 
 * Arguments:
 * - char *str: A pointer to the null-terminated string 
 * whose length is to be calculated.
 * 
 * Returns:
 * - int: The length of the string `str`.
 * 
 * Examples:
 * - char *str1 = "Hello";
 *   int len1 = ft_strlen(str1); // len1 is 5
 * - char *str2 = "";
 *   int len2 = ft_strlen(str2); // len2 is 0
 */

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}
