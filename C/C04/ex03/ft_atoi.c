/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:51:57 by provira-          #+#    #+#             */
/*   Updated: 2024/07/10 10:51:59 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_is_numeric(char c)
 * -------------------------------
 * Checks if a given character is a numeric digit (0-9).
 * 
 * Syntax:
 * int ft_is_numeric(char c)
 * 
 * Arguments:
 * - char c: The character to be checked.
 * 
 * Returns:
 * - 1 if the character is a numeric digit, 0 otherwise.
 * 
 * Examples:
 * - ft_is_numeric('3') -> 1
 * - ft_is_numeric('a') -> 0
 */
int	ft_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/*
 * Function: ft_atoi(char *str)
 * ----------------------------
 * Converts a string to an integer. This implementation is specific to 42 and
 * differs from the standard atoi() function.
 * 
 * Syntax:
 * int ft_atoi(char *str)
 * 
 * Arguments:
 * - char *str: The string to be converted to an integer.
 * 
 * Returns:
 * - The integer representation of the string.
 * 
 * Notes:
 * - This function skips leading whitespace characters and considers an 
 *   optional '+' or '-' sign. It handles multiple signs but only the 
 *   last sign affects the result. The conversion stops at the first 
 *   non-numeric character.
 * 
 * Examples:
 * - ft_atoi("  -42") -> -42
 * - ft_atoi("123abc") -> 123
 * - ft_atoi("  +---42") -> 42
 */
int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	value;
	int	sign_count;

	i = 0;
	sign = 1;
	value = 0;
	sign_count = 0;
	while (str[i] <= ' ' || str[i] == '~')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign_count++;
		i++;
	}
	if (sign_count % 2 != 0)
		sign = -1;
	while (ft_is_numeric(str[i]))
	{
		value = (value * 10) + (str[i] - '0');
		i++;
	}
	return (value * sign);
}

/*
 * Function: ft_atoi(char *str)
 * ----------------------------
 * Converts a string to an integer, similar to the standard atoi() function.
 * 
 * Syntax:
 * int ft_atoi(char *str)
 * 
 * Arguments:
 * - char *str: The string to be converted to an integer.
 * 
 * Returns:
 * - The integer representation of the string.
 * 
 * Notes:
 * - This function skips leading whitespace characters. It considers an 
 *   optional '+' or '-' sign at the beginning of the string. The conversion 
 *   stops at the first non-numeric character.
 * 
 * Examples:
 * - ft_atoi("  -42") -> -42
 * - ft_atoi("123abc") -> 123
 * - ft_atoi("   +42") -> 42
 */
/*
int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	value;

	sign = 1;
	i = 0;
	value = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_is_numeric(str[i]))
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	return (value * sign);
}
*/