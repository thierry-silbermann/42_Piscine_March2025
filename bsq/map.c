/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibarre <vibarre@student.42lisboa.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:35:54 by vibarre           #+#    #+#             */
/*   Updated: 2025/03/18 19:43:21 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

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
		j = -1;
		while (line[++j])
			map[i][j] = line[j];
		map[i][j] = '\0';
		free(line);
		line = get_line(fd);
		i++;
	}
	map_info->map = map;
	free(line);
	return (1);
}

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
