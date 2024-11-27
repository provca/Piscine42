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
 * This function writes a string to the standard error output.
 * It uses the write system call to output each character of the string.
 */
void	ft_putstr_err(char *str)
{
	while (*str)
		write(2, str++, 1);
}

/*
 * This function opens a file for reading and prints its contents to 
   the standard output.
 * If the file cannot be opened, it outputs an error message.
 * It reads the file in chunks of BUFFER_SIZE bytes and writes them
 * to the output.
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
		return ;
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		write(1, buffer, bytes_read);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	close(fd);
}

/*
 * This is the main function of the program.
 * It checks the number of command-line arguments and calls 
 * display_file to print
 * the content of the file specified in the argument.
 * If the number of arguments is incorrect, an error message
 * is printed.
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
