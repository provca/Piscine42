/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:08:01 by provira-          #+#    #+#             */
/*   Updated: 2024/07/06 15:33:18 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_ultimate_ft(int *********nbr)
 * -------------------------------------------
 * Updates the value pointed to by a nine-level deep pointer `nbr` to 42.
 * 
 * Syntax:
 * void ft_ultimate_ft(int *********nbr)
 * 
 * Arguments:
 * - int *********nbr: A pointer to a nine-level deep pointer to an integer.
 * 
 * Returns:
 * - None
 * 
 * Examples:
 * - int num = 0;
 *   int *ptr1 = &num;
 *   int **ptr2 = &ptr1;
 *   int ***ptr3 = &ptr2;
 *   int ****ptr4 = &ptr3;
 *   int *****ptr5 = &ptr4;
 *   int ******ptr6 = &ptr5;
 *   int *******ptr7 = &ptr6;
 *   int ********ptr8 = &ptr7;
 *   int *********ptr9 = &ptr8;
 *   ft_ultimate_ft(ptr9); // num is now 42
 */
void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}
