/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustoliv <gustoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:55:58 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/09 21:27:23 by gustoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
	while (str[i] != '\0' && i < 32 && j < 16)
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			arr[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	if (j == 16 && i == 31)
		return (arr);
	else
		return (0);
}
