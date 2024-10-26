/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:23:09 by provira-          #+#    #+#             */
/*   Updated: 2024/10/25 14:23:12 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Function: ft_print_memory
 * -------------------------
 * Displays the memory content in hexadecimal and ASCII representation.
 *
 * Syntax:
 * void *ft_print_memory(void *addr, unsigned int size)
 *
 * Arguments:
 * - void *addr: Starting address of the memory block to be displayed.
 * - unsigned int size: The size of the memory block in bytes.
 *
 * Returns:
 * - Returns the starting address of the memory block for convenience.
 *
 * Function details:
 * - This function iterates over the memory block pointed to by `addr`,
 *   processing 16 bytes per line. For each line:
 *      1. The memory address is displayed in hexadecimal format.
 *      2. The content of the memory is printed in hexadecimal format,
 *         with a space every two bytes.
 *      3. The ASCII representation of each byte is displayed,
 *         substituting non-printable characters with a dot (`.`).
 *
 * Supporting functions:
 * - print_address(): Prints the memory address in hexadecimal.
 * - print_hex_content(): Converts and displays each byte in hex, 
 *   adding a space every two bytes.
 * - print_char_content(): Displays each byte as an ASCII character, 
 *   or `.` if non-printable.
 *
 * Example:
 * char str[] = "Hello World!";
 * ft_print_memory(str, sizeof(str));
 * 
 * This would display the memory content of `str` in 
 * both hex and ASCII representation.
 */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_address(unsigned long addr)
{
	char	*hex;
	char	buffer[16];
	int		i;

	hex = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		buffer[i] = hex[addr % 16];
		addr = addr / 16;
		i--;
	}
	write(1, buffer, 16);
}

void	print_hex_content(unsigned char *mem, int size)
{
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			ft_putchar(hex[mem[i] / 16]);
			ft_putchar(hex[mem[i] % 16]);
		}
		else
			write(1, "  ", 2);
		if (i % 2 == 1)
			ft_putchar(' ');
		i++;
	}
}

void	print_char_content(unsigned char *mem, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (mem[i] >= 32 && mem[i] <= 126)
			ft_putchar(mem[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				line_size;

	i = 0;
	while (i < size)
	{
		line_size = 16;
		if (size - i < 16)
			line_size = size - i;
		print_address((unsigned long)(addr + i));
		write(1, ": ", 2);
		print_hex_content((unsigned char *)addr + i, line_size);
		print_char_content((unsigned char *)addr + i, line_size);
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}
