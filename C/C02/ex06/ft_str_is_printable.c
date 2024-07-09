/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:34:28 by provira-          #+#    #+#             */
/*   Updated: 2024/07/08 16:34:30 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_is_printable(char c)
 * ---------------------------------
 * Checks if the character `c` is a printable ASCII character
 * (ASCII 32 to 126 inclusive).
 * 
 * Syntax:
 * int ft_is_printable(char c)
 * 
 * Arguments:
 * - char c: The character to be checked.
 * 
 * Returns:
 * - int: 1 if `c` is a printable ASCII character, 0 otherwise.
 * 
 * Examples:
 * - ft_is_printable(' ') -> 1 (space character is printable)
 * - ft_is_printable('A') -> 1 (uppercase letter 'A' is printable)
 * - ft_is_printable('\n') -> 0 (newline character is not printable)
 * - ft_is_printable('\0') -> 0 (null terminator is not printable)
 */
int	ft_is_printable(char c)
{
	if (c >= ' ' && c <= '~')
	{
		return (1);
	}
	return (0);
}

/*
 * Function: ft_str_is_printable(char *str)
 * ----------------------------------------
 * Checks if the string `str` contains only printable ASCII characters.
 * 
 * Syntax:
 * int ft_str_is_printable(char *str)
 * 
 * Arguments:
 * - char *str: A pointer to the string to be checked.
 * 
 * Returns:
 * - int: 1 if `str` contains only printable ASCII characters, 0 otherwise.
 * 
 * Examples:
 * - ft_str_is_printable("Hello!")
 * -> 1 (string "Hello!" contains only printable characters)
 * - ft_str_is_printable("Hello\n")
 * -> 0 (string "Hello\n" contains non-printable newline character)
 * - ft_str_is_printable("")
 * -> 1 (an empty string is considered to contain only printable characters)
 */
int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_is_printable(str[i]))
			return (0);
		i++;
	}
	return (1);
}
