/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:13:34 by provira-          #+#    #+#             */
/*   Updated: 2024/07/09 19:13:36 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_strstr(char *str, char *to_find)
 * ---------------------------------------------
 * Finds the first occurrence of the substring `to_find` in the string `str`.
 * 
 * Syntax:
 * char *ft_strstr(char *str, char *to_find)
 * 
 * Arguments:
 * - char *str: The string to be searched.
 * - char *to_find: The substring to find within `str`.
 * 
 * Returns:
 * - A pointer to the first occurrence of `to_find` in `str`, 
 *   or NULL if not found.
 * 
 * Examples:
 * - ft_strstr("hello world", "world") -> "world"
 * - ft_strstr("hello world", "") -> "hello world"
 * - ft_strstr("hello world", "abc") -> NULL
 */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	f;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		f = 0;
		if (str[i] == to_find[f])
		{
			while (str[i + f] != '\0' && to_find[f] != '\0')
			{
				if (str[i + f] != to_find[f])
					break ;
				f++;
			}
			if (to_find[f] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}

/*
Executing: norminette -R CheckForbiddenSourceHeader ft_strstr.c:
ft_strstr.c: OK!

Executing: gcc -Wall -Wextra -Werror main.c ft_strstr.c:
gcc: OK!

Executing: ./a.out | cat -e:
return the same positon: 1 (yours: '0', std: '0')$
return the same positon: 1 (yours: '2', std: '2')$
return NULL on no match: 1, 1$
return the first position on empty string: 1 (yours: '0', std: '0')$
return same position on both empty strings: 1$
return NULL if src is empty: 1 (yours: '(nil)', std: '(nil)')$


Executing: diff --text expected out:
< expected, > your result
6c6
< return NULL if src is empty: 1 (yours: '0x0', std: '0x0')$
---
> return NULL if src is empty: 1 (yours: '(nil)', std: '(nil)')$


══════════════════════════════    Ex04 failed!    ══════════════════════════════
*/