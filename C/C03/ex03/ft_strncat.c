/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:49:43 by provira-          #+#    #+#             */
/*   Updated: 2024/07/09 18:49:46 by provira-         ###   ########.fr       */
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
 * Function: ft_strncat(char *dest, char *src, unsigned int nb)
 * ------------------------------------------------------------
 * Concatenates up to `nb` characters from the source string to the destination.
 * 
 * Syntax:
 * char *ft_strncat(char *dest, char *src, unsigned int nb)
 * 
 * Arguments:
 * - char *dest: A pointer to the destination string.
 * - char *src: A pointer to the source string.
 * - unsigned int nb: The maximum number of characters to concatenate.
 * 
 * Returns:
 * - A pointer to the destination string `dest`.
 * 
 * Examples:
 * - char dest[50] = "Hello, ";
 *   ft_strncat(dest, "world!", 3) -> "Hello, wor"
 * - char dest[50] = "";
 *   ft_strncat(dest, "Hello!", 4) -> "Hell"
 */
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(dest);
	while (src[i] != '\0' && i < nb)
		dest[len++] = src[i++];
	dest[len] = '\0';
	return (dest);
}
