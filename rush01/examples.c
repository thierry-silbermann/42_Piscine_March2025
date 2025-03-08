
#include <stdlib.h>

int     **ft_allocate_mem_tab(int size);
int	*ft_allocate_mem_arr(int size);

int	**exampleN4(int **all_view, int *size)
{
	int	i, j;
	int 	N = 4;
	
	int grid[4][4] = {
		{1, 2, 3, 4},
		{2, 3, 4, 1},
		{3, 4, 1, 2},
		{4, 1, 2, 3}
	};

	// Allocate memory for 4 row pointers
	int **array = ft_allocate_mem_tab(N);
	// Copy values from the grid
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			array[i][j] = grid[i][j];
	*all_view = ft_allocate_mem_arr(N * 4);
	*size = N;
	return (array);
}
