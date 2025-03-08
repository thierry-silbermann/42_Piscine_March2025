#include <stdio.h>
#include <stdlib.h>

int     **ft_allocate_mem_tab(int size);
void    ft_free_tab(int **tab, int size);

int	is_valid(int **grid, int row, int col, int num, int N)
{
	int	i;

	i = 0;
	// Check if num is already in the row or column
	while (i < N) 
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
	printf("Latin Square:\n");
	while  (i < N)
	{
		j = 0;
		while (j < N)
		{
			printf("%d ", grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

void generate_latin_square(int **grid, int row, int col, int N)
{
	int	num;
	int	next_row;
	int	next_col;

	if (row == N) {
		print_grid(grid, N);
		return;
	}
	next_row = (col == N - 1) ? row + 1 : row;
	next_col = (col + 1) % N;
	num = 1;
	while (num <= N) 
	{
		if (is_valid(grid, row, col, num, N))
		{
			grid[row][col] = num;
			generate_latin_square(grid, next_row, next_col, N);
			grid[row][col] = 0; // Backtrack
		}
		num++;
	}
}

int main()
{
	int	N;
	int	**grid;

	printf("Enter an integer N (1-9): ");
	scanf("%d", &N);

	if (N < 1 || N > 9)
	{
		printf("Invalid input. N must be between 1 and 9.\n");
		return 1;
	}
	grid = ft_allocate_mem_tab(N);  // Allocate tab of size NxN
	generate_latin_square(grid, 0, 0, N);
	ft_free_tab(grid, N);  // Free tab
	return (0);
}
