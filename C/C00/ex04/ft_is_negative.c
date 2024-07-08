/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:30:23 by provira-          #+#    #+#             */
/*   Updated: 2024/07/06 10:37:53 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_is_negative(int n)
 * --------------------------------
 * Prints 'N' if the given integer is negative, otherwise prints 'P'
 * (positive or zero).
 * 
 * Syntax:
 * void ft_is_negative(int n)
 * 
 * Arguments:
 * - int n: The integer to be checked.
 * 
 * Returns:
 * - None
 * 
 * Examples:
 * - ft_is_negative(-5) -> "N" (prints 'N' to indicate the number is negative)
 * - ft_is_negative(0) -> "P" (prints 'P' to indicate the number is non-negative)
 */
#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n < 0)
		write(1, "N", 1);
	else
		write(1, "P", 1);
}
