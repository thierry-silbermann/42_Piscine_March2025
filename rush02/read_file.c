#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include "ft_header.h"

void    ft_putstr_error(char *str)
{
    while (*str)
        write(2, str++, 1);
    write(2, "\n", 1);
}

void    ft_display_file(char *filename)
{
    int     fd;
    char    buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr_error("Cannot read file");
        return;
    }
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
        write(1, buffer, bytes_read);
    close(fd);
}

int is_positive_number(char *str)
{
    if (!str || !*str)
        return (0);
    while (*str)
    {
        if (!isdigit(*str))
            return (0);
        str++;
    }
    return (1);
}
