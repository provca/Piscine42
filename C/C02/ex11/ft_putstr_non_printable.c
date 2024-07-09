/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:59:50 by provira-          #+#    #+#             */
/*   Updated: 2024/07/09 14:59:53 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
 * Function: ft_putchar(char c)
 * ----------------------------
 * Writes a single character to the standard output (usually the terminal).
 * 
 * Syntax:
 * void ft_putchar(char c)
 * 
 * Arguments:
 * - char c: The character to be written.
 * 
 * Returns:
 * - None
 * 
 * Examples:
 * - ft_putchar('A') -> "A" (prints the character 'A' to the standard output)
 * - ft_putchar('b') -> "b" (prints the character 'b' to the standard output)
 */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
 * Function: ft_to_hex(unsigned char nb)
 * -------------------------------------
 * Converts an unsigned char value to its hexadecimal representation
 * and writes it to the standard output.
 * 
 * Syntax:
 * void ft_to_hex(unsigned char nb)
 * 
 * Arguments:
 * - unsigned char nb: The unsigned char value to be converted to hexadecimal.
 * 
 * Returns:
 * - None
 * 
 * Examples:
 * - ft_to_hex(15) -> "\\0f" (prints the string "\\0f" to the standard output)
 * - ft_to_hex(255) -> "\\ff" (prints the string "\\ff" to the standard output)
 */
void	ft_to_hex(unsigned char nb)
{
	char	*hex;
	char	hex_output[3];

	hex = "0123456789abcdef";
	hex_output[0] = '\\';
	hex_output[1] = hex[nb / 16];
	hex_output[2] = hex[nb % 16];
	write(1, hex_output, 3);
}

/*
 * Function: ft_putstr_non_printable(char *str)
 * --------------------------------------------
 * Writes a string to the standard output, converting non-printable characters
 * to their hexadecimal representation prefixed by a backslash.
 * 
 * Syntax:
 * void ft_putstr_non_printable(char *str)
 * 
 * Arguments:
 * - char *str: A pointer to the string to be written.
 * 
 * Returns:
 * - None
 * 
 * Examples:
 * - char str[] = "Hello\nWorld!";
 *   ft_putstr_non_printable(str); // Output: "Hello\\0aWorld!"
 * - char str[] = "\x01\x02\x03";
 *   ft_putstr_non_printable(str); // Output: "\\01\\02\\03"
 */
void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= ' ' && str[i] <= '~')
			ft_putchar(str[i]);
		else
			ft_to_hex((unsigned char)str[i]);
		i++;
	}
}
