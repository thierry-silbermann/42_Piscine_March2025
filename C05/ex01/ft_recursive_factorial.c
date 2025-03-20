/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:45:48 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/06 17:07:03 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	else
		return (nb * ft_recursive_factorial(nb - 1));
}
/*int	 main()
{
	printf("0 -> %d\n", ft_recursive_factorial(-1));
	printf("1 -> %d\n", ft_recursive_factorial(0));
	printf("1 -> %d\n", ft_recursive_factorial(1));
	printf("2 -> %d\n", ft_recursive_factorial(2));
	printf("6 -> %d\n", ft_recursive_factorial(3));
	printf("3628800 -> %d\n", ft_recursive_factorial(10));
}*/
