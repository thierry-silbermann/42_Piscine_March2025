/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:42:43 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/19 19:43:12 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	print_error(void)
{
	write(1, "map error\n", 10);
}

void	print_error_and_free_map(t_map *map)
{
	print_error();
	free_map(map);
}
