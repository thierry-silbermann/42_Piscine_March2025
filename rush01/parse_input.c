
#include <stdio.h>

int     *ft_allocate_mem_arr(int size);

/*
./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e
*/

int	get_N(char *str)
{
	int	i;
	int	N;

	i = 0;
	N = 0;
	while (str[i])
	{
		if ((str[i] - '0') > N)
			N = str[i] - '0';
		i++;
	}
	return (N);
}

int	*arr_input(char *str, int size)
{
	int	i;
	int	j;
	int	*arr;

	i = 0;
	j = 0;
	arr = ft_allocate_mem_arr(size * 4);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			arr[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (arr);
}

void    display_all_view(int *all_view, int N)
{
        int     i;

        i = 0;
        while (i < 4 * N)
        {
                printf("%d ", all_view[i]);
                i++;
        }
        printf("\n");
}


int	main(int argc, char *argv[])
{
	int	*input;
	int	N;

	printf("%d\n", argc);
	printf("%s\n", argv[1]);
	N = get_N(argv[1]);
	printf("N: %d\n", N);
	input = arr_input(argv[1], N);
	display_all_view(input, N);
}
