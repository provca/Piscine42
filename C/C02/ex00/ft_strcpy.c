/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:17:50 by provira-          #+#    #+#             */
/*   Updated: 2024/07/08 14:17:52 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_strcpy(char *dest, char *src)
 * ------------------------------------------
 * Copies the string pointed to by `src` (including the null terminator) to the 
 * buffer pointed to by `dest`.
 * 
 * Syntax:
 * char *ft_strcpy(char *dest, char *src)
 * 
 * Arguments:
 * - char *dest: A pointer to the destination buffer where
 * the content is to be copied.
 * - char *src: A pointer to the source string to be copied.
 * 
 * Returns:
 * - char *: A pointer to the destination string `dest`.
 * 
 * Examples:
 * - char src[] = "Hello, World!";
 *   char dest[20];
 *   ft_strcpy(dest, src); // dest now contains "Hello, World!"
 * - char src[] = "";
 *   char dest[10];
 *   ft_strcpy(dest, src); // dest now contains ""
 */
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
