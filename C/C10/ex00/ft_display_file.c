/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:42:03 by provira-          #+#    #+#             */
/*   Updated: 2024/11/27 15:42:05 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

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
 * Function: display_file
 * -----------------------
 * Reads the content of a file and writes it to the standard output.
 *
 * Parameters:
 * - char *filename: The name of the file to read.
 *
 * Returns:
 * - Nothing.
 *
 * Notes:
 * - If the file cannot be opened, an error message is displayed on the standard error.
 * - The function reads the file in chunks defined by `BUFFER_SIZE`.
 */
void	display_file(char *filename)
{
	int		fd;
	int		bytes_read;
	char	buffer[BUFFER_SIZE];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_err("Cannot read file.\n");
		return;
	}
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
		write(1, buffer, bytes_read);
	close(fd);
}

/*
 * Function: main
 * --------------
 * Entry point of the program. Handles arguments and calls `display_file`.
 *
 * Parameters:
 * - int argc: The number of arguments passed to the program.
 * - char **argv: The array of argument strings.
 *
 * Returns:
 * - 0 on successful execution.
 *
 * Notes:
 * - Displays an error message if no file name is provided or if too many arguments are given.
 */
int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_putstr_err("File name missing.\n");
	else if (argc > 2)
		ft_putstr_err("Too many arguments.\n");
	else
		display_file(argv[1]);
	return (0);
}
