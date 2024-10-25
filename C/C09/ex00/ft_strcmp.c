/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:59:39 by provira-          #+#    #+#             */
/*   Updated: 2024/07/09 17:59:41 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_strcmp(char *s1, char *s2)
 * ---------------------------------------
 * Compares two null-terminated strings lexicographically.
 * 
 * Syntax:
 * int ft_strcmp(char *s1, char *s2)
 * 
 * Arguments:
 * - char *s1: A pointer to the first string to be compared.
 * - char *s2: A pointer to the second string to be compared.
 * 
 * Returns:
 * - An integer less than, equal to, or greater than zero if `s1` is found,
 *   respectively, to be less than, to match, or be greater than `s2`.
 *   Specifically, it returns the difference between the first pair of 
 *   differing characters in the two strings.
 * 
 * Examples:
 * - ft_strcmp("abc", "abc") -> 0 (strings are equal)
 * - ft_strcmp("abc", "abd") -> -1 (s1 is less than s2)
 * - ft_strcmp("abc", "abb") -> 1 (s1 is greater than s2)
 * - ft_strcmp("abc", "abcd") -> -100 (s1 is less than s2 because the 
 *   difference between '\0' and 'd' is -100)
 */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			break ;
		else if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
