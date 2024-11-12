/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:45:02 by provira-          #+#    #+#             */
/*   Updated: 2024/11/12 23:45:07 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

/*
 * Function: ft_is_valid_base()
 * ----------------------------
 * Checks if the given base is valid for base conversions.
 *
 * Syntax:
 * int ft_is_valid_base(char *base)
 *
 * Arguments:
 * - char *base: The string representing the base.
 *
 * Returns:
 * - 1 if the base is valid.
 * - 0 if the base is invalid.
 *
 * Note:
 * - A valid base must contain at least two characters.
 * - It must not include '+' or '-' characters or any character with ASCII 
 *   value less than 32.
 * - It must not contain duplicate characters.
 *
 * Example:
 * - ft_is_valid_base("0123456789");  // returns 1 (valid base)
 * - ft_is_valid_base("01+-");        // returns 0 (invalid base)
 */
int	ft_is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*
 * Function: char_to_value()
 * -------------------------
 * Converts a character from the given base to its numerical value.
 *
 * Syntax:
 * int char_to_value(char c, char *base)
 *
 * Arguments:
 * - char c: The character to be converted.
 * - char *base: The base string.
 *
 * Returns:
 * - The numeric value of the character if found in the base.
 * - -1 if the character is not found in the base.
 *
 * Example:
 * - char_to_value('1', "0123456789"); // returns 1
 * - char_to_value('a', "0123456789abcdef"); // returns 10
 */
int	char_to_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/*
 * Function: skip_whitespace_and_sign()
 * ------------------------------------
 * Skips over any whitespace characters and determines the sign of the number.
 *
 * Syntax:
 * int skip_whitespace_and_sign(char **str)
 *
 * Arguments:
 * - char **str: The string to parse.
 *
 * Returns:
 * - The sign of the number, either 1 or -1.
 *
 * Note:
 * - The function advances the string pointer as it skips whitespace and 
 *   sign characters.
 *
 * Example:
 *   // str points to "42", returns -1
 * - char *str = "  -42"; skip_whitespace_and_sign(&str);  
 */
int	skip_whitespace_and_sign(char **str)
{
	int	sign;

	sign = 1;
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	while (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -sign;
		(*str)++;
	}
	return (sign);
}

/*
 * Function: ft_atoi_base()
 * ------------------------
 * Converts a string representing a number in a given base to 
 * its decimal (base 10) integer value.
 *
 * Syntax:
 * int ft_atoi_base(char *str, char *base)
 *
 * Arguments:
 * - char *str: The string representing the number to convert.
 * - char *base: The base in which the number is represented.
 *
 * Returns:
 * - The decimal integer value of the number.
 *
 * Note:
 * - The function uses the base string to map characters to values.
 * - It handles skipping whitespace and determining the sign.
 *
 * Example:
 *   // returns 10 (binary to decimal) 
 * - ft_atoi_base("1010", "01");
 *   // returns 26 (hexadecimal to decimal)
 * - ft_atoi_base("1a", "0123456789abcdef"); 
 */
int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	sign;
	int	result;
	int	value;

	base_len = ft_strlen(base);
	sign = skip_whitespace_and_sign(&str);
	result = 0;
	value = char_to_value(*str, base);
	while (value != -1)
	{
		result = result * base_len + value;
		str++;
		value = char_to_value(*str, base);
	}
	return (result * sign);
}
