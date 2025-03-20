/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:55:28 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/06 18:38:28 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (nb == 0 && power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
/*int   main()
{
        printf("3^-4 = 0 -> %d\n", ft_recursive_power(3, -4));
        printf("0^0 = 1 -> %d\n", ft_recursive_power(0, 0));
        printf("2^3 = 8 -> %d\n", ft_recursive_power(2, 3));
	printf("2^0 = 1 -> %d\n", ft_recursive_power(2, 0));
}*/
