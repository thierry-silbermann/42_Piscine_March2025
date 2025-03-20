/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:24:02 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/18 19:18:16 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	init_answer(t_answer *answer)
{
	answer->i = -1;
	answer->j = -1;
	answer->size = 0;
}

void	update_answer(t_answer *answer, int i, int j, int size)
{
	answer->i = i;
	answer->j = j;
	answer->size = size;
}

int	find_size(t_map *map_info, int i, int j, int size)
{
	int	k;
	int	l;

	k = 0;
	while (k < size && i + k < map_info->row_size)
	{
		l = 0;
		while (l < size && j + l < map_info->col_size)
		{
			if (map_info->map[i + k][j + l] != map_info->empty)
				return (0);
			l++;
		}
		if (l < size)
			return (0);
		k++;
	}
	if (k < size)
		return (0);
	return (ft_max(size, find_size(map_info, i, j, size + 1)));
}

void	print_solution(t_answer answer, t_map *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->row_size)
	{
		j = 0;
		while (j < map_info->col_size)
		{
			if (
				i >= answer.i
				&& i < (answer.i + answer.size)
				&& j >= answer.j
				&& j < (answer.j + answer.size)
			)
				ft_putchar(map_info->full);
			else
				ft_putchar(map_info->map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	find_biggest_square(t_map *map_info)
{
	t_answer	answer;
	int			i;
	int			j;
	int			size;

	init_answer(&answer);
	i = 0;
	while (i < map_info->row_size)
	{
		j = 0;
		while (j < map_info->col_size)
		{
			size = find_size(map_info, i, j, 1);
			if (size > answer.size)
				update_answer(&answer, i, j, size);
			j++;
		}
		i++;
	}
	print_solution(answer, map_info);
}
