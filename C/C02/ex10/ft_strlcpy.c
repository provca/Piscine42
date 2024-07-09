/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:17:04 by provira-          #+#    #+#             */
/*   Updated: 2024/07/09 12:17:07 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_strlcpy(char *dest, char *src, unsigned int size)
 * --------------------------------------------------------------
 * Copies up to `size - 1` characters from the string `src` to the string `dest`,
 * including a terminating null character `\0`.
 * 
 * Syntax:
 * unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
 * 
 * Arguments:
 * - char *dest: A pointer to the destination buffer
 *   where the string is to be copied.
 * - char *src: A pointer to the source string to be copied.
 * - unsigned int size:
 *   The maximum number of characters to be copied into `dest`, 
 *   including the null terminator.
 * 
 * Returns:
 * - unsigned int: The total length of the string `src`,
 *   excluding the null terminator.
 * 
 * Examples:
 * - char dest[10];
 *   char src[] = "Hello";
 *   unsigned int len = ft_strlcpy(dest, src, 10);
 *   // len will be 5, dest will contain "Hello\0"
 * - char dest[5];
 *   char src[] = "Hello";
 *   unsigned int len = ft_strlcpy(dest, src, 5); 
 *   // len will be 5, dest will contain "Hell\0" (no room for 'o')
 * - char dest[3];
 *   char src[] = "Hello";
 *   unsigned int len = ft_strlcpy(dest, src, 3);
 *   // len will be 5, dest will contain "Hel\0" (only 'H' and 'e' fit)
 */
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < (size - 1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
