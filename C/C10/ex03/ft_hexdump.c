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
#include <libgen.h>
#include <stdio.h>

#define BUFFER_SIZE 16

/*
 * This function writes a string to the standard error output using the 
   write system call.
 * It prints each character of the string one by one.
 */
static void	ft_putstr_err(char *str)
{
	while (*str)
		write(2, str++, 1);
}

/*
 * This function displays an error message to the standard error.
 * It outputs the program name, the filename, and the corresponding 
 * error message
 * from the system's errno variable.
 */
static void	display_error(char *prog_name, char *filename)
{
	ft_putstr_err(basename(prog_name));
	ft_putstr_err(": ");
	ft_putstr_err(filename);
	ft_putstr_err(": ");
	ft_putstr_err(strerror(errno));
	ft_putstr_err("\n");
}

/*
 * This function prints a formatted line of hexadecimal and ASCII 
   representation of a file's contents.
 * The line shows the memory address (offset), followed by the bytes 
   in hexadecimal and their ASCII equivalents.
 * Non-printable characters are replaced by a dot ('.').
 */
static void	print_line(unsigned char *buffer, int size, int offset)
{
	int	i;

	printf("%08x  ", offset);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (i < size)
			printf("%02x ", buffer[i]);
		else
			printf("   ");
		if (++i % 8 == 0)
			printf(" ");
	}
	printf(" |");
	i = 0;
	while (i < size)
	{
		if (buffer[i] >= 32 && buffer[i] <= 126)
			write(1, &buffer[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	printf("|\n");
}

/*
 * This function reads a file in chunks of BUFFER_SIZE bytes and 
   prints its hexadecimal dump.
 * It calls print_line to display each chunk, with the appropriate 
   offset and byte values.
 */
static void	display_hexdump(int fd)
{
	unsigned char	buffer[BUFFER_SIZE];
	int				bytes_read;
	int				offset;

	offset = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		print_line(buffer, bytes_read, offset);
		offset += bytes_read;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0)
		display_error("ft_hexdump", "");
}

/*
 * The main function of the program. It takes one or more 
   filenames as command line arguments.
 * For each file, it attempts to open the file and then 
   displays its hexadecimal dump.
 * If a file cannot be opened, it displays an error message.
 */
int	main(int argc, char **argv)
{
	int	fd;
	int	i;

	if (argc < 2)
	{
		ft_putstr_err("Usage: ft_hexdump [file ...]\n");
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
