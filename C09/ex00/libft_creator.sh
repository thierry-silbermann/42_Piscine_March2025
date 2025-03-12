#!/bin/bash

# Compile all .c files into object files
gcc -Wall -Wextra -Werror -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

# Create the static library
ar rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o

# Index the library
ranlib libft.a

# Cleanup object files
rm -f *.o

echo "Library libft.a has been created successfully!"
