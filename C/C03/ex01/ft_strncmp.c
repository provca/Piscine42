/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:29:54 by provira-          #+#    #+#             */
/*   Updated: 2024/07/09 18:29:56 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_strncmp(char *s1, char *s2, unsigned int n)
 * --------------------------------------------------------
 * Compares up to `n` characters of two null-terminated strings 
 * lexicographically.
 * 
 * Syntax:
 * int ft_strncmp(char *s1, char *s2, unsigned int n)
 * 
 * Arguments:
 * - char *s1: A pointer to the first string to be compared.
 * - char *s2: A pointer to the second string to be compared.
 * - unsigned int n: The maximum number of characters to compare.
 * 
 * Returns:
 * - An integer less than, equal to, or greater than zero if `s1` is found,
 *   respectively, to be less than, to match, or be greater than `s2` up to
 *   the first `n` characters.
 * 
 * Examples:
 * - ft_strncmp("abc", "abc", 3) -> 0 (first 3 characters are equal)
 * - ft_strncmp("abc", "abd", 3) 
 *   -> -1 (s1 is less than s2 within the first 3 characters)
 * - ft_strncmp("abc", "abb", 3) 
 *   -> 1 (s1 is greater than s2 within the first 3 characters)
 * - ft_strncmp("abc", "abcd", 4)
 *   -> -100 (s1 is less than s2 within the first 4 characters)
 */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			break ;
		else if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
