/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:10:16 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/19 21:37:18 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	parse_first_line(char *line, t_map *map_info)
{
	int	row_nb;
	int	i;
	int	len;

	row_nb = 0;
	i = 0;
	len = ft_strlen(line);
	if (len < 4 || !ft_isdigit(line[0]))
		return (0);
	while (i < len - 3)
	{
		if (!ft_isdigit(line[i]))
			return (0);
		row_nb = row_nb * 10 + (line[i++] - '0');
	}
	map_info->row_size = row_nb;
	if (!ft_isprintable(line[len - 3])
		|| !ft_isprintable(line[len - 2])
		|| !ft_isprintable(line[len - 1]))
		return (0);
	map_info->empty = line[len - 3];
	map_info->obstacle = line[len - 2];
	map_info->full = line[len - 1];
	return (check_duplicates_char(map_info));
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
	{
		free(line);
		return (0);
	}
	if (ft_len_int(map_info->row_size) + 3 != ft_strlen(line))
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}

int	solve(int fd)
{
	t_map	map_info;

	if (!ingest_map(fd, &map_info))
	{
		print_error();
		return (0);
	}
	if (!read_map(fd, &map_info))
	{
		print_error_and_free_map(&map_info);
		return (0);
	}
	if (!map_info.map || !validate_map(&map_info))
	{
		print_error_and_free_map(&map_info);
		return (0);
	}
	find_biggest_square(&map_info);
	free_map(&map_info);
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;

	if (argc == 1)
	{
		fd = 0;
		if (!solve(fd))
			exit(1);
	}
	i = 0;
	while (i < (argc - 1))
	{
		fd = open(argv[i + 1], O_RDONLY);
		if (fd == -1)
			print_error();
		else
			solve(fd);
		if ((i + 1) < (argc - 1))
			ft_putchar('\n');
		i++;
	}
	return (0);
}
