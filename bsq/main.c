#include "ft_header.h"

void	print_error(void)
{
	write(2, "map error\n", 10);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_duplicates_char(map_struct *map_info)
{
	if (map_info->empty == map_info->obstacle)
		return (0);
	if (map_info->empty == map_info->full)
		return (0);
	if (map_info->obstacle == map_info->full)
		return (0);
	return (1);
}

int	parse_first_line(char *line, map_struct *map_info)
{
	int len;

	len = ft_strlen(line);
	if (len != 4)
		return 0;
	map_info->size = line[0] - '0';
	map_info->empty = line[len - 3];
	map_info->obstacle = line[len - 2];
	map_info->full = line[len - 1];
	return (check_duplicates_char(map_info));
}

int	validate_map(map_struct *map_info)
{
	int	line_length;
	int	i;
	int	j;
	int	len;

	line_length = -1;
	i = 0;
	while (i < map_info->size)
	{
		len = ft_strlen(map_info->map[i]);
		if (map_info->map[i][len - 1] == '\n')
			map_info->map[i][len - 1] = '\0';
		if (line_length == -1)
			line_length = ft_strlen(map_info->map[i]);
		else if ((int)strlen(map_info->map[i]) != line_length)
			return (0);
		j = 0;
		while (j < line_length)
		{
			if (map_info->map[i][j] != map_info->empty && map_info->map[i][j] != map_info->obstacle)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_strdup(char *s)
{
	int		len;
	int		i;
	char	*dup;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

char	**read_map(int fd, int rows)
{
	int		i;
	int		j;
	char	**map;
	char		buffer[BUFFER_SIZE];

	map = malloc(rows * sizeof(char *));
	if (!map)
		return (NULL);
    
	i = 0;
	while (i < rows && read(fd, buffer, BUFFER_SIZE) > 0)
	{
		map[i] = ft_strdup(buffer);
		if (!map[i])
		{
			j = 0;
			while (j < i)
			{
				free(map[j]);
				j++;
			}
			free(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

// Check if it frees correctly with velgrind
void	free_map(map_struct *map_info)
{
	int	i;

	i = 0;
	while (i < map_info->size)
	{
		free(map_info->map[i]);
		i++;
	}
	free(map_info->map);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		// Read on the standard input
		return (0);
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print_error();
		return (1);
	}
    
	char first_line[BUFFER_SIZE];
	int i = 0;
	int bytes_read;
	char c;
	while ((bytes_read = read(fd, &c, 1)) > 0 && c != '\n')
	{
		first_line[i++] = c;
		if (i >= BUFFER_SIZE - 1)
		{
			print_error();
			close(fd);
			return (1);
		}
	}
	first_line[i] = '\0';
    
	map_struct map_info;
	if (!parse_first_line(first_line, &map_info))
	{
		print_error();
		close(fd);
		return (1);
	}
	printf("%d / %c / %c / %c\n", map_info.size, map_info.empty, map_info.obstacle, map_info.full);  // to delete
    
	map_info.map = read_map(fd, map_info.size);
	close(fd);
	if (!map_info.map || !validate_map(&map_info))
	{
		print_error();
		return (1);
	}
	free_map(&map_info); 
	return (0);
}
