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
/*
 * Header: ft_abs.h
 * ---------------
 * Header file defining the ABS macro for absolute value calculation.
 *
 * Macros:
 * - ABS(Value): Macro that computes the absolute value of a number.
 *               If Value is negative, it returns -Value.
 *               If Value is non-negative, it returns Value.
 */
#ifndef FT_ABS_H
# define FT_ABS_H

/*
 * Macro: ABS(Value)
 * -----------------
 * Computes the absolute value of a number using a macro.
 *
 * Explanation:
 * - The macro ABS(Value) is defined to compute the absolute value of 
 *   the parameter Value.
 * - It uses a ternary-like expression to achieve this:
 *   - (((Value) < 0) * (-1) * (Value)): If Value is less than 0, 
 *     this part of the expression evaluates to -1 * Value, 
 *     effectively converting negative Value to its positive counterpart.
 *   - ((Value) >= 0) * (Value): If Value is greater than or equal to 0, 
 *     this part evaluates to Value itself, leaving non-negative
 *     values unchanged.
 * - When combined, the expression effectively computes the absolute
 *   value of Value, handling both negative and non-negative cases in
 *   a single line of code.
 *
 * Example:
 * - ABS(-5) expands to (((-5) < 0) * (-1) * (-5) + ((-5) >= 0) * (-5))
 *            which simplifies to (1 * -1 * -5 + 0 * -5)
 *            which further simplifies to 5.
 *   Thus, ABS(-5) yields 5, the absolute value of -5.
 */
# define ABS(Value) (((Value) < 0) * (-1) * (Value) + ((Value) >= 0) * (Value))

#endif
