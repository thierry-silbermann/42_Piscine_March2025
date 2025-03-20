/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_comb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustoliv <gustoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:50:52 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/09 21:29:56 by gustoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		**ft_allocate_mem_tab(int size);
int		*ft_allocate_mem_arr(int size);
void	ft_free_tab(int **tab, int size);
void	ft_free_arr(int *arr);
void	print_views_col(int **grid, int *all_view, int size);
void	print_views_row(int **grid, int *all_view, int size);
void	display_all_view(int *all_view, int size);
int		get_n(char *str);
int		*arr_input(char *str, int size);
void	ft_putchar(char c);
int		check_solution(int *arr_input, int *arr_solution, int size);

int	is_valid(int **grid, int *row_col, int num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (grid[row_col[0]][i] == num || grid[i][row_col[1]] == num)
			return (0);
		i++;
	}
	return (1);
}

void	print_grid(int **grid, int N)
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (j != N - 1)
				ft_putchar('0' + grid[i][j]);
			else
				ft_putchar('0' + grid[i][j]);
			j++;
		}
		if (i != N - 1)
			ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

int	check_filled_grid(int **grid, int size, int *input)
{
	int	*all_view;

	all_view = ft_allocate_mem_arr(4 * size);
	print_views_col(grid, all_view, size);
	print_views_row(grid, all_view, size);
	if (check_solution(input, all_view, size) == 1)
	{
		print_grid(grid, size);
		ft_free_arr(all_view);
		return (1);
	}
	else
	{
		ft_free_arr(all_view);
		return (0);
	}
}

int	generate_latin_square(int **grid, int *row_col, int size, int *input)
{
	int	num;
	int	next_row_col[2];

	next_row_col[0] = 0;
	next_row_col[1] = 0;
	if (row_col[0] == size)
		return (check_filled_grid(grid, size, input));
	next_row_col[0] = row_col[0] + (row_col[1] == size - 1);
	next_row_col[1] = (row_col[1] + 1) % size;
	num = 1;
	while (num <= size)
	{
		if (is_valid(grid, row_col, num, size))
		{
			grid[row_col[0]][row_col[1]] = num;
			if (generate_latin_square(grid, next_row_col, size, input))
				return (1);
			grid[row_col[0]][row_col[1]] = 0;
		}
		num++;
	}
	return (0);
}

int	main(int argc, char*argv[])
{
	int	**grid;
	int	*input;
	int	next_row_col[2];

	next_row_col[0] = 0;
	next_row_col[1] = 0;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	input = arr_input(argv[1], 4);
	if (!(input))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	grid = ft_allocate_mem_tab(4);
	if (!(generate_latin_square(grid, next_row_col, 4, input)))
	{
		write(1, "Error\n", 6);
	}
	ft_free_tab(grid, 4);
	ft_free_arr(input);
	return (0);
}
