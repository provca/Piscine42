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

#define BUFFER_SIZE 1024

static void	ft_putstr_err(char *str)
{
	while (*str)
		write(2, str++, 1);
}

static void	display_error(char *prog_name, char *filename)
{
	ft_putstr_err(basename(prog_name));
	ft_putstr_err(": ");
	ft_putstr_err(filename);
	ft_putstr_err(": ");
	ft_putstr_err(strerror(errno));
	ft_putstr_err("\n");
}

static void	display_usage(void)
{
	ft_putstr_err("Usage: ft_tail -c <num> [file ...]\n");
}

static int	validate_args(int argc, char **argv, int *bytes)
{
	if (argc < 4 || strcmp(argv[1], "-c") != 0)
	{
		display_usage();
		return (1);
	}
	*bytes = atoi(argv[2]);
	if (*bytes <= 0)
	{
		ft_putstr_err("Invalid byte count.\n");
		return (1);
	}
	return (0);
}

static void	read_and_print_tail(int fd, int n)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;
	int		total_bytes;
	char	*tail;

	tail = (char *)malloc(n);
	if (!tail)
	{
		ft_putstr_err("Memory allocation error.\n");
		return;
	}
	total_bytes = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		if (total_bytes + bytes_read <= n)
			memcpy(tail + total_bytes, buffer, bytes_read);
		else
		{
			memmove(tail, tail + bytes_read, n - bytes_read);
			memcpy(tail + n - bytes_read, buffer, bytes_read);
		}
		total_bytes += bytes_read;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (total_bytes >= n)
		write(1, tail, n);
	free(tail);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	bytes;
	int	i;

	if (validate_args(argc, argv, &bytes))
		return (1);
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
			read_and_print_tail(fd, bytes);
			close(fd);
		}
		i++;
	}
	return (0);
}
