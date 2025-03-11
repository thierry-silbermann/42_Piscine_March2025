#include <stdio.h>
#include <stdlib.h>

void	print_solution(int *board)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		printf("%d", board[i]);
		i++;
	}
	printf("\n");
}



int	is_safe(int *board, int col, int row)
{
	int	prev_col;
	int	prev_row;

	prev_col = 0;
   	while (prev_col < col)
	{
		prev_row = board[prev_col];
		if (prev_row == row || abs(prev_row - row) == abs(prev_col - col))
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
		return;
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
	int board[10];
	int count;

	count = 0;
	solve(board, 0, &count);
	return count;
}

int	main(void)
{
	printf("Total Solutions: %d\n", ft_ten_queens_puzzle());
	return (0);
}

