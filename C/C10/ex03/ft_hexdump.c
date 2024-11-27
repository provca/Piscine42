/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:43:45 by provira-          #+#    #+#             */
/*   Updated: 2024/11/27 15:43:49 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include <stdio.h>

#define BUFFER_SIZE 16

/*
 * Function: ft_putstr_err
 * ------------------------
 * Outputs a string to the standard error output.
 *
 * Parameters:
 * - char *str: The string to be displayed.
 *
 * Returns:
 * - Nothing.
 */
void	ft_putstr_err(char *str)
{
	while (*str)
		write(2, str++, 1);
}

/*
 * Function: display_error
 * ------------------------
 * Displays an error message when a file cannot be opened.
 *
 * Parameters:
 * - char *prog_name: The name of the program (for error reporting).
 * - char *filename: The name of the file that failed to open.
 *
 * Returns:
 * - Nothing.
 *
 * Output Format:
 * - "<prog_name>: <filename>: <error_message>"
 */
void	display_error(char *prog_name, char *filename)
{
	ft_putstr_err(basename(prog_name));
	ft_putstr_err(": ");
	ft_putstr_err(filename);
	ft_putstr_err(": ");
	ft_putstr_err(strerror(errno));
	ft_putstr_err("\n");
}

/*
 * Function: print_hex
 * -------------------
 * Prints the hexadecimal representation of a buffer to standard output.
 *
 * Parameters:
 * - unsigned char *buffer: Pointer to the buffer containing the data.
 * - int size: The size of the data to print.
 *
 * Returns:
 * - Nothing.
 *
 * Notes:
 * - Each byte is printed as a two-digit hexadecimal value.
 * - The output is grouped into 8-byte chunks.
 */
void	print_hex(unsigned char *buffer, int size)
{
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (i < size)
			printf("%02x ", buffer[i]);
		else
			printf("   ");
		if (i % 8 == 7)
			printf(" ");
	}
}

/*
 * Function: print_ascii
 * ---------------------
 * Prints the ASCII representation of a buffer to standard output.
 *
 * Parameters:
 * - unsigned char *buffer: Pointer to the buffer containing the data.
 * - int size: The size of the data to print.
 *
 * Returns:
 * - Nothing.
 *
 * Notes:
 * - Non-printable characters are replaced with a dot ('.').
 */
void	print_ascii(unsigned char *buffer, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (buffer[i] >= 32 && buffer[i] <= 126)
			write(1, &buffer[i], 1);
		else
			write(1, ".", 1);
	}
}

/*
 * Function: display_hexdump
 * -------------------------
 * Reads the content of a file and displays it in a hexadecimal and ASCII format.
 *
 * Parameters:
 * - int fd: The file descriptor of the file to display.
 *
 * Returns:
 * - Nothing.
 *
 * Notes:
 * - For each chunk of `BUFFER_SIZE` bytes, the offset, hexadecimal representation, 
 *   and ASCII representation are printed in a formatted way.
 * - If an error occurs during reading, it calls `display_error`.
 */
void	display_hexdump(int fd)
{
	unsigned char	buffer[BUFFER_SIZE];
	int				bytes_read;
	int				offset = 0;

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		printf("%08x  ", offset);
		print_hex(buffer, bytes_read);
		printf(" |");
		print_ascii(buffer, bytes_read);
		printf("|\n");
		offset += bytes_read;
	}
	if (bytes_read < 0)
		display_error("ft_hexdump", "");
}

/*
 * Function: main
 * --------------
 * Entry point of the program. Processes command-line arguments and displays
 * the hexdump of the specified files.
 *
 * Parameters:
 * - int argc: The number of arguments passed to the program.
 * - char **argv: An array of argument strings.
 *
 * Returns:
 * - 0 on successful execution, 1 on error.
 *
 * Notes:
 * - If no file is provided or if an error occurs while opening a file, an error message is displayed.
 * - Displays the hexdump for each file passed as an argument.
 */
int	main(int argc, char **argv)
{
	int	fd;
	int	i;

	if (argc < 2)
	{
		ft_putstr_err("Usage: ");
		ft_putstr_err(basename(argv[0]));
		ft_putstr_err(" [file ...]\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
			display_error(argv[0], argv[i]);
		else
		{
			display_hexdump(fd);
			close(fd);
		}
		i++;
	}
	return (0);
}
