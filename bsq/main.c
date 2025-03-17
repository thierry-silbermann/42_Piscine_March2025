/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:10:16 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/17 17:55:08 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	parse_first_line(char *line, t_map *map_info)
{
	int	len;

	len = ft_strlen(line);
	if (len != 4)
		return (0);
	map_info->row_size = line[0] - '0';
	map_info->empty = line[len - 3];
	map_info->obstacle = line[len - 2];
	map_info->full = line[len - 1];
	return (check_duplicates_char(map_info));
}

char	**allocate_map_memory(t_map *map_info)
{
	char	**map;

	map = (char **) malloc((map_info->row_size) * sizeof(char *));
	if (!map)
		return (NULL);
	return (map);
}

int	read_map(int fd, t_map *map_info)
{
	int		i;
	int		j;
	char	**map;
	char	*line;

	map = allocate_map_memory(map_info);
	i = 0;
	line = get_line(fd);
	while (i < (map_info->row_size) && line != NULL && map)
	{
		map[i] = (char *) malloc((ft_strlen(line) + 1) * sizeof(char));
		if (!map[i])
			return (0);
		j = 0;
		while (line[j])
		{
			map[i][j] = line[j];
			j++;
		}
		map[i][j] = '\0';
		line = get_line(fd);
		i++;
	}
	map_info->map = map;
	return (1);
}

// Check if it frees correctly with velgrind
void	free_map(t_map *map_info)
{
	int	i;

	i = 0;
	while (i < map_info->row_size)
	{
		free(map_info->map[i]);
		i++;
	}
	free(map_info->map);
}

char	*get_line(int fd)
{
	char	*line;
	int		i;
	char	c;
	int		bytes_read;

	i = 0;
	line = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (line == NULL)
		return (NULL);
	bytes_read = read(fd, &c, 1);
	while (bytes_read > 0 && c != '\n')
	{
		line[i++] = c;
		if (i >= BUFFER_SIZE - 1)
		{
			print_error();
			close(fd);
			return (NULL);
		}
		bytes_read = read(fd, &c, 1);
	}
	line[i] = '\0';
	return (line);
}

int	ingest_map(int fd, t_map *map_info)
{
	char	*line;

	line = get_line(fd);
	if (!parse_first_line(line, map_info))
		return (0);
	free(line);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	map_info;
	int		i;
	int		fd;

	if (argc == 1)
	{
		// Read on the standard input
		return (0);
	}
	i = 0;
	while (i < argc - 1)
	{
		fd = open(argv[i + 1], O_RDONLY);
		if (fd == -1)
		{
			print_error();
			return (1);
		}
		if (!ingest_map(fd, &map_info))
		{
			print_error();
			return (1);
		}
		/* to delete */
		printf("%d / ", map_info.row_size);
		printf("%c / ", map_info.empty);
		printf("%c / ", map_info.obstacle);
		printf("%c\n", map_info.full);
		if (!read_map(fd, &map_info))
		{
			printf("Erreur read map\n");
			return (1); // Handle error
		}
		close(fd);
		/* line below to delete */
		print_map(&map_info);
		if (!map_info.map || !validate_map(&map_info))
		{
			print_error();
			printf("map validate failed");
			// Need to free memory
			return (1);
		}
		find_biggest_square(&map_info);                      // new line
		free_map(&map_info);
		i++;
	}
	return (0);
}
