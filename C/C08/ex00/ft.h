/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:24:07 by provira-          #+#    #+#             */
/*   Updated: 2024/07/16 15:24:11 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Header: ft.h
 * -----------
 * Header file containing function prototypes for string manipulation.
 *
 * Functions:
 * - void ft_putchar(char c): Outputs a character to the standard output.
 * - void ft_swap(int *a, int *b): Swaps the values of two integers.
 * - void ft_putstr(char *str): Outputs a string to the standard output.
 * - int ft_strlen(char *str): Returns the length of a string.
 * - int ft_strcmp(char *s1, char *s2): Compares two strings lexicographically.
 */
#ifndef FT_H
# define FT_H
# include <unistd.h>

/*
 * Function: ft_putchar
 * --------------------
 * Outputs a character to the standard output.
 *
 * Parameters:
 * - char c: Character to be output.
 */
void	ft_putchar(char c);

/*
 * Function: ft_swap
 * -----------------
 * Swaps the values of two integers.
 *
 * Parameters:
 * - int *a: Pointer to the first integer.
 * - int *b: Pointer to the second integer.
 */
void	ft_swap(int *a, int *b);

/*
 * Function: ft_putstr
 * -------------------
 * Outputs a string to the standard output.
 *
 * Parameters:
 * - char *str: Pointer to the string to be output.
 */
void	ft_putstr(char *str);

/*
 * Function: ft_strlen
 * -------------------
 * Returns the length of a string.
 *
 * Parameters:
 * - char *str: Pointer to the string whose length is to be determined.
 *
 * Returns:
 * - int: Length of the string.
 */
int		ft_strlen(char *str);

/*
 * Function: ft_strcmp
 * -------------------
 * Compares two strings lexicographically.
 *
 * Parameters:
 * - char *s1: Pointer to the first string.
 * - char *s2: Pointer to the second string.
 *
 * Returns:
 * - int: 0 if s1 and s2 are equal,
 *        negative value if s1 is less than s2,
 *        positive value if s1 is greater than s2.
 */
int		ft_strcmp(char *s1, char *s2);
#endif
