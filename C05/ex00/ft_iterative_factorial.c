/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:57:22 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/06 17:07:25 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (nb >= 1)
	{
		result *= nb;
		nb--;
	}
	return (result);
}
/*int	main()
{
	printf("0 -> %d\n", ft_iterative_factorial(-1));
	printf("1 -> %d\n", ft_iterative_factorial(0));
	printf("1 -> %d\n", ft_iterative_factorial(1));
	printf("2 -> %d\n", ft_iterative_factorial(2));
        printf("6 -> %d\n", ft_iterative_factorial(3));
        printf("3628800 -> %d\n", ft_iterative_factorial(10));	
}*/
