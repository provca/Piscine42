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

char	ft_lowcase(char c)
{
	return (c + ('a' - 'A'));
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = ft_lowcase(str[i]);
		}
		i++;
	}
	return (str);
}
