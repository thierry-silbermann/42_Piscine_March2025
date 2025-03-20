/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:51:18 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/11 11:19:09 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_abs(int a, int b)
{
	if (a >= b)
		return (a - b);
	else
		return (b - a);
}

void	print_solution(int *board)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		write(1, &(char){board[i] + '0'}, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_safe(int *board, int col, int row)
{
	int	prev_col;
	int	prev_row;

	prev_col = 0;
	while (prev_col < col)
	{
		prev_row = board[prev_col];
		if (prev_row == row || (ft_abs(prev_row, row) == ft_abs(prev_col, col)))
			return (0);
		prev_col++;
	}
	return (1);
}

void	solve(int *board, int col, int *count)
{
	int	row;

	if (col == 10)
	{
		print_solution(board);
		(*count)++;
		return ;
	}
	row = 0;
	while (row < 10)
	{
		if (is_safe(board, col, row))
		{
			board[col] = row;
			solve(board, col + 1, count);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;

	count = 0;
	solve(board, 0, &count);
	return (count);
}
/*
int	main(void)
{
	printf("Total Solutions: %d\n", ft_ten_queens_puzzle());
	return (0);
}*/
