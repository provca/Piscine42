/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:39:38 by provira-          #+#    #+#             */
/*   Updated: 2024/07/16 15:39:41 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Header: ft_boolean.h
 * --------------------
 * Header file defining boolean constants and macros.
 *
 * Macros:
 * - TRUE: Represents the boolean value 'true', defined as 1.
 * - FALSE: Represents the boolean value 'false', defined as 0.
 * - EVEN(nbr): Macro that checks if a number is even.
 *              Returns true (1) if the number is even, false (0) otherwise.
 * - EVEN_MSG: Message indicating that the number of arguments is even.
 * - ODD_MSG: Message indicating that the number of arguments is odd.
 * - SUCCESS: Represents the success status code, defined as 0.
 */
#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

typedef int	t_bool;

# define TRUE 1
# define FALSE 0

/*
 * Macro: EVEN(nbr)
 * ----------------
 * Checks if a number is even.
 *
 * Parameters:
 * - int nbr: Number to be checked.
 *
 * Returns:
 * - t_bool: TRUE (1) if the number is even, FALSE (0) otherwise.
 */
# define EVEN(nbr) ((nbr) % 2 == 0)

# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"

# define SUCCESS 0

#endif

/*
#include "ft_boolean.h"
void	ft_putstr(char *str)
{
	while (*str)
	write(1, str++, 1);
}

t_bool ft_is_even(int nbr)
{
	return ((EVEN(nbr)) ? TRUE : FALSE);
}
int main(int argc, char **argv)
{
	(void)argv;
	if (ft_is_even(argc - 1) == TRUE)
		ft_putstr(EVEN_MSG);
	else
		ft_putstr(ODD_MSG);
	return (SUCCESS);
}

*/