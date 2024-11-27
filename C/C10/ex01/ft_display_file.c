/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: provira- <provira-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:42:35 by provira-          #+#    #+#             */
/*   Updated: 2024/11/15 15:42:37 by provira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

#define BUFFER_SIZE 1024

/*
 * This function writes a string to the standard error output.
 * It uses the write system call to output each character of the string.
 */
void	ft_putstr_err(char *str)
{
	while (*str)
		write(2, str++, 1);
}

/*
 * This function handles errors by printing the program name, filename, and the
 * error message associated with the last system error (errno).
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
 * This function reads the content of the file associated with the given file
 * descriptor and writes it to the standard output in 
 * chunks of BUFFER_SIZE bytes.
 */
void	read_and_display(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		write(1, buffer, bytes_read);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
}

/*
 * This function attempts to open the file specified by the filename.
 * If the file cannot be opened, it calls display_error to show 
 * the error message.
 * Otherwise, it reads the file and displays its contents.
 */
void	display_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		display_error("ft_display_file", filename);
		return ;
	}
	read_and_display(fd);
	close(fd);
}

/*
 * This is the main function of the program. It checks the number of arguments
 * provided. If the number of arguments is incorrect, an error message
 * is printed.
 * If a valid file name is provided, display_file is called to print the contents
 * of the specified file.
 */
int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr_err("File name missing.\n");
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr_err("Too many arguments.\n");
		return (1);
	}
	display_file(argv[1]);
	return (0);
}
