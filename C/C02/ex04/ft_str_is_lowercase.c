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
int	ft_is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	return (0);
}

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
