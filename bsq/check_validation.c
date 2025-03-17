/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:41:08 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/17 17:40:51 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	check_duplicates_char(t_map *map_info)
{
	if (map_info->empty == map_info->obstacle)
		return (0);
	if (map_info->empty == map_info->full)
		return (0);
	if (map_info->obstacle == map_info->full)
		return (0);
	return (1);
}

int	validate_row(int i, int j, int len, t_map *map_info)
{
	if (map_info->map[i][j] == map_info->empty)
		return (1);
	else if (map_info->map[i][j] == map_info->obstacle)
		return (1);
	else if (j == len - 1 && map_info->map[i][j] == '\0')
		return (1);
	return (0);
}

int	validate_map(t_map *map_info)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	map_info->col_size = ft_strlen(map_info->map[0]);
	while (i < map_info->row_size)
	{
		len = ft_strlen(map_info->map[i]);
		if (len != map_info->col_size)
			return (0);
		j = 0;
		while (j < len)
		{
			if (!validate_row(i, j, len, map_info))
				return (0);
			j++;
		}
		i++;
	}
	if (i != map_info->row_size)
		return (0);
	return (1);
}
