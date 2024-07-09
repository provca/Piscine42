/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:19:42 by provira-          #+#    #+#             */
/*   Updated: 2024/07/08 16:19:45 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_is_numeric(char c)
 * -------------------------------
 * Checks if the character `c` is a numeric digit (0-9).
 * 
 * Syntax:
 * int ft_is_numeric(char c)
 * 
 * Arguments:
 * - char c: The character to be checked.
 * 
 * Returns:
 * - int: 1 if `c` is a numeric digit, 0 otherwise.
 * 
 * Examples:
 * - ft_is_numeric('0') -> 1 (character '0' is a numeric digit)
 * - ft_is_numeric('5') -> 1 (character '5' is a numeric digit)
 * - ft_is_numeric('a') -> 0 (character 'a' is not a numeric digit)
 * - ft_is_numeric('!') -> 0 (character '!' is not a numeric digit)
 */
int	ft_is_numeric(char c)
{
	if ((c >= '0' && c <= '9'))
	{
		return (1);
	}
	return (0);
}

/*
 * Function: ft_str_is_numeric(char *str)
 * --------------------------------------
 * Checks if the string `str` contains only numeric digits.
 * 
 * Syntax:
 * int ft_str_is_numeric(char *str)
 * 
 * Arguments:
 * - char *str: A pointer to the string to be checked.
 * 
 * Returns:
 * - int: 1 if `str` contains only numeric digits, 0 otherwise.
 * 
 * Examples:
 * - ft_str_is_numeric("12345")
 * -> 1 (string "12345" contains only numeric digits)
 * - ft_str_is_numeric("123a45")
 * -> 0 (string "123a45" contains non-numeric characters)
 * - ft_str_is_numeric("")
 * -> 1 (an empty string is considered to contain only numeric digits)
 */
int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_is_numeric(str[i]))
			return (0);
		i++;
	}
	return (1);
}
