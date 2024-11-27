/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:43:11 by provira-          #+#    #+#             */
/*   Updated: 2024/11/27 15:43:13 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

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
 * Displays an error message to standard error if a file cannot be opened.
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
 * Function: display_tail
 * -----------------------
 * Reads and outputs the last `n` bytes of a file.
 *
 * Parameters:
 * - int fd: The file descriptor of the file to read.
 * - int n: The number of bytes to display from the end of the file.
 *
 * Returns:
 * - Nothing.
 *
 * Notes:
 * - Uses a buffer of size `BUFFER_SIZE` to read chunks of the file.
 * - Allocates a buffer of `n` bytes to store the tail.
 * - If the file is larger than `n` bytes, the content in the buffer is shifted to keep the last `n` bytes.
 */
void	display_tail(int fd, int n)
{
	char	buffer[BUFFER_SIZE];
	char	*tail;
	int		bytes_read;
	int		total_bytes = 0;
	int		i;

	tail = (char *)malloc(n * sizeof(char));
	if (!tail)
		return;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (total_bytes + bytes_read <= n)
			memcpy(tail + total_bytes, buffer, bytes_read);
		else
		{
			memmove(tail, tail + bytes_read, n - bytes_read);
			memcpy(tail + n - bytes_read, buffer, bytes_read);
		}
		total_bytes += bytes_read;
	}
	if (total_bytes >= n)
		write(1, tail, n);
	free(tail);
}

/*
 * Function: main
 * --------------
 * Entry point of the program. Processes command-line arguments to display
 * the last `n` bytes of the specified files.
 *
 * Parameters:
 * - int argc: The number of arguments passed to the program.
 * - char **argv: An array of argument strings.
 *
 * Returns:
 * - 0 on successful execution.
 *
 * Notes:
 * - The program expects the first argument to be `-c`, followed by the number
 *   of bytes to display, and then one or more filenames.
 * - Displays an error if the arguments are incorrect or if a file cannot be opened.
 * - For multiple files, outputs a header with the file name before each file's content.
 */
int	main(int argc, char **argv)
{
	int		fd;
	int		bytes;
	int		i;

	if (argc < 4 || strcmp(argv[1], "-c") != 0 || (bytes = atoi(argv[2])) <= 0)
	{
		ft_putstr_err("Usage: ");
		ft_putstr_err(basename(argv[0]));
		ft_putstr_err(" -c <num> [file ...]\n");
		return (1);
	}
	i = 3;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
			display_error(argv[0], argv[i]);
		else
		{
			if (argc > 4)
			{
				write(1, "==> ", 4);
				write(1, argv[i], strlen(argv[i]));
				write(1, " <==\n", 5);
			}
			display_tail(fd, bytes);
			close(fd);
		}
		i++;
	}
	return (0);
}
