/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:03:15 by provira-          #+#    #+#             */
/*   Updated: 2024/07/10 02:03:17 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_strlen(char *str)
 * ------------------------------
 * Calculates the length of a null-terminated string.
 * 
 * Syntax:
 * unsigned int ft_strlen(char *str)
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
unsigned int	ft_strlen(char *str)
{
	unsigned int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

/*
 * Function: ft_check_memory(char *dest, char *src, unsigned int size)
 * -------------------------------------------------------------------
 * Checks if there is enough memory to concatenate `src` to `dest` within `size`.
 * 
 * Syntax:
 * unsigned int ft_check_memory(char *dest, char *src, unsigned int size)
 * 
 * Arguments:
 * - char *dest: The destination string.
 * - char *src: The source string.
 * - unsigned int size: The total size of the buffer `dest`.
 * 
 * Returns:
 * - 1 if there is enough space, 0 otherwise.
 * 
 * Examples:
 * - ft_check_memory("hello", "world", 11) -> 1
 * - ft_check_memory("hello", "world", 10) -> 0
 */
unsigned int	ft_check_memory(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size == 0)
		return (0);
	if (len_dest >= size)
		return (0);
	return ((size - len_dest) - 1 >= len_src);
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
 * - char *dest: The destination string.
 * - char *src: The source string.
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
	dest[len] = '\0';
	return (dest);
}

/*
 * Function: ft_strlcat(char *dest, char *src, unsigned int size)
 * --------------------------------------------------------------
 * Appends the source string to the destination string, ensuring not to exceed 
 * `size` bytes.
 * 
 * Syntax:
 * unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
 * 
 * Arguments:
 * - char *dest: The destination string.
 * - char *src: The source string.
 * - unsigned int size: The total size of the buffer `dest`.
 * 
 * Returns:
 * - The total length of the string they tried to create
 *   (initial length of `dest` plus the length of `src`).
 * 
 * Examples:
 * - char dest[20] = "Hello, ";
 *   ft_strlcat(dest, "world!", 20) -> 12 ("Hello, world!")
 * - char dest[10] = "Hello";
 *   ft_strlcat(dest, " world", 10) -> 11 ("Hello wor")
 */
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;

	if (!dest || !src || size == 0)
		return (0);
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (len_dest >= size)
		return (size + len_src);
	if (ft_check_memory(dest, src, size))
		ft_strcat(dest, src);
	return (len_dest + len_src);
}

/*
═════════════════════════════════ Testing ex05 ═════════════════════════════════

Executing: norminette -R CheckForbiddenSourceHeader ft_strlcat.c:
ft_strlcat.c: OK!

Executing: gcc -Wall -Wextra -Werror main.c ft_strlcat.c:
main.c: In function ‘main’:
main.c:65:25: error: implicit declaration of function ‘strlcat’;
   did you mean ‘strncat’? [-Werror=implicit-function-declaration]
   65 |  unsigned int std_res = strlcat(std_s1, s2, n);
      |                         ^~~~~~~
      |                         strncat
cc1: all warnings being treated as errors
Problem compiling files

══════════════════════════════    Ex05 failed!    ══════════════════════════════
*/