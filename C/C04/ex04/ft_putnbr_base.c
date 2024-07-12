/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:04:38 by provira-          #+#    #+#             */
/*   Updated: 2024/07/10 15:04:40 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

/*
 * Function: ft_putchar()
 * ----------------------
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
 * Function: ft_strlen()
 * ---------------------
 * Calculates the length of a string.
 * 
 * Syntax:
 * int ft_strlen(char *str)
 * 
 * Arguments:
 * - char *str: The string whose length is to be calculated.
 * 
 * Returns:
 * - The length of the string as an integer.
 * 
 * Examples:
 * - ft_strlen("Hello") -> 5
 * - ft_strlen("") -> 0
 */
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/*
 * Function: is_valid_base()
 * -------------------------
 * Checks if the given base string is valid for numeral conversion.
 * A valid base must not contain duplicate characters, '+', '-', or any
 * non-printable characters.
 * 
 * Syntax:
 * bool is_valid_base(char *base)
 * 
 * Arguments:
 * - char *base: The base string to be validated.
 * 
 * Returns:
 * - true if the base is valid, false otherwise.
 * 
 * Examples:
 * - is_valid_base("01") -> true (binary base)
 * - is_valid_base("0123456789ABCDEF") -> true (hexadecimal base)
 * - is_valid_base("01234+56789") -> false (contains invalid character '+')
 */
bool	is_valid_base(char *base)
{
	int	len;
	int	i;
	int	j;

	len = ft_strlen(base);
	if (len <= 1)
		return (false);
	i = 0;
	while (i < len)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < ' ')
			return (false);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

/*
 * Function: ft_putnbr_recursive()
 * -------------------------------
 * Recursively writes the given number in the specified base 
 * to the standard output.
 * 
 * Syntax:
 * void ft_putnbr_recursive(int nbr, char *base, int base_len)
 * 
 * Arguments:
 * - int nbr: The number to be written.
 * - char *base: The base string used for numeral conversion.
 * - int base_len: The length of the base string.
 * 
 * Returns:
 * - None
 * 
 * Examples:
 * - ft_putnbr_recursive(255, "01", 2) 
 *   -> "11111111" (binary representation)
 * - ft_putnbr_recursive(255, "0123456789ABCDEF", 16) 
 *   -> "FF" (hexadecimal representation)
 */
void	ft_putnbr_recursive(int nbr, char *base, int base_len)
{
	if (nbr < 0)
	{
		if (nbr <= -base_len)
			ft_putnbr_recursive(nbr / base_len, base, base_len);
		ft_putchar(base[-(nbr % base_len)]);
	}
	else
	{
		if (nbr >= base_len)
			ft_putnbr_recursive(nbr / base_len, base, base_len);
		ft_putchar(base[nbr % base_len]);
	}
}

/*
 * Function: ft_putnbr_base()
 * --------------------------
 * Writes the given number in the specified base to the standard output.
 * 
 * Syntax:
 * void ft_putnbr_base(int nbr, char *base)
 * 
 * Arguments:
 * - int nbr: The number to be written.
 * - char *base: The base string used for numeral conversion.
 * 
 * Returns:
 * - None
 * 
 * Examples:
 * - ft_putnbr_base(255, "01") -> "11111111" (binary representation)
 * - ft_putnbr_base(255, "0123456789ABCDEF") -> "FF" (hexadecimal representation)
 */
void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	if (!is_valid_base(base))
		return ;
	base_len = ft_strlen(base);
	if (nbr < 0)
		ft_putchar('-');
	ft_putnbr_recursive(nbr, base, base_len);
}
