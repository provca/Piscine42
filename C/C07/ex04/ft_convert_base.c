/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:31:50 by provira-          #+#    #+#             */
/*   Updated: 2024/11/12 23:32:02 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

/*
 * Function: ft_convert_base()
 * ----------------------------
 * Converts a number from one base to another.
 *
 * Syntax:
 * char *ft_convert_base(char *nbr, char *base_from, char *base_to)
 *
 * Arguments:
 * - char *nbr: A string representing the number to be converted.
 * - char *base_from: A string representing the base of the input number.
 * - char *base_to: A string representing the base to which the number 
 *   should be converted.
 *
 * Returns:
 * - A string representing the converted number in the target base.
 * - Returns NULL if either of the input bases is invalid or if memory 
 *   allocation fails.
 *
 * Notes:
 * - This function first checks if the provided bases are valid, 
 *   then converts the input number to decimal using ft_atoi_base.
 *   It calculates the necessary length for the result, allocates memory
 *   for it, and then converts the decimal number to the target base using
 *   the base-to string.
 *
 * Example:
 * - char *result = ft_convert_base("1010", "01", "0123456789");
 *   // Result: "10" (binary "1010" to decimal)
 */
int		ft_strlen(char *str);
int		ft_is_valid_base(char *base);
int		ft_atoi_base(char *str, char *base);
char	*create_result(int nbr, int len, int sign, char *base_to);
int		calculate_length(int nbr, int base_len);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		decimal;
	int		length;
	int		sign;
	char	*result;

	if (!ft_is_valid_base(base_from) || !ft_is_valid_base(base_to))
		return (NULL);
	decimal = ft_atoi_base(nbr, base_from);
	sign = decimal < 0;
	length = calculate_length(decimal, ft_strlen(base_to));
	result = create_result(decimal, length, sign, base_to);
	return (result);
}

/*
 * Function: ft_strlen()
 * ---------------------
 * Returns the length of a string.
 *
 * Syntax:
 * int ft_strlen(char *str)
 *
 * Arguments:
 * - char *str: The string whose length is to be calculated.
 *
 * Returns:
 * - The length of the string (number of characters before the 
 *   null terminator).
 *
 * Example:
 * - int len = ft_strlen("Hello");
 *   // len = 5
 */
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

/*
 * Function: calculate_length()
 * ----------------------------
 * Calculates the number of digits required to represent a number in the 
 * target base.
 *
 * Syntax:
 * int calculate_length(int nbr, int base_len)
 *
 * Arguments:
 * - int nbr: The number to be represented in the target base.
 * - int base_len: The length of the target base (number of characters
 *   in base_to).
 *
 * Returns:
 * - The length required to represent the number in the given base.
 *
 * Example:
 *   // len = 2 (255 in hexadecimal requires 2 digits: "FF")
 * - int len = calculate_length(255, 16);
 */
int	calculate_length(int nbr, int base_len)
{
	int	len;

	len = 1 + (nbr < 0);
	while (nbr != 0)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

/*
 * Function: create_result()
 * -------------------------
 * Creates the result string representing the number in the target base.
 *
 * Syntax:
 * char *create_result(int nbr, int len, int sign, char *base_to)
 *
 * Arguments:
 * - int nbr: The number to be converted.
 * - int len: The length of the result string (calculated before).
 * - int sign: Indicates if the number is negative.
 * - char *base_to: The target base string.
 *
 * Returns:
 * - A string representing the number in the target base.
 * - NULL if memory allocation fails.
 *
 * Notes:
 * - The result string is created by calculating each digit in the target base.
 * - The number is processed in reverse, starting with the 
 *   least significant digit.
 *
 * Example:
 *   // result = "-FF"
 * - char *result = create_result(-255, 3, 1, "0123456789ABCDEF");
 */
char	*create_result(int nbr, int len, int sign, char *base_to)
{
	char	*result;
	int		base_len;

	base_len = ft_strlen(base_to);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (sign)
		nbr = -nbr;
	while (len-- > sign)
	{
		result[len] = base_to[nbr % base_len];
		nbr /= base_len;
	}
	if (sign)
		result[0] = '-';
	return (result);
}
