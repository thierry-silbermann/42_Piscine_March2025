#include <stdio.h>


int     **ft_allocate_mem_tab(int size);
void    ft_free_tab(int **tab, int size);

#define MAX_N 9

int N;
int grid[MAX_N][MAX_N];

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

void	print_views()
{
	int	top_views[MAX_N];
	int	bottom_views[MAX_N];
	int	left_views[MAX_N];
	int	right_views[MAX_N];

	// Compute top and bottom views for columns
	for (int j = 0; j < N; j++)
	{
		int column[MAX_N], reversed_column[MAX_N];
		for (int i = 0; i < N; i++)
		{
			column[i] = grid[i][j];            // Normal column
			reversed_column[i] = grid[N - i - 1][j];  // Reverse column
		}
		top_views[j] = count_visible(column, N);
		bottom_views[j] = count_visible(reversed_column, N);
	}

	// Compute left and right views for rows
	for (int i = 0; i < N; i++) 
	{
		int reversed_row[MAX_N];
		for (int j = 0; j < N; j++)
		{
			reversed_row[j] = grid[i][N - j - 1];  // Reverse row
		}
		left_views[i] = count_visible(grid[i], N);
		right_views[i] = count_visible(reversed_row, N);
	}

	//////////////////////////////////////////////////////////

	// Print top views (aligned)
	printf("    ");
	for (int j = 0; j < N; j++)
	{
		printf("%d ", top_views[j]);
	}
	printf("\n");

	// Print separator
	printf("    ");
	for (int j = 0; j < N; j++)
	{
		printf("--");
	}
	printf("\n");

	// Print grid with row views
	for (int i = 0; i < N; i++)
	{
		printf("%d | ", left_views[i]);
		for (int j = 0; j < N; j++)
		{
			printf("%d ", grid[i][j]);
		}
		printf("| %d\n", right_views[i]);
	}

	// Print separator
	printf("    ");
	for (int j = 0; j < N; j++)
	{
		printf("--");
	}
	printf("\n");

	// Print bottom views (aligned)
	printf("    ");
	for (int j = 0; j < N; j++)
	{
		printf("%d ", bottom_views[j]);
	}
	printf("\n");
}

int main(void)
{
	printf("Enter grid size (1-9): ");
	scanf("%d", &N);

	if (N < 1 || N > 9)
	{
		printf("Invalid size.\n");
		return 1;
	}

	printf("Enter %dx%d grid values:\n", N, N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &grid[i][j]);
		}
	}

	print_views();

	return (0);
}
