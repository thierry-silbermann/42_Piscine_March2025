/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:24:35 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/18 19:28:42 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_map(t_map *map_s)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_s->row_size)
	{
		j = 0;
		while (map_s->map[i][j])
		{
			write(1, &map_s->map[i][j], 1);
			j++;
		}
		if (i != map_s->row_size - 1)
			ft_putchar('\n');
		i++;
	}
}
