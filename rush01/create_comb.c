/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_comb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:50:52 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/09 15:12:25 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	**ft_allocate_mem_tab(int size);
int	*ft_allocate_mem_arr(int size);
void	ft_free_tab(int **tab, int size);
void	ft_free_arr(int *arr);
void	print_views_col(int **grid, int *all_view, int size);
void    print_views_row(int **grid, int *all_view, int size);
void	display_all_view(int *all_view, int size);
int	get_n(char *str);
int	*arr_input(char *str, int size);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_solution(int *arr_input, int *arr_solution, int size)
{
	int	i;

	i = 0;
	while (i < size * 4)
	{
		if (arr_input[i] != arr_solution[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_valid(int **grid, int row, int col, int num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (grid[row][i] == num || grid[i][col] == num)
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


int	generate_latin_square(int **grid, int row, int col, int size, int *input)
{
	int	num;
	int	next_row;
	int	next_col;

	if (row == size)
		return (check_filled_grid(grid, size, input));
	if (col == size - 1)
		next_row = row + 1;
	else
		next_row = row;
	next_col = (col + 1) % size;
	num = 1;
	while (num <= size)
	{
		if (is_valid(grid, row, col, num, size))
		{
			grid[row][col] = num;
			if (generate_latin_square(grid, next_row, next_col, size, input))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

int	main(int argc, char*argv[])
{
	int	size;
	int	**grid;
	int	*input;

	if (argc != 2)
	{
		printf("Error\n");
		return (0);
	}
	size = get_n(argv[1]);
	if (size < 1 || size > 9)
	{
		printf("Invalid input. N must be between 1 and 9.\n");
		return (0);
	}
	input = arr_input(argv[1], size);
	grid = ft_allocate_mem_tab(size);
	if (!(generate_latin_square(grid, 0, 0, size, input)))
	{
		printf("Error\n");
	}
	ft_free_tab(grid, size);
	return (0);
}
