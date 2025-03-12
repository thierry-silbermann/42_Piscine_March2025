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
	@echo "Creating library $(NAME)..."
	ar rcs $(NAME) $(OBJS)
	@echo "Library $(NAME) created successfully!"

# Compile .c files into .o files
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

# Remove object files
clean:
	@echo "Removing object files..."
	rm -f $(OBJS)

# Remove object files and library
fclean: clean
	@echo "Removing $(NAME)..."
	rm -f $(NAME)

# Rebuild the library
re: fclean all

.PHONY: all clean fclean re

