/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:54:40 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/09 14:52:47 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**ft_allocate_mem_tab(int size)
{
	int	i;
	int	j;
	int	**tab;

	i = 0;
	tab = malloc(size * sizeof(int *));
	while (i < size)
	{
		tab[i] = malloc(size * sizeof(int));
		j = 0;
		while (j < size)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
}

int	*ft_allocate_mem_arr(int size)
{
	int	i;
	int	*arr;

	i = 0;
	arr = malloc(size * sizeof(int));
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}

void	ft_free_tab(int **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_arr(int *arr)
{
	free(arr);
}
