# Name of the executable
# ------------------------
NAME := ft_display_file

# Compiler and flags
# -------------------
# CC: Specifies the compiler to be used (gcc in this case).
# CFLAGS: Compilation flags to enable all warnings (-Wall),
#         additional warnings (-Wextra), and treat warnings as errors (-Werror).
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# Source and object files
# ------------------------
# SRCS: Lists the source files required to build the project.
# OBJS: Defines the object files by replacing the `.c` extension in SRCS with `.o`.
SRCS := ft_display_file.c
OBJS := $(SRCS:.c=.o)

# Default target
# --------------
# The default target (all) builds the executable $(NAME).
all: $(NAME)

# Linking step
# ------------
# $(NAME): The target executable depends on the object files $(OBJS).
# Links all object files to create the executable.
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Cleaning intermediate files
# ---------------------------
# clean: Removes all object files.
clean:
	rm -f $(OBJS)

# Full clean
# ----------
# fclean: Removes both object files and the final executable.
fclean: clean
	rm -f $(NAME)

# Rebuild
# -------
# re: Forces a clean rebuild of the project by invoking fclean and all targets.
re: fclean all

# Compilation rule for object files
# ---------------------------------
# %.o: %.c: Compiles each `.c` file into a corresponding `.o` file.
# $<: Refers to the first dependency (the `.c` file).
# $@: Refers to the target (the `.o` file).
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# PHONY targets
# -------------
# Declares targets that are not associated with actual files to prevent conflicts.
.PHONY: all clean fclean re

