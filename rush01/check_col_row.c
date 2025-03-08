#include <stdio.h>

int	*ft_allocate_mem_arr(int size);
int     **ft_allocate_mem_tab(int size);
void	ft_free_arr(int *arr);
void    ft_free_tab(int **tab, int size);

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

void	print_views(int **grid, int *all_view, int N)
{
	/* 
		./rush-01 "col1up col2up col3up col4up 
			col1down col2down col3down col4down 
			row1left row2left row3left row4left 
			row1right row2right row3right row4right"
	*/
	int	top_views[N];
	int	bottom_views[N];
	int	left_views[N];
	int	right_views[N];
	//int	all_view[N*4];   // Condensed view of top/bottom/left/right

	// Compute top and bottom views for columns
	for (int j = 0; j < N; j++)
	{
		int column[N], reversed_column[N];
		for (int i = 0; i < N; i++)
		{
			column[i] = grid[i][j];            // Normal column
			reversed_column[i] = grid[N - i - 1][j];  // Reverse column
		}
		top_views[j] = count_visible(column, N);
		bottom_views[j] = count_visible(reversed_column, N);
		all_view[j] = count_visible(column, N);
		all_view[4 + j] = count_visible(reversed_column, N);
	}

	// Compute left and right views for rows
	for (int i = 0; i < N; i++) 
	{
		int reversed_row[N];
		for (int j = 0; j < N; j++)
		{
			reversed_row[j] = grid[i][N - j - 1];  // Reverse row
		}
		left_views[i] = count_visible(grid[i], N);
		right_views[i] = count_visible(reversed_row, N);
		all_view[8 + i] = count_visible(grid[i], N);
		all_view[12 + i] = count_visible(reversed_row, N);
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

void	display_all_view(int *all_view)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		printf("%d ", all_view[i]);
		i++;
	}
	printf("\n");
}

int main(void)
{
	int	**grid;
	int	N;
	int	*all_view;

	printf("Enter grid size (1-9): ");
	scanf("%d", &N);

	if (N < 1 || N > 9)
	{
		printf("Invalid size.\n");
		return 1;
	}
	all_view = ft_allocate_mem_arr(N * 4);
	grid = ft_allocate_mem_tab(N);
	printf("Enter %dx%d grid values:\n", N, N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &grid[i][j]);
		}
	}

	print_views(grid, all_view, N);
	printf("Solution: ");
	display_all_view(all_view);
	ft_free_tab(grid, N);
	ft_free_arr(all_view);

	return (0);
}
