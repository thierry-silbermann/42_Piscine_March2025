/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:07:56 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/06 17:49:28 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}
/*int	main()
{
	printf("3^-4 = 0 -> %d\n", ft_iterative_power(3, -4));
	printf("0^0 = 0 -> %d\n", ft_iterative_power(0, 0));
	printf("2^3 = 8 -> %d\n", ft_iterative_power(2, 3));
}*/
