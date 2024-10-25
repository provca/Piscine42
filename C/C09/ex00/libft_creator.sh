#!/bin/bash

# Compile the source files into object files with -Wall, -Wextra, and -Werror flags
gcc -Wall -Wextra -Werror -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

# Create a static library (archive) named libft.a from the object files
ar rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o

# Generate an index for the archive to optimize access to its symbols
ranlib libft.a
