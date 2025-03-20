/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:39:17 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/11 11:20:14 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

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

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb))
		return (nb);
	if (nb <= 2)
		return (2);
	if ((nb % 2) == 0)
		nb++;
	while (nb < (ft_recursive_power(2, 31)) - 1)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb += 2;
	}
	return (-1);
}
/*
int	main(void)
{
	printf("0 -> %d\n", ft_find_next_prime(0));
	printf("1 -> %d\n", ft_find_next_prime(1));
	printf("5 -> %d\n", ft_find_next_prime(5));
	printf("10 -> %d\n", ft_find_next_prime(10));
	printf("2147395500 -> %d\n", ft_find_next_prime(2147395500));
}*/
