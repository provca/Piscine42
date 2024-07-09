/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:50:56 by provira-          #+#    #+#             */
/*   Updated: 2024/07/08 16:51:01 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_to_lowercase(char c)
 * ---------------------------------
 * Converts the uppercase character `c` to its corresponding
 * lowercase equivalent.
 * If `c` is not an uppercase letter, it returns `c` unchanged.
 * 
 * Syntax:
 * char ft_to_lowercase(char c)
 * 
 * Arguments:
 * - char c: The character to be converted to lowercase.
 * 
 * Returns:
 * - char: The lowercase equivalent of `c` if `c` is an uppercase letter,
 *   otherwise `c`.
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
 * - char *: A pointer to the modified string `str` 
 *   with all uppercase letters converted to lowercase.
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

/*
 * Function: ft_strcapitalize(char *str)
 * -------------------------------------
 * Capitalizes the first letter of each word in the string `str` and converts
 * all other letters to lowercase.
 * 
 * Syntax:
 * char *ft_strcapitalize(char *str)
 * 
 * Arguments:
 * - char *str: A pointer to the string to be capitalized.
 * 
 * Returns:
 * - char *: A pointer to the modified string `str` with
 *   the first letter of each word capitalized.
 * 
 * Examples:
 * - char str[] = "hello, world!";
 *   ft_strcapitalize(str); // str now contains "Hello, World!"
 * - char str[] = "42 is the Answer";
 *   ft_strcapitalize(str); // str now contains "42 Is The Answer"
 * - char str[] = "HELLO";
 *   ft_strcapitalize(str); // str now contains "Hello"
 */
char	*ft_strcapitalize(char *str)
{
	unsigned int	i;

	i = 0;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (i == 0)
			str[0] = ft_to_uppercase(str[0]);
		else
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				if ((str[i - 1] < '0')
					|| (str[i - 1] > '9' && str[i - 1] < 'A')
					|| (str[i - 1] > 'Z' && str[i - 1] < 'a')
					|| (str[i - 1] > 'z'))
				{
					str[i] = ft_to_uppercase(str[i]);
				}
			}
		}
		i++;
	}
	return (str);
}
