/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:58:05 by provira-          #+#    #+#             */
/*   Updated: 2024/07/16 16:58:06 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

/*
 * This inline function computes the absolute value of an integer.
 * If the input value is negative, it returns the positive counterpart.
 * If the input value is already positive, it returns the value unchanged.
 */
static inline int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

#endif
