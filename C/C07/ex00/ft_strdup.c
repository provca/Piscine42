/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:24:10 by provira-          #+#    #+#             */
/*   Updated: 2024/07/12 15:24:13 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
 * Function: ft_strlen()
 * ---------------------
 * Calculates the length of a string.
 *
 * Syntax:
 * int ft_strlen(char *str)
 *
 * Arguments:
 * - char *str: Pointer to the string whose length is to be calculated.
 *
 * Returns:
 * - The length of the string.
 *
 * Example:
 * - ft_strlen("Hello"); // returns 5
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
 * Function: ft_strcpy()
 * ---------------------
 * Copies a string from source to destination.
 *
 * Syntax:
 * char *ft_strcpy(char *dest, char *src)
 *
 * Arguments:
 * - char *dest: Pointer to the destination array 
 *   where the string is to be copied.
 * - char *src: Pointer to the source array 
 *   from where the string is to be copied.
 *
 * Returns:
 * - Pointer to the destination array.
 *
 * Example:
 * - char dest[20];
 * - ft_strcpy(dest, "Hello"); // dest now contains "Hello\0"
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

/*
 * Function: ft_strdup()
 * ---------------------
 * Duplicates a string.
 *
 * Syntax:
 * char *ft_strdup(char *src)
 *
 * Arguments:
 * - char *src: Pointer to the string to be duplicated.
 *
 * Returns:
 * - Pointer to a new string which is a duplicate of src.
 * - Returns NULL if memory allocation fails.
 *
 * Note:
 * - The returned pointer must be freed when no longer needed 
 *   to avoid memory leaks.
 *
 * Example:
 * - char *duplicate = ft_strdup("Hello");
 */
char	*ft_strdup(char *src)
{
	char	*dest;

	dest = malloc(ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	return (ft_strcpy(dest, src));
}
