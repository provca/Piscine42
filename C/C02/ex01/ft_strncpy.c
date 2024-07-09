/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:52:01 by provira-          #+#    #+#             */
/*   Updated: 2024/07/08 14:52:05 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_strncpy(char *dest, char *src, unsigned int n)
 * -----------------------------------------------------------
 * Copies up to `n` characters from the string pointed to by `src` to the 
 * buffer pointed to by `dest`. If the length of `src` is less than `n`, 
 * the remainder of `dest` will be padded with null bytes.
 * 
 * Syntax:
 * char *ft_strncpy(char *dest, char *src, unsigned int n)
 * 
 * Arguments:
 * - char *dest: A pointer to the destination buffer
 * where the content is to be copied.
 * - char *src: A pointer to the source string to be copied.
 * - unsigned int n: The maximum number of characters to be copied from `src`.
 * 
 * Returns:
 * - char *: A pointer to the destination string `dest`.
 * 
 * Examples:
 * - char src[] = "Hello";
 *   char dest[10];
 *   ft_strncpy(dest, src, 10); // dest now contains "Hello\0\0\0\0\0"
 * - char src[] = "Hello, World!";
 *   char dest[5];
 *   ft_strncpy(dest, src, 5); // dest now contains "Hello"
 * - char src[] = "Hi";
 *   char dest[5];
 *   ft_strncpy(dest, src, 5); // dest now contains "Hi\0\0\0"
 */
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
