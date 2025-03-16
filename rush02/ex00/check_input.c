/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:05:24 by tsilberm          #+#    #+#             */
/*   Updated: 2025/03/15 20:39:13 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	ft_putstr_error(char *str)
{
        while (*str)
                write(2, str++, 1); 
        write(2, "\n", 1);
	return (1);
}

int	is_positive_number(char *str)
{
	unsigned long long	nb;

	nb = ft_atoi(str);
        if (nb < 0)
		return (0);
	return (1);
}

int     check_input(int argc, char **argv)
{
        if (argc < 2) // Not enough arguments
                return (ft_putstr_error("Error"));
        if (argc > 3) // Too many arguments
                return (ft_putstr_error("Error"));
        if (argc == 2)
        {
                if (!is_positive_number(argv[1]))
                        return (ft_putstr_error("Error"));
        }
	else if (argc == 3)
	{
		if (!is_positive_number(argv[2]))
			return (ft_putstr_error("Error"));
	}
        return (0);
}
