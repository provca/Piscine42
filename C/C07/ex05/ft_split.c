/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:19:54 by provira-          #+#    #+#             */
/*   Updated: 2024/11/13 00:19:58 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
 * Function: is_charset()
 * ----------------------
 * Checks if a character is present in a given charset.
 *
 * Syntax:
 * int is_charset(char c, char *charset)
 *
 * Arguments:
 * - char c: The character to search for.
 * - char *charset: The charset (string) to search within.
 *
 * Returns:
 * - 1 if the character is found in the charset.
 * - 0 if the character is not found in the charset.
 *
 * Example:
 * - is_charset('a', "abc");  // returns 1
 * - is_charset('z', "abc");  // returns 0
 */
int	is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

/*
 * Function: count_words()
 * ------------------------
 * Counts the number of words in a string, based on the provided charset.
 * A word is defined as a sequence of characters not present in the charset.
 *
 * Syntax:
 * int count_words(char *str, char *charset)
 *
 * Arguments:
 * - char *str: The string to search through.
 * - char *charset: The charset (string) to define word boundaries.
 *
 * Returns:
 * - The number of words in the string.
 *
 * Example:
 * - count_words("hello world!", " "); // returns 2
 * - count_words("hello, world", ", ");  // returns 2
 */
int	count_words(char *str, char *charset)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (is_charset(*str, charset))
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

/*
 * Function: word_length()
 * ------------------------
 * Determines the length of a word in the string, which is 
 * delimited by characters
 * found in the charset.
 *
 * Syntax:
 * int word_length(char *str, char *charset)
 *
 * Arguments:
 * - char *str: The string representing the word to measure.
 * - char *charset: The charset (string) to define word boundaries.
 *
 * Returns:
 * - The length of the word, which is the number of characters
 *   before a charset character is encountered.
 *
 * Example:
 * - word_length("hello world!", " ");  // returns 5
 * - word_length("apple", ", ");        // returns 5
 */
int	word_length(char *str, char *charset)
{
	int	length;

	length = 0;
	while (str[length] && !is_charset(str[length], charset))
		length++;
	return (length);
}

/*
 * Function: extract_word()
 * -------------------------
 * Extracts a word from a string of a given length.
 *
 * Syntax:
 * char *extract_word(char *str, int length)
 *
 * Arguments:
 * - char *str: The string from which to extract the word.
 * - int length: The length of the word to extract.
 *
 * Returns:
 * - A new dynamically allocated string containing the extracted word.
 * - NULL if memory allocation fails.
 *
 * Example:
 * - extract_word("hello world!", 5); // returns "hello"
 * - extract_word("apple", 5);        // returns "apple"
 */
char	*extract_word(char *str, int length)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (length + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < length)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

/*
 * Function: ft_split()
 * --------------------
 * Splits a string into an array of words, using the provided charset
 * to define word boundaries. The result is a dynamically allocated array
 * of strings (words).
 *
 * Syntax:
 * char **ft_split(char *str, char *charset)
 *
 * Arguments:
 * - char *str: The string to split.
 * - char *charset: The charset (string) that defines word boundaries.
 *
 * Returns:
 * - A dynamically allocated array of strings (words), terminated by NULL.
 * - NULL if memory allocation fails or if there are issues processing the input.
 *
 * Example:
 *   // returns {"hello", "world!"}
 * - ft_split("hello world!", " ");
 *   // returns {"apple", "orange", "banana"}
 * - ft_split("apple,orange,banana", ",");
 */
char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		words;
	int		i;
	int		length;

	words = count_words(str, charset);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			length = word_length(str, charset);
			result[i] = extract_word(str, length);
			if (!result[i++])
				return (NULL);
			str += length;
		}
		else
			str++;
	}
	result[i] = 0;
	return (result);
}
