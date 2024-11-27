/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:41:24 by provira-          #+#    #+#             */
/*   Updated: 2024/11/27 15:41:27 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
 * Function: is_separator
 * -----------------------
 * Checks if a given character is present in the provided charset.
 *
 * Parameters:
 * - char c: The character to check.
 * - char *charset: The set of characters to compare against.
 *
 * Returns:
 * - 1 if the character is found in the charset, 0 otherwise.
 */
int	is_separator(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

/*
 * Function: word_count
 * ---------------------
 * Counts the number of words in a string separated by 
 * characters from the charset.
 *
 * Parameters:
 * - char *str: The string to analyze.
 * - char *charset: The set of characters considered as word separators.
 *
 * Returns:
 * - The number of words found in the string.
 */
int	word_count(char *str, char *charset)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_separator(*str, charset) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_separator(*str, charset))
			in_word = 0;
		str++;
	}
	return (count);
}

/*
 * Function: word_dup
 * -------------------
 * Creates a duplicate of a substring representing a word of a given length.
 *
 * Parameters:
 * - char *start: Pointer to the beginning of the word in the string.
 * - int len: The length of the word to copy.
 *
 * Returns:
 * - A pointer to the newly allocated word, or NULL if memory allocation fails.
 */
char	*word_dup(char *start, int len)
{
	char	*word;
	int		i;

	*word = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

/*
 * Function: ft_split
 * -------------------
 * Splits a string into an array of words, using a charset as delimiters.
 *
 * Parameters:
 * - char *str: The string to split.
 * - char *charset: The set of characters used as word separators.
 *
 * Returns:
 * - A pointer to the newly allocated array of strings (words),
 *   or NULL if memory allocation fails.
 *
 * Notes:
 * - The last element of the array is NULL.
 */
char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		word_len;

	i = 0;
	word_len = 0;
	result = (char **)malloc(sizeof(char *) * (word_count(str, charset) + 1));
	if (!result)
		return (NULL);
	while (*str)
	{
		if (!is_separator(*str, charset))
		{
			word_len = 0;
			while (str[word_len] && !is_separator(str[word_len], charset))
				word_len++;
			result[i++] = word_dup(str, word_len);
			str += word_len;
		}
		else
			str++;
	}
	result[i] = NULL;
	return (result);
}
