/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:35:52 by provira-          #+#    #+#             */
/*   Updated: 2024/07/09 18:37:13 by provira-         ###   ########.fr       */
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

/*
 * Function: ft_strcat(char *dest, char *src)
 * ------------------------------------------
 * Concatenates the source string to the destination string.
 * 
 * Syntax:
 * char *ft_strcat(char *dest, char *src)
 * 
 * Arguments:
 * - char *dest: A pointer to the destination string.
 * - char *src: A pointer to the source string.
 * 
 * Returns:
 * - A pointer to the destination string `dest`.
 * 
 * Examples:
 * - char dest[50] = "Hello, ";
 *   ft_strcat(dest, "world!") -> "Hello, world!"
 * - char dest[50] = "";
 *   ft_strcat(dest, "Hello!") -> "Hello!"
 */
char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(dest);
	while (src[i] != '\0')
		dest[len++] = src[i++];
	return (dest);
}
