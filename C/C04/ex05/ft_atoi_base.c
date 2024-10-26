/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:10:21 by provira-          #+#    #+#             */
/*   Updated: 2024/07/11 12:10:23 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_atoi_base
 * -----------------------
 * Converts a string to an integer based on a specified base.
 *
 * Syntax:
 * int ft_atoi_base(char *str, char *base)
 *
 * Arguments:
 * - char *str: The input string to be converted.
 * - char *base: The string representing the base, containing valid characters.
 *
 * Returns:
 * - The converted integer value from the string based on the specified base.
 * - Returns 0 if the base is invalid or the string cannot be converted.
 *
 * Function details:
 * - The function first checks if the provided base is valid
 *   using the `check_base()` function.
 * - It then skips leading whitespace and identifies 
 *   the sign of the number with `skip_whitespace_and_sign()`.
 * - The main conversion happens in a loop where each character in 
 *   the string is converted to its respective value in the specified base
 *   using `char_to_value()`, accumulating the result.
 *
 * Supporting functions:
 * - check_base(): Validates the base string to ensure it meets 
 *   criteria (no duplicate or invalid characters).
 * - char_to_value(): Maps a character in the base string to 
 *   its corresponding integer value.
 * - skip_whitespace_and_sign(): Skips leading whitespaces 
 *   and detects the sign of the number.
 *
 * Example:
 * char *number = "   -1011";
 * char *base = "01"; // Binary base
 * int result = ft_atoi_base(number, base);
 * // result will be -11
 */
#include <unistd.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i > 1);
}

int	char_to_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

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

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	sign;
	int	result;
	int	value;

	if (!check_base(base))
		return (0);
	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
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
