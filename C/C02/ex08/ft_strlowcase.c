/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:46:26 by provira-          #+#    #+#             */
/*   Updated: 2024/07/08 16:46:29 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_to_lowercase(char c)
 * ---------------------------------
 * Converts the uppercase character `c` to its
 * corresponding lowercase equivalent.
 * If `c` is not an uppercase letter, it returns `c` unchanged.
 * 
 * Syntax:
 * char ft_to_lowercase(char c)
 * 
 * Arguments:
 * - char c: The character to be converted to lowercase.
 * 
 * Returns:
 * - char: The lowercase equivalent of `c` if `c`
 *   is an uppercase letter, otherwise `c`.
 * 
 * Examples:
 * - ft_to_lowercase('A') -> 'a' (converts uppercase 'A' to lowercase 'a')
 * - ft_to_lowercase('z') -> 'z' (no change since 'z' is already lowercase)
 * - ft_to_lowercase('1') -> '1' (no change since '1' is not a letter)
 * - ft_to_lowercase('\n') -> '\n' (no change since '\n' is not a letter)
 */
char	ft_to_lowercase(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + ('a' - 'A'));
	}
	return (c);
}

/*
 * Function: ft_strlowcase(char *str)
 * ----------------------------------
 * Converts all uppercase letters in the string `str` to lowercase.
 * 
 * Syntax:
 * char *ft_strlowcase(char *str)
 * 
 * Arguments:
 * - char *str: A pointer to the string whose uppercase letters
 *   are to be converted.
 * 
 * Returns:
 * - char *: A pointer to the modified string `str` with all uppercase letters
 *   converted to lowercase.
 * 
 * Examples:
 * - char str[] = "Hello, World!";
 *   ft_strlowcase(str); // str now contains "hello, world!"
 * - char str[] = "123ABC";
 *   ft_strlowcase(str); // str now contains "123abc"
 * - char str[] = "";
 *   ft_strlowcase(str); // str remains "" (empty string remains unchanged)
 */
char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_to_lowercase(str[i]);
		i++;
	}
	return (str);
}
