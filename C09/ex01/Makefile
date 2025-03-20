# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 15:28:37 by tsilberm          #+#    #+#              #
#    Updated: 2025/03/13 17:59:15 by tsilberm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC       = cc
CFLAGS   = -Wall -Wextra -Werror

# Directories
SRCDIR   = srcs
INCDIR   = includes

# Source files and object files
SRCS     = $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_strcmp.c
OBJS     = $(SRCS:.c=.o)

# Library name
NAME     = libft.a

# Default rule (same as `make all`)
all: $(NAME)

# Create the library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compile .c files into .o files
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

# Remove object files
clean:
	rm -f $(OBJS)

# Remove object files and library
fclean: clean
	rm -f $(NAME)

# Rebuild the library
re: fclean all

.PHONY: all clean fclean re
