/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:17:21 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/15 20:32:18 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned long long int	ft_atoi(char *str)
{
	unsigned long long int	result;
	unsigned long long int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	if (sign < 0)
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
/*
int	main()
{
	char str[] = " ---+--+1234ab567";
	printf("-1 -> %d\n", ft_atoi(str));  // Expected: -1

	char str2[] = "\t 9886+";
	printf("9886 -> %d\n", ft_atoi(str2));  // Expected: 9886
}*/
