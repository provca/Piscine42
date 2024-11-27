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
#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

/*
 * Definition of the t_bool type:
 *  This defines an alias for the int type, which will be used to represent
 *  a boolean value.
 */
typedef int	t_bool;

/*
 * Boolean values definition:
 *  TRUE is 1, which represents a true value.
 *  FALSE is 0, which represents a false value.
 */
# define TRUE 1
# define FALSE 0

/*
 * Argument count message definitions:
 *  EVEN_MSG is used when the number of arguments is even.
 *  ODD_MSG is used when the number of arguments is odd.
 */
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"

/*
 * Success code definition:
 *  SUCCESS is defined as 0, which typically indicates that the
 *  operation was successful.
 */
# define SUCCESS 0

/*
 * Inline function that checks if a number is even:
 *  The function takes an integer as a parameter and returns TRUE (1) 
 *  if the number is even,
 *  and FALSE (0) if the number is odd.
 *  It uses the modulus operator to determine the parity.
 */
static inline t_bool	ft_is_even(int nbr)
{
	return (nbr % 2 == 0);
}

#endif