/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:27:44 by provira-          #+#    #+#             */
/*   Updated: 2024/07/08 16:27:47 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_is_lowercase(char c)
 * ---------------------------------
 * Checks if the character `c` is a lowercase alphabetic letter (a-z).
 * 
 * Syntax:
 * int ft_is_lowercase(char c)
 * 
 * Arguments:
 * - char c: The character to be checked.
 * 
 * Returns:
 * - int: 1 if `c` is a lowercase alphabetic letter, 0 otherwise.
 * 
 * Examples:
 * - ft_is_lowercase('a') -> 1 (character 'a' is a lowercase letter)
 * - ft_is_lowercase('Z') -> 0 (character 'Z' is not a lowercase letter)
 * - ft_is_lowercase('1') -> 0 (character '1' is not a letter)
 * - ft_is_lowercase('!') -> 0 (character '!' is not a letter)
 */
int	ft_is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	return (0);
}

/*
 * Function: ft_str_is_lowercase(char *str)
 * ----------------------------------------
 * Checks if the string `str` contains only lowercase alphabetic letters.
 * 
 * Syntax:
 * int ft_str_is_lowercase(char *str)
 * 
 * Arguments:
 * - char *str: A pointer to the string to be checked.
 * 
 * Returns:
 * - int: 1 if `str` contains only lowercase alphabetic letters, 0 otherwise.
 * 
 * Examples:
 * - ft_str_is_lowercase("hello")
 * -> 1 (string "hello" contains only lowercase letters)
 * - ft_str_is_lowercase("Hello")
 * -> 0 (string "Hello" contains uppercase letters)
 * - ft_str_is_lowercase("123abc")
 * -> 0 (string "123abc" contains non-alphabetic characters)
 * - ft_str_is_lowercase("")
 * -> 1 (an empty string is considered to contain only lowercase letters)
 */
int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_is_lowercase(str[i]))
			return (0);
		i++;
	}
	return (1);
}
