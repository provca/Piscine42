/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:10:21 by provira-          #+#    #+#             */
/*   Updated: 2024/07/11 12:10:23 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

bool	is_valid_base(char *base)
{
	int	len;
	int	i;
	int	j;

	len = ft_strlen(base);
	if (len <= 1)
		return (false);
	i = 0;
	while (i < len)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < ' ')
			return (false);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	ft_atoi_base(char *str, char *base)
{
}
