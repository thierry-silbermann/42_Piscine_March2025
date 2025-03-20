# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 15:44:00 by tsilberm          #+#    #+#              #
#    Updated: 2025/03/17 19:56:44 by tsilberm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Compile all .c files into object files
cc -Wall -Wextra -Werror -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

# Create the static library
ar rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o

# Index the library
ranlib libft.a

# Cleanup object files
rm -f *.o
