/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:31:06 by provira-          #+#    #+#             */
/*   Updated: 2024/07/08 16:31:08 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_is_uppercase(char c)
 * ---------------------------------
 * Checks if the character `c` is an uppercase alphabetic letter (A-Z).
 * 
 * Syntax:
 * int ft_is_uppercase(char c)
 * 
 * Arguments:
 * - char c: The character to be checked.
 * 
 * Returns:
 * - int: 1 if `c` is an uppercase alphabetic letter, 0 otherwise.
 * 
 * Examples:
 * - ft_is_uppercase('A')
 * -> 1 (character 'A' is an uppercase letter)
 * - ft_is_uppercase('z')
 * -> 0 (character 'z' is not an uppercase letter)
 * - ft_is_uppercase('1')
 * -> 0 (character '1' is not a letter)
 * - ft_is_uppercase('!')
 * -> 0 (character '!' is not a letter)
 */
int	ft_is_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	return (0);
}

/*
 * Function: ft_str_is_uppercase(char *str)
 * ----------------------------------------
 * Checks if the string `str` contains only uppercase alphabetic letters.
 * 
 * Syntax:
 * int ft_str_is_uppercase(char *str)
 * 
 * Arguments:
 * - char *str: A pointer to the string to be checked.
 * 
 * Returns:
 * - int: 1 if `str` contains only uppercase alphabetic letters, 0 otherwise.
 * 
 * Examples:
 * - ft_str_is_uppercase("HELLO")
 *   -> 1 (string "HELLO" contains only uppercase letters)
 * - ft_str_is_uppercase("Hello")
 *   -> 0 (string "Hello" contains lowercase letters)
 * - ft_str_is_uppercase("ABC123")
 *   -> 0 (string "ABC123" contains non-alphabetic characters)
 * - ft_str_is_uppercase("")
 *   -> 1 (an empty string is considered to contain only uppercase letters)
 */
int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_is_uppercase(str[i]))
			return (0);
		i++;
	}
	return (1);
}
