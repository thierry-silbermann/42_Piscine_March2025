#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 30720  // ~30 KB

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}


void	ft_cat(int fd)
{
	char	buffer[BUFFER_SIZE];
	int	 bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		if (write(STDOUT_FILENO, buffer, bytes_read) != bytes_read)
		{
			perror("Error writing to stdout");
			return;
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0)
	{
		perror("Error reading file");
	}
}

int main(int argc, char *argv[])
{
	int fd;
	int i;

	if (argc == 1)
	{
		ft_cat(STDIN_FILENO);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (ft_strcmp(argv[i], "-") == 0)
			{
				ft_cat(STDIN_FILENO);
			}
			else
			{
				fd = open(argv[i], O_RDONLY);
				if (fd < 0)
				{
					perror("Error opening file");
					continue; // Skip to the next file
				}
				ft_cat(fd);
				close(fd);
			}
			i++;
		}
	}
	return (0);
}
