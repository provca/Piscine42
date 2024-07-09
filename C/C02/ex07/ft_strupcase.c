/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:38:50 by provira-          #+#    #+#             */
/*   Updated: 2024/07/08 16:38:52 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_to_uppercase(char c)
 * ---------------------------------
 * Converts the lowercase character `c` to its corresponding
 * uppercase equivalent.
 * If `c` is not a lowercase letter, it returns `c` unchanged.
 * 
 * Syntax:
 * char ft_to_uppercase(char c)
 * 
 * Arguments:
 * - char c: The character to be converted to uppercase.
 * 
 * Returns:
 * - char: The uppercase equivalent of `c` if `c` is a lowercase letter,
 *   otherwise `c`.
 * 
 * Examples:
 * - ft_to_uppercase('a') -> 'A' (converts lowercase 'a' to uppercase 'A')
 * - ft_to_uppercase('Z') -> 'Z' (no change since 'Z' is already uppercase)
 * - ft_to_uppercase('1') -> '1' (no change since '1' is not a letter)
 * - ft_to_uppercase('\n') -> '\n' (no change since '\n' is not a letter)
 */
char	ft_to_uppercase(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - ('a' - 'A'));
	}
	return (c);
}

/*
 * Function: ft_strupcase(char *str)
 * ---------------------------------
 * Converts all lowercase letters in the string `str` to uppercase.
 * 
 * Syntax:
 * char *ft_strupcase(char *str)
 * 
 * Arguments:
 * - char *str: A pointer to the string
 *   whose lowercase letters are to be converted.
 * 
 * Returns:
 * - char *: A pointer to the modified string `str`
 *   with all lowercase letters converted to uppercase.
 * 
 * Examples:
 * - char str[] = "Hello, World!";
 *   ft_strupcase(str); // str now contains "HELLO, WORLD!"
 * - char str[] = "123abc";
 *   ft_strupcase(str); // str remains "123abc"
 *   (non-alphabetic characters are not changed)
 * - char str[] = "";
 *   ft_strupcase(str); // str remains "" (empty string remains unchanged)
 */
char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_to_uppercase(str[i]);
		i++;
	}
	return (str);
}
