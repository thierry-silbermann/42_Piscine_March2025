/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:52:37 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/16 20:34:21 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	compareBigNumbers(const char *num1, const char *num2)
{
	int	i;
	int	len1;
	int	len2;

	i = 0;
	len1 = str_len(num1);
	len2 = str_len(num2);
	if (len1 > len2)
		return 1;
	if (len1 < len2)
		return -1;
	while (i < len1)
	{
		if (num1[i] > num2[i]) return 1;
		if (num1[i] < num2[i]) return - 1;
		i++;
	}
	return (0);
}

dict_struct	*findFloorNumber(char *str, dict_struct *dict, int dictSize)
{
	dict_struct	*floor;
	int			i;

	floor = NULL;
	i = 0;
	while (i < dictSize)
	{
		if (compareBigNumbers(str, dict[i].number) >= 0)
		{
			if (!floor || compareBigNumbers(dict[i].number, floor->number) > 0)
			{
				floor = &dict[i];
			}
		}
		i++;
	}
	return (floor);
}

int	divideBigNumber(char *numStr, int divisor, int *remainder)
{
	int	quotient = 0;
	int	rem = 0;
	int	i;

	i = 0;
	rem = 0;
	quotient = 0;
	while (numStr[i] != '\0')
	{
		rem = rem * 10 + (numStr[i] - '0');
		if (quotient || rem / divisor)
		{
			quotient = quotient * 10 + (rem / divisor);
		}
        	rem %= divisor;
		i++;
	}
	*remainder = rem;
	return (quotient);
}
