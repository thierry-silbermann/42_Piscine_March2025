/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:55:58 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/09 14:07:12 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	*ft_allocate_mem_arr(int size);

/*
./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e
*/

int	get_n(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if ((str[i] - '0') > size)
			size = str[i] - '0';
		i++;
	}
	return (size);
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
		if (str[i] >= '1' && str[i] <= '9')
		{
			arr[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (arr);
}
/*
// This function will need to be removed
void	display_all_view(int *all_view, int N)
{
	int	i;

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
	int	size;

	if (argc != 2)
	{
		printf("Error\n");
		return (0);
	}
	printf("%d\n", argc);
	printf("%s\n", argv[1]);
	size = get_n(argv[1]);
	printf("N: %d\n", size);
	input = arr_input(argv[1], size);
	display_all_view(input, size);
	// Need to free input
}*/
