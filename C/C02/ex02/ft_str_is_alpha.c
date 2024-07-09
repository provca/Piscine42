/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:29:12 by provira-          #+#    #+#             */
/*   Updated: 2024/07/08 15:29:15 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_is_alpha(char c)
 * -----------------------------
 * Checks if the character `c` is an alphabetic letter
 * (either uppercase or lowercase).
 * 
 * Syntax:
 * int ft_is_alpha(char c)
 * 
 * Arguments:
 * - char c: The character to be checked.
 * 
 * Returns:
 * - int: 1 if `c` is an alphabetic letter, 0 otherwise.
 * 
 * Examples:
 * - ft_is_alpha('A') -> 1 (character 'A' is an alphabetic letter)
 * - ft_is_alpha('z') -> 1 (character 'z' is an alphabetic letter)
 * - ft_is_alpha('1') -> 0 (character '1' is not an alphabetic letter)
 * - ft_is_alpha('!') -> 0 (character '!' is not an alphabetic letter)
 */
int	ft_is_alpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}

/*
 * Function: ft_str_is_alpha(char *str)
 * ------------------------------------
 * Checks if the string `str` contains only alphabetic letters.
 * 
 * Syntax:
 * int ft_str_is_alpha(char *str)
 * 
 * Arguments:
 * - char *str: A pointer to the string to be checked.
 * 
 * Returns:
 * - int: 1 if `str` contains only alphabetic letters, 0 otherwise.
 * 
 * Examples:
 * - ft_str_is_alpha("Hello")
 * -> 1 (string "Hello" contains only alphabetic letters)
 * - ft_str_is_alpha("Hello123")
 * -> 0 (string "Hello123" contains non-alphabetic characters)
 * - ft_str_is_alpha("")
 * -> 1 (an empty string is considered to contain only alphabetic letters)
 */
int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_is_alpha(str[i]))
			return (0);
		i++;
	}
	return (1);
}
