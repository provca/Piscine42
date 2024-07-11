/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:17:34 by provira-          #+#    #+#             */
/*   Updated: 2024/07/11 20:17:36 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_fibonacci()
 * ------------------------
 * Computes the Fibonacci number at the given index using a recursive approach.
 *
 * Syntax:
 * int ft_fibonacci(int index)
 *
 * Arguments:
 * - int index: The position in the Fibonacci sequence to compute.
 *              The first position (index 0) corresponds to the value 0,
 *              and the second position (index 1) corresponds to the value 1.
 *
 * Returns:
 * - The Fibonacci number at the specified position.
 *   Returns -1 if the index is negative.
 *
 * Examples:
 * - ft_fibonacci(0) -> 0
 * - ft_fibonacci(1) -> 1
 * - ft_fibonacci(5) -> 5
 */
int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0 || index == 1)
		return (index);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
