/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col_row.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:49:59 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/09 15:09:41 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	*ft_allocate_mem_arr(int size);
int	**ft_allocate_mem_tab(int size);
void	ft_free_arr(int *arr);
void	ft_free_tab(int **tab, int size);
void	display_all_view(int *all_view, int size);

// Function to count visible buildings from a given direction
int	count_visible(int *arr, int size)
{
	int	count;
	int	max_height;
	int	i;

	count = 0;
	max_height = 0;
	i = 0;
	while (i < size)
	{
		if (arr[i] > max_height)
		{
			max_height = arr[i];
			count++;
		}
		i++;
	}
	return (count);
}

void	print_views_col(int **grid, int *all_view, int size)
{
	int	i;
	int	j;
	int	*column;
	int	*reversed_column;

        j = 0;
        column = ft_allocate_mem_arr(size);
        reversed_column = ft_allocate_mem_arr(size);
        while (j < size)
        {
                i = 0;
                while (i < size)
                {
                        column[i] = grid[i][j];
                        reversed_column[i] = grid[size - i - 1][j];
                        i++;
                }
                all_view[j] = count_visible(column, size);
                all_view[size + j] = count_visible(reversed_column, size);
                j++;
        }
}

void	print_views_row(int **grid, int *all_view, int size)
{
	int	i;
	int	j;
	int	*reversed_row;

	i = 0;
	reversed_row = ft_allocate_mem_arr(size);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			reversed_row[j] = grid[i][size - j - 1];
			j++;
		}
		all_view[2 * size + i] = count_visible(grid[i], size);
		all_view[3 * size + i] = count_visible(reversed_row, size);
		i++;
	}
}
