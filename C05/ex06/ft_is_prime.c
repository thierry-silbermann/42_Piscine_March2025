/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:26:40 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/10 17:37:11 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 3;
	if (nb <= 1)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	while ((i * i) <= nb)
	{
		if ((nb % i) == 0)
			return (0);
		i += 2;
	}
	return (1);
}
/*
int	main(void)
{
	printf("2 -> %d\n", ft_is_prime(2));
	printf("5 -> %d\n", ft_is_prime(5));
	printf("10 -> %d\n", ft_is_prime(10));
	printf("17 -> %d\n", ft_is_prime(17));
	printf("49 -> %d\n", ft_is_prime(49));
}*/
